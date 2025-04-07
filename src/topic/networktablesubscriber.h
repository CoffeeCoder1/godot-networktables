#ifndef NETWORKTABLESUBSCRIBER_H
#define NETWORKTABLESUBSCRIBER_H

#include "godot_cpp/classes/ref_counted.hpp"
#include "networktables/Topic.h"

namespace godot {

class NetworkTableSubscriber : public RefCounted {
	GDCLASS(NetworkTableSubscriber, RefCounted)

private:
	nt::Topic topic;

protected:
	static void _bind_methods();

	NT_Subscriber sub_handle{ 0 };

public:
	NetworkTableSubscriber() = default;
	~NetworkTableSubscriber() = default;

	void set_topic(nt::Topic);

	/**
	 * Gets the last time the value was changed.
	 * Note: this is not atomic with Get(); use GetAtomic() to get both the value and last change
	 * as an atomic operation.
	 *
	 * @return Topic last change time
	 */
	int64_t get_last_change() const {
		return ::nt::GetEntryLastChange(sub_handle);
	}
};

} // namespace godot

#endif
