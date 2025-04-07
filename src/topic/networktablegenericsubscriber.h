#ifndef NETWORKTABLEGENERICSUBSCRIBER_H
#define NETWORKTABLEGENERICSUBSCRIBER_H

#include "godot_cpp/classes/ref_counted.hpp"
#include "networktables/Topic.h"
#include "networktablesubscriber.h"

namespace godot {

class NetworkTableGenericSubscriber : public NetworkTableSubscriber {
	GDCLASS(NetworkTableGenericSubscriber, NetworkTableSubscriber)

protected:
	static void _bind_methods();

public:
	NetworkTableGenericSubscriber() = default;
	~NetworkTableGenericSubscriber() = default;

	/**
	 * Gets the entry's value as a boolean. If the entry does not exist or is of different type, it
	 * will return the default value.
	 *
	 * @param default_value The value to be returned if no value is found
	 * @return The entry's value or the given default value
	 */
	bool get_boolean(bool default_value) const {
		return ::nt::GetBoolean(sub_handle, default_value);
	}

	/**
	 * Gets the entry's value as a integer. If the entry does not exist or is of different type, it
	 * will return the default value.
	 *
	 * @param default_value The value to be returned if no value is found
	 * @return The entry's value or the given default value
	 */
	int64_t get_integer(int64_t default_value) const {
		return ::nt::GetInteger(sub_handle, default_value);
	}

	/**
	 * Gets the entry's value as a float. If the entry does not exist or is of different type, it
	 * will return the default value.
	 *
	 * @param default_value The value to be returned if no value is found
	 * @return The entry's value or the given default value
	 */
	float get_float(float default_value) const {
		return ::nt::GetFloat(sub_handle, default_value);
	}

	/**
	 * Gets the entry's value as a double. If the entry does not exist or is of different type, it
	 * will return the default value.
	 *
	 * @param default_value The value to be returned if no value is found
	 * @return The entry's value or the given default value
	 */
	double get_double(double default_value) const {
		return ::nt::GetDouble(sub_handle, default_value);
	}

	/**
	 * Gets the entry's value as a string. If the entry does not exist or is of different type, it
	 * will return the default value.
	 *
	 * @param default_value The value to be returned if no value is found
	 * @return The entry's value or the given default value
	 */
	String get_string(String default_value) const {
		return String(::nt::GetString(sub_handle, default_value.utf8().get_data()).c_str());
	}

	/**
	 * Gets the entry's value as a raw. If the entry does not exist or is of different type, it
	 * will return the default value.
	 *
	 * @param default_value The value to be returned if no value is found
	 * @return The entry's value or the given default value
	 */
	PackedByteArray get_raw(PackedByteArray default_value) const {
		std::vector<uint8_t> default_data;
		for (uint8_t value : default_value) {
			default_data.push_back(value);
		}

		PackedByteArray data = PackedByteArray();
		for (uint8_t value : ::nt::GetRaw(sub_handle, default_data)) {
			data.append(value);
		}
		return data;
	}

	/**
	 * Gets the entry's value as a boolean array. If the entry does not exist
	 * or is of different type, it will return the default value.
	 *
	 * @param defaultValue the value to be returned if no value is found
	 * @return the entry's value or the given default value
	 *
	 * @note This makes a copy of the array.  If the overhead of this is a
	 *       concern, use GetValue() instead.
	 *
	 * @note The returned array is std::vector<int> instead of std::vector<bool>
	 *       because std::vector<bool> is special-cased in C++.  0 is false, any
	 *       non-zero value is true.
	 */
	PackedByteArray get_boolean_array(PackedByteArray default_value) const {
		std::vector<int> default_data;
		for (uint8_t value : default_value) {
			default_data.push_back(value);
		}

		PackedByteArray data = PackedByteArray();
		for (uint8_t value : ::nt::GetBooleanArray(sub_handle, std::span<const int>(default_data))) {
			data.append(value);
		}
		return data;
	}

	/**
	 * Gets the entry's value as a integer array. If the entry does not exist
	 * or is of different type, it will return the default value.
	 *
	 * @param defaultValue the value to be returned if no value is found
	 * @return the entry's value or the given default value
	 *
	 * @note This makes a copy of the array.  If the overhead of this is a
	 *       concern, use GetValue() instead.
	 */
	PackedInt64Array get_integer_array(PackedInt64Array default_value) const {
		std::vector<int64_t> default_data;
		for (int64_t value : default_value) {
			default_data.push_back(value);
		}

		PackedInt64Array data = PackedInt64Array();
		for (int64_t value : ::nt::GetIntegerArray(sub_handle, std::span<const int64_t>(default_data))) {
			data.append(value);
		}
		return data;
	}

	/**
	 * Gets the entry's value as a float array. If the entry does not exist
	 * or is of different type, it will return the default value.
	 *
	 * @param defaultValue the value to be returned if no value is found
	 * @return the entry's value or the given default value
	 *
	 * @note This makes a copy of the array.  If the overhead of this is a
	 *       concern, use GetValue() instead.
	 */
	PackedFloat32Array get_float_array(PackedFloat32Array default_value) const {
		std::vector<float> default_data;
		for (float value : default_value) {
			default_data.push_back(value);
		}

		PackedFloat32Array data = PackedFloat32Array();
		for (float value : ::nt::GetFloatArray(sub_handle, std::span<const float>(default_data))) {
			data.append(value);
		}
		return data;
	}

	/**
	 * Gets the entry's value as a double array. If the entry does not exist
	 * or is of different type, it will return the default value.
	 *
	 * @param defaultValue the value to be returned if no value is found
	 * @return the entry's value or the given default value
	 *
	 * @note This makes a copy of the array.  If the overhead of this is a
	 *       concern, use GetValue() instead.
	 */
	PackedFloat64Array get_double_array(PackedFloat64Array default_value) const {
		std::vector<double> default_data;
		for (double value : default_value) {
			default_data.push_back(value);
		}

		PackedFloat64Array data = PackedFloat64Array();
		for (double value : ::nt::GetDoubleArray(sub_handle, std::span<const double>(default_data))) {
			data.append(value);
		}
		return data;
	}

	/**
	 * Gets the entry's value as a string array. If the entry does not exist
	 * or is of different type, it will return the default value.
	 *
	 * @param defaultValue the value to be returned if no value is found
	 * @return the entry's value or the given default value
	 *
	 * @note This makes a copy of the array.  If the overhead of this is a
	 *       concern, use GetValue() instead.
	 */
	PackedStringArray get_string_array(PackedStringArray default_value) const {
		std::vector<std::string> default_data;
		for (String value : default_value) {
			default_data.push_back(value.utf8().get_data());
		}

		PackedStringArray data = PackedStringArray();
		for (std::string value : ::nt::GetStringArray(sub_handle, std::span<const std::string>(default_data))) {
			data.append(value.c_str());
		}
		return data;
	}
};

} // namespace godot

#endif
