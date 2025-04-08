#include "networktabletopic.h"
#include "godot_cpp/classes/ref.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "networktablegenericpublisher.h"
#include "networktablegenericsubscriber.h"

using namespace godot;

void NetworkTableTopic::_bind_methods() {
	ClassDB::bind_method(D_METHOD("exists"), &NetworkTableTopic::exists);
	ClassDB::bind_method(D_METHOD("generic_subscribe"), &NetworkTableTopic::generic_subscribe);
	ClassDB::bind_method(D_METHOD("generic_publish", "type_string"), &NetworkTableTopic::generic_publish);
	ClassDB::bind_method(D_METHOD("set_type"), &NetworkTableTopic::set_type);
	ClassDB::bind_method(D_METHOD("get_type"), &NetworkTableTopic::get_type);

	ADD_PROPERTY(PropertyInfo(Variant::INT, "type", PropertyHint::PROPERTY_HINT_ENUM, "type1, type2, type3"), "set_type", "get_type");

	BIND_ENUM_CONSTANT(UNASSIGNED);
	BIND_ENUM_CONSTANT(BOOLEAN);
	BIND_ENUM_CONSTANT(DOUBLE);
	BIND_ENUM_CONSTANT(STRING);
	BIND_ENUM_CONSTANT(RAW);
	BIND_ENUM_CONSTANT(BOOLEAN_ARRAY);
	BIND_ENUM_CONSTANT(DOUBLE_ARRAY);
	BIND_ENUM_CONSTANT(STRING_ARRAY);
	BIND_ENUM_CONSTANT(RPC);
	BIND_ENUM_CONSTANT(INTEGER);
	BIND_ENUM_CONSTANT(FLOAT);
	BIND_ENUM_CONSTANT(INTEGER_ARRAY);
	BIND_ENUM_CONSTANT(FLOAT_ARRAY);
}

void NetworkTableTopic::set_topic(nt::Topic topic) {
	this->topic = topic;
}

void NetworkTableTopic::set_type(NetworkTableType type) {
	this->type = type;
}

NetworkTableTopic::NetworkTableType NetworkTableTopic::get_type() {
	return type;
}

NT_Type NetworkTableTopic::get_type_native() {
	switch (get_type()) {
		case BOOLEAN:
			return NT_Type::NT_BOOLEAN;
		case DOUBLE:
			return NT_Type::NT_DOUBLE;
		case STRING:
			return NT_Type::NT_STRING;
		case RAW:
			return NT_Type::NT_RAW;
		case BOOLEAN_ARRAY:
			return NT_Type::NT_BOOLEAN_ARRAY;
		case DOUBLE_ARRAY:
			return NT_Type::NT_DOUBLE_ARRAY;
		case STRING_ARRAY:
			return NT_Type::NT_STRING_ARRAY;
		case RPC:
			return NT_Type::NT_RPC;
		case INTEGER:
			return NT_Type::NT_INTEGER;
		case FLOAT:
			return NT_Type::NT_FLOAT;
		case INTEGER_ARRAY:
			return NT_Type::NT_INTEGER_ARRAY;
		case FLOAT_ARRAY:
			return NT_Type::NT_FLOAT_ARRAY;
		default:
			return NT_Type::NT_UNASSIGNED;
	}
}

Ref<NetworkTableGenericSubscriber> NetworkTableTopic::generic_subscribe() {
	Ref<NetworkTableGenericSubscriber> subscriber;
	subscriber.instantiate();
	subscriber->set_topic(this);
	return subscriber;
}

Ref<NetworkTableGenericPublisher> NetworkTableTopic::generic_publish(String type_string) {
	Ref<NetworkTableGenericPublisher> publisher;
	publisher.instantiate();
	publisher->set_topic(this, type_string);
	return publisher;
}
