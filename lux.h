#pragma once

#include <string>
#include <cstdint>
#include <stdexcept>

class LuxSensor
{
public:
	using Value = uint32_t;
	using ValueOutOfRange = std::runtime_error;
	using OpenError = std::runtime_error;
	
	LuxSensor(std::string const &,
		  int);
	~LuxSensor();

	Value read() const;
private:
	void *handle_;
};
