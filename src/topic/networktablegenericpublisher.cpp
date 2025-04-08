#include "networktablegenericpublisher.h"

using namespace godot;

void NetworkTableGenericPublisher::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_boolean", "value", "timestamp"), &NetworkTableGenericPublisher::set_boolean, DEFVAL(0));
	ClassDB::bind_method(D_METHOD("set_integer", "value", "timestamp"), &NetworkTableGenericPublisher::set_integer, DEFVAL(0));
	ClassDB::bind_method(D_METHOD("set_float", "value", "timestamp"), &NetworkTableGenericPublisher::set_float, DEFVAL(0));
	ClassDB::bind_method(D_METHOD("set_double", "value", "timestamp"), &NetworkTableGenericPublisher::set_double, DEFVAL(0));
	ClassDB::bind_method(D_METHOD("set_string", "value", "timestamp"), &NetworkTableGenericPublisher::set_string, DEFVAL(0));
	ClassDB::bind_method(D_METHOD("set_raw", "value", "timestamp"), &NetworkTableGenericPublisher::set_raw, DEFVAL(0));
	ClassDB::bind_method(D_METHOD("set_boolean_array", "value", "timestamp"), &NetworkTableGenericPublisher::set_boolean_array, DEFVAL(0));
	ClassDB::bind_method(D_METHOD("set_integer_array", "value", "timestamp"), &NetworkTableGenericPublisher::set_integer_array, DEFVAL(0));
	ClassDB::bind_method(D_METHOD("set_float_array", "value", "timestamp"), &NetworkTableGenericPublisher::set_float_array, DEFVAL(0));
	ClassDB::bind_method(D_METHOD("set_double_array", "value", "timestamp"), &NetworkTableGenericPublisher::set_double_array, DEFVAL(0));
	ClassDB::bind_method(D_METHOD("set_string_array", "value", "timestamp"), &NetworkTableGenericPublisher::set_string_array, DEFVAL(0));

	ClassDB::bind_method(D_METHOD("set_default_boolean", "default_value"), &NetworkTableGenericPublisher::set_default_boolean);
	ClassDB::bind_method(D_METHOD("set_default_integer", "default_value"), &NetworkTableGenericPublisher::set_default_integer);
	ClassDB::bind_method(D_METHOD("set_default_float", "default_value"), &NetworkTableGenericPublisher::set_default_float);
	ClassDB::bind_method(D_METHOD("set_default_double", "default_value"), &NetworkTableGenericPublisher::set_default_double);
	ClassDB::bind_method(D_METHOD("set_default_string", "default_value"), &NetworkTableGenericPublisher::set_default_string);
	ClassDB::bind_method(D_METHOD("set_default_raw", "default_value"), &NetworkTableGenericPublisher::set_default_raw);
	ClassDB::bind_method(D_METHOD("set_default_boolean_array", "default_value"), &NetworkTableGenericPublisher::set_default_boolean_array);
	ClassDB::bind_method(D_METHOD("set_default_integer_array", "default_value"), &NetworkTableGenericPublisher::set_default_integer_array);
	ClassDB::bind_method(D_METHOD("set_default_float_array", "default_value"), &NetworkTableGenericPublisher::set_default_float_array);
	ClassDB::bind_method(D_METHOD("set_default_double_array", "default_value"), &NetworkTableGenericPublisher::set_default_double_array);
	ClassDB::bind_method(D_METHOD("set_default_string_array", "default_value"), &NetworkTableGenericPublisher::set_default_string_array);
}
