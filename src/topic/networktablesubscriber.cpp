#include "networktablesubscriber.h"

using namespace godot;

void NetworkTableSubscriber::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_last_change"), &NetworkTableSubscriber::get_last_change);
}

void NetworkTableSubscriber::set_topic(NetworkTableTopic *topic) {
	this->topic = topic;
	this->sub_handle = ::nt::Subscribe(topic->get_handle(), topic->get_type_native(), topic->get_type_string());
}
