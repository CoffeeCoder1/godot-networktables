#ifndef NETWORKTABLETOPIC_H
#define NETWORKTABLETOPIC_H

#include "godot_cpp/classes/ref_counted.hpp"
#include "networktablegenericsubscriber.h"
#include "networktables/Topic.h"

namespace godot {

class NetworkTableTopic : public RefCounted {
	GDCLASS(NetworkTableTopic, RefCounted)

private:
	nt::Topic topic;

protected:
	static void _bind_methods();

public:
	NetworkTableTopic() = default;
	~NetworkTableTopic() = default;

	/**
	 * Determines if the topic is currently being published.
	 *
	 * @return True if the topic exists, false otherwise.
	 */
	bool exists() const {
		return topic.Exists();
	}

	void set_topic(nt::Topic);
	Ref<NetworkTableGenericSubscriber> generic_subscribe();
};

} // namespace godot

#endif
