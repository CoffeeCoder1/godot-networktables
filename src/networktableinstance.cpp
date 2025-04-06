#include "networktableinstance.h"

#include "godot_cpp/variant/utility_functions.hpp"
#include "networktables/NetworkTableInstance.h"
#include "ntcore_c.h"
#include "ntcore_cpp.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void NetworkTableInstance::_bind_methods() {
	ClassDB::bind_method(D_METHOD("start_client_4", "identity"), &NetworkTableInstance::start_client_4);
	ClassDB::bind_method(D_METHOD("start_ds_client", "port"), &NetworkTableInstance::start_ds_client, DEFVAL(0));
	ClassDB::bind_method(D_METHOD("set_server", "address", "port"), &NetworkTableInstance::set_server, DEFVAL(0));
	ClassDB::bind_method(D_METHOD("set_server_team", "team", "port"), &NetworkTableInstance::set_server_team, DEFVAL(0));
}

NetworkTableInstance::NetworkTableInstance() {
	// Initialize any variables here.
	instance = nt::NetworkTableInstance::GetDefault();
	instance.AddLogger(NT_LOG_INFO, NT_LOG_CRITICAL, NetworkTableInstance::_print_log_output);
}

NetworkTableInstance::~NetworkTableInstance() {
	// Add your cleanup here.
}

void NetworkTableInstance::_process(double delta) {}

void NetworkTableInstance::_print_log_output(const nt::Event event) {
	UtilityFunctions::print(event.GetLogMessage()->message.c_str());
}

void NetworkTableInstance::start_client_4(String identity) {
	instance.StartClient4(identity.utf8().get_data());
}

void NetworkTableInstance::start_ds_client(unsigned int port) {
	instance.StartDSClient(port);
}

void NetworkTableInstance::set_server(String address, unsigned int port) {
	instance.SetServer(address.utf8().get_data(), port);
}

void NetworkTableInstance::set_server_team(unsigned int team, unsigned int port) {
	instance.SetServerTeam(team, port);
}

