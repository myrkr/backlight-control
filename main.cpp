#include <iostream>
#include <unistd.h>

#include "lux.h"

int main()
{
	LuxSensor sensor("/dev/i2c-1", 0x39);
	while (true) {
		try {
			auto value = sensor.read();
			std::cout << "Value: " << value << "\n";
		} catch (std::runtime_error const &e) {
			std::cerr << e.what() << "\n";
		}
		sleep(1);
	}

	return 0;
}
