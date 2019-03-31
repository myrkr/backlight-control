#include "backlight.h"

#include <fcntl.h>
#include <sstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

Backlight::Backlight()
{
	fd_ = open("/sys/class/backlight/rpi_backlight/brightness", O_WRONLY);
	if (fd_ < 0) {
		throw OpenError("Failed to open brightness file for writing");
	}
}

Backlight::~Backlight()
{
	close(fd_);
}

void Backlight::set(Value value)
{
	std::ostringstream str;
	str << (int)value;
	std::string to_write(str.str());
	size_t length = to_write.size();
	ssize_t result = write(fd_, to_write.data(), length);
	if (result < 0 || static_cast<size_t>(result) != length) {
		throw SetError("Failed to write data");
	}
}
