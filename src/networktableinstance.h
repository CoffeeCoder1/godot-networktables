#ifndef NETWORKTABLEINSTANCE_H
#define NETWORKTABLEINSTANCE_H

#include "ntcore_c.h"
#include <godot_cpp/classes/node.hpp>
#include <networktables/NetworkTableInstance.h>

namespace godot {

class NetworkTableInstance : public Node {
	GDCLASS(NetworkTableInstance, Node)

private:
	nt::NetworkTableInstance instance;

	static void _print_log_output(const nt::Event event);

protected:
	static void _bind_methods();

public:
	NetworkTableInstance();
	~NetworkTableInstance();

	static NetworkTableInstance get_default();

	void _process(double delta) override;

	void start_client_4(String identity);
	void start_ds_client(unsigned int port);
	void set_server(String address, unsigned int port);
	void set_server_team(unsigned int team, unsigned int port);
};

} // namespace godot

#endif
