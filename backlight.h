#pragma once

#include <cstdint>
#include <stdexcept>

class Backlight
{
public:
	using Value = uint8_t;
	using OpenError = std::runtime_error;
	using SetError = std::runtime_error;
	
	Backlight();
	~Backlight();

	void set(Value);
private:
	int fd_;
};
