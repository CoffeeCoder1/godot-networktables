#include "networktablegenericsubscriber.h"

using namespace godot;

void NetworkTableGenericSubscriber::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_boolean", "default"), &NetworkTableGenericSubscriber::get_boolean);
	ClassDB::bind_method(D_METHOD("get_integer", "default"), &NetworkTableGenericSubscriber::get_integer);
	ClassDB::bind_method(D_METHOD("get_float", "default"), &NetworkTableGenericSubscriber::get_float);
	ClassDB::bind_method(D_METHOD("get_double", "default"), &NetworkTableGenericSubscriber::get_double);
	ClassDB::bind_method(D_METHOD("get_string", "default"), &NetworkTableGenericSubscriber::get_string);
	ClassDB::bind_method(D_METHOD("get_raw", "default"), &NetworkTableGenericSubscriber::get_raw);
	ClassDB::bind_method(D_METHOD("get_boolean_array", "default"), &NetworkTableGenericSubscriber::get_boolean_array);
	ClassDB::bind_method(D_METHOD("get_integer_array", "default"), &NetworkTableGenericSubscriber::get_integer_array);
	ClassDB::bind_method(D_METHOD("get_float_array", "default"), &NetworkTableGenericSubscriber::get_float_array);
	ClassDB::bind_method(D_METHOD("get_double_array", "default"), &NetworkTableGenericSubscriber::get_double_array);
	ClassDB::bind_method(D_METHOD("get_string_array", "default"), &NetworkTableGenericSubscriber::get_string_array);
}
