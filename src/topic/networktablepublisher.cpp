#include "networktablepublisher.h"

using namespace godot;

void NetworkTablePublisher::_bind_methods() {
}

void NetworkTablePublisher::set_topic(NetworkTableTopic *topic, String type_string) {
	this->topic = topic;
	this->pub_handle = ::nt::Publish(topic->get_handle(), topic->get_type_native(), type_string.utf8().get_data());
}
