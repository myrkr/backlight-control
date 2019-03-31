#include "lux.h"

#include <limits>
#include "tsl2561.h"

LuxSensor::LuxSensor(std::string const &bus,
		     int address)
{
	handle_ = tsl2561_init(address, bus.c_str());
	if (! handle_) {
		throw OpenError("Failed to open connection to device");
	}

	tsl2561_set_gain(handle_, TSL2561_GAIN_0X);
	tsl2561_set_integration_time(handle_, TSL2561_INTEGRATION_TIME_402MS);
}

LuxSensor::~LuxSensor()
{
	tsl2561_close(handle_);
}

auto LuxSensor::read() const -> Value
{
	long result = tsl2561_lux(handle_);
	using check = std::numeric_limits<Value>;
	if (result < 0 || static_cast<unsigned long>(result) > check::max()) {
		throw ValueOutOfRange("result not within range");
	}
	return static_cast<Value>(result);
}

