#ifndef NETWORKTABLETOPIC_H
#define NETWORKTABLETOPIC_H

#include "godot_cpp/classes/ref_counted.hpp"
#include "networktables/Topic.h"

namespace godot {

class NetworkTableGenericPublisher;
class NetworkTableGenericSubscriber;

class NetworkTableTopic : public RefCounted {
	GDCLASS(NetworkTableTopic, RefCounted)

public:
	enum NetworkTableType {
		UNASSIGNED,
		BOOLEAN,
		DOUBLE,
		STRING,
		RAW,
		BOOLEAN_ARRAY,
		DOUBLE_ARRAY,
		STRING_ARRAY,
		RPC,
		INTEGER,
		FLOAT,
		INTEGER_ARRAY,
		FLOAT_ARRAY,
	};

private:
	nt::Topic topic;

protected:
	static void _bind_methods();

	NetworkTableType type;

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
	NT_Topic get_handle() {
		return topic.GetHandle();
	}
	std::string get_type_string() {
		return topic.GetTypeString();
	}

	void set_topic(nt::Topic topic);
	void set_type(NetworkTableType type);
	NetworkTableType get_type();
	NT_Type get_type_native();
	Ref<NetworkTableGenericSubscriber> generic_subscribe();
	Ref<NetworkTableGenericPublisher> generic_publish(String type_string);
};

} // namespace godot

VARIANT_ENUM_CAST(NetworkTableTopic::NetworkTableType);

#endif
