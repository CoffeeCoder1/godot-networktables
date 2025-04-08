#ifndef NETWORKTABLEPUBLISHER_H
#define NETWORKTABLEPUBLISHER_H

#include "godot_cpp/classes/ref_counted.hpp"
#include "networktabletopic.h"

namespace godot {

class NetworkTablePublisher : public RefCounted {
	GDCLASS(NetworkTablePublisher, RefCounted)

private:
	NetworkTableTopic *topic;

protected:
	static void _bind_methods();

	NT_Publisher pub_handle{ 0 };

public:
	NetworkTablePublisher() = default;
	~NetworkTablePublisher() = default;

	void set_topic(NetworkTableTopic *topic, String type_string);
};

} // namespace godot

#endif
