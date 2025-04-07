#include "networktabletopic.h"
#include "godot_cpp/classes/ref.hpp"
#include "networktablegenericsubscriber.h"

using namespace godot;

void NetworkTableTopic::_bind_methods() {
	ClassDB::bind_method(D_METHOD("exists"), &NetworkTableTopic::exists);
	ClassDB::bind_method(D_METHOD("generic_subscribe"), &NetworkTableTopic::generic_subscribe);
}

void NetworkTableTopic::set_topic(nt::Topic topic) {
	this->topic = topic;
}

Ref<NetworkTableGenericSubscriber> NetworkTableTopic::generic_subscribe() {
	Ref<NetworkTableGenericSubscriber> subscriber;
	subscriber.instantiate();
	subscriber->set_topic(topic);
	return subscriber;
}
