#ifndef NETWORKTABLEENTRY_H
#define NETWORKTABLEENTRY_H

#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class NetworkTableEntry : public RefCounted {
	GDCLASS(NetworkTableEntry, RefCounted)

protected:
	static void _bind_methods();

public:
	NetworkTableEntry();
	~NetworkTableEntry();
};

} // namespace godot

#endif
