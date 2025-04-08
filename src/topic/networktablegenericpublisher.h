#ifndef NETWORKTABLEGENERICPUBLISHER_H
#define NETWORKTABLEGENERICPUBLISHER_H

#include "godot_cpp/classes/ref_counted.hpp"
#include "networktablepublisher.h"
#include "networktables/Topic.h"
#include <span>

namespace godot {

class NetworkTableGenericPublisher : public NetworkTablePublisher {
	GDCLASS(NetworkTableGenericPublisher, NetworkTablePublisher)

protected:
	static void _bind_methods();

public:
	NetworkTableGenericPublisher() = default;
	~NetworkTableGenericPublisher() = default;

	/**
	 * Sets the entry's value.
	 *
	 * @param value the value to set
	 * @param time the timestamp to set (0 = nt::Now())
	 * @return False if the entry exists with a different type
	 */
	bool set_boolean(bool value, int64_t time = 0) {
		return nt::SetBoolean(pub_handle, value, time);
	}

	/**
	 * Sets the entry's value.
	 *
	 * @param value the value to set
	 * @param time the timestamp to set (0 = nt::Now())
	 * @return False if the entry exists with a different type
	 */
	bool set_integer(int64_t value, int64_t time = 0) {
		return nt::SetInteger(pub_handle, value, time);
	}

	/**
	 * Sets the entry's value.
	 *
	 * @param value the value to set
	 * @param time the timestamp to set (0 = nt::Now())
	 * @return False if the entry exists with a different type
	 */
	bool set_float(float value, int64_t time = 0) {
		return nt::SetFloat(pub_handle, value, time);
	}

	/**
	 * Sets the entry's value.
	 *
	 * @param value the value to set
	 * @param time the timestamp to set (0 = nt::Now())
	 * @return False if the entry exists with a different type
	 */
	bool set_double(double value, int64_t time = 0) {
		return nt::SetDouble(pub_handle, value, time);
	}

	/**
	 * Sets the entry's value.
	 *
	 * @param value the value to set
	 * @param time the timestamp to set (0 = nt::Now())
	 * @return False if the entry exists with a different type
	 */
	bool set_string(String value, int64_t time = 0) {
		return nt::SetString(pub_handle, value.utf8().get_data(), time);
	}

	/**
	 * Sets the entry's value.
	 *
	 * @param values the value to set
	 * @param time the timestamp to set (0 = nt::Now())
	 * @return False if the entry exists with a different type
	 */
	bool set_raw(PackedByteArray values, int64_t time = 0) {
		std::vector<uint8_t> data;
		for (uint8_t value : values) {
			data.push_back(value);
		}
		return nt::SetRaw(pub_handle, data, time);
	}

	/**
	 * Sets the entry's value.
	 *
	 * @param values the value to set
	 * @param time the timestamp to set (0 = nt::Now())
	 * @return False if the entry exists with a different type
	 */
	bool set_boolean_array(PackedByteArray values, int64_t time = 0) {
		std::vector<int> data;
		for (int value : values) {
			data.push_back(value);
		}
		return nt::SetEntryValue(pub_handle, nt::Value::MakeBooleanArray(data, time));
	}

	/**
	 * Sets the entry's value.
	 *
	 * @param values the value to set
	 * @param time the timestamp to set (0 = nt::Now())
	 * @return False if the entry exists with a different type
	 */
	bool set_integer_array(PackedInt64Array values, int64_t time = 0) {
		std::vector<int64_t> data;
		for (int64_t value : values) {
			data.push_back(value);
		}
		return nt::SetIntegerArray(pub_handle, data, time);
	}

	/**
	 * Sets the entry's value.
	 *
	 * @param values the value to set
	 * @param time the timestamp to set (0 = nt::Now())
	 * @return False if the entry exists with a different type
	 */
	bool set_float_array(PackedFloat32Array values, int64_t time = 0) {
		std::vector<float> data;
		for (float value : values) {
			data.push_back(value);
		}
		return nt::SetFloatArray(pub_handle, data, time);
	}

	/**
	 * Sets the entry's value.
	 *
	 * @param values the value to set
	 * @param time the timestamp to set (0 = nt::Now())
	 * @return False if the entry exists with a different type
	 */
	bool set_double_array(PackedFloat64Array values, int64_t time = 0) {
		std::vector<double> data;
		for (double value : values) {
			data.push_back(value);
		}
		return nt::SetDoubleArray(pub_handle, data, time);
	}

	/**
	 * Sets the entry's value.
	 *
	 * @param values the value to set
	 * @param time the timestamp to set (0 = nt::Now())
	 * @return False if the entry exists with a different type
	 */
	bool set_string_array(PackedStringArray values, int64_t time = 0) {
		std::vector<std::string> data;
		for (String value : values) {
			data.push_back(value.utf8().get_data());
		}
		return nt::SetStringArray(pub_handle, data, time);
	}

	/**
	 * Sets the entry's value if it does not exist.
	 *
	 * @param default_value the default value to set
	 * @return True if the entry did not already have a value, otherwise False
	 */
	bool set_default_boolean(bool default_value) {
		return nt::SetDefaultBoolean(pub_handle, default_value);
	}

	/**
	 * Sets the entry's value if it does not exist.
	 *
	 * @param default_value the default value to set
	 * @return True if the entry did not already have a value, otherwise False
	 */
	bool set_default_integer(int64_t default_value) {
		return nt::SetDefaultInteger(pub_handle, default_value);
	}

	/**
	 * Sets the entry's value if it does not exist.
	 *
	 * @param default_value the default value to set
	 * @return True if the entry did not already have a value, otherwise False
	 */
	bool set_default_float(float default_value) {
		return nt::SetDefaultFloat(pub_handle, default_value);
	}

	/**
	 * Sets the entry's value if it does not exist.
	 *
	 * @param default_value the default value to set
	 * @return True if the entry did not already have a value, otherwise False
	 */
	bool set_default_double(double default_value) {
		return nt::SetDefaultDouble(pub_handle, default_value);
	}

	/**
	 * Sets the entry's value if it does not exist.
	 *
	 * @param default_value the default value to set
	 * @return True if the entry did not already have a value, otherwise False
	 */
	bool set_default_string(String default_value) {
		return nt::SetDefaultString(pub_handle, default_value.utf8().get_data());
	}

	/**
	 * Sets the entry's value if it does not exist.
	 *
	 * @param default_value the default value to set
	 * @return True if the entry did not already have a value, otherwise False
	 */
	bool set_default_raw(PackedByteArray default_value) {
		std::vector<uint8_t> data;
		for (uint8_t value : default_value) {
			data.push_back(value);
		}
		return nt::SetDefaultRaw(pub_handle, data);
	}

	/**
	 * Sets the entry's value if it does not exist.
	 *
	 * @param default_value the default value to set
	 * @return True if the entry did not already have a value, otherwise False
	 */
	bool set_default_boolean_array(PackedByteArray default_value) {
		std::vector<int> data;
		for (int value : default_value) {
			data.push_back(value);
		}
		return nt::SetDefaultBooleanArray(pub_handle, data);
	}

	/**
	 * Sets the entry's value if it does not exist.
	 *
	 * @param default_value the default value to set
	 * @return True if the entry did not already have a value, otherwise False
	 */
	bool set_default_integer_array(PackedInt64Array default_value) {
		std::vector<int64_t> data;
		for (int64_t value : default_value) {
			data.push_back(value);
		}
		return nt::SetDefaultIntegerArray(pub_handle, data);
	}

	/**
	 * Sets the entry's value if it does not exist.
	 *
	 * @param default_value the default value to set
	 * @return True if the entry did not already have a value, otherwise False
	 */
	bool set_default_float_array(PackedFloat32Array default_value) {
		std::vector<float> data;
		for (float value : default_value) {
			data.push_back(value);
		}
		return nt::SetDefaultFloatArray(pub_handle, data);
	}

	/**
	 * Sets the entry's value if it does not exist.
	 *
	 * @param default_value the default value to set
	 * @return True if the entry did not already have a value, otherwise False
	 */
	bool set_default_double_array(PackedFloat64Array default_value) {
		std::vector<double> data;
		for (double value : default_value) {
			data.push_back(value);
		}
		return nt::SetDefaultDoubleArray(pub_handle, data);
	}

	/**
	 * Sets the entry's value if it does not exist.
	 *
	 * @param default_value the default value to set
	 * @return True if the entry did not already have a value, otherwise False
	 */
	bool set_default_string_array(PackedStringArray default_value) {
		std::vector<std::string> data;
		for (String value : default_value) {
			data.push_back(value.utf8().get_data());
		}
		return nt::SetDefaultStringArray(pub_handle, data);
	}
};

} // namespace godot

#endif
