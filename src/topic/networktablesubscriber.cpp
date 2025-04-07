#include "networktablesubscriber.h"
#include "godot_cpp/classes/ref.hpp"

using namespace godot;

void NetworkTableSubscriber::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_last_change"), &NetworkTableSubscriber::get_last_change);
}

void NetworkTableSubscriber::set_topic(nt::Topic topic) {
	this->topic = topic;
	this->sub_handle = ::nt::Subscribe(topic.GetHandle(), NT_UNASSIGNED, "");
}
