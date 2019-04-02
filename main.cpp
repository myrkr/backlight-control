#include <iostream>
#include <unistd.h>

#include "lux.h"
#include "backlight.h"

int main()
{
	LuxSensor sensor("/dev/i2c-1", 0x39);
	Backlight backlight;
	while (true) {
		try {
			auto value = sensor.read();
			if (isatty(1)) {
				std::cout << "Value: " << value << "\n";
			}

			/* 11 is the minimum value where the backlight
			 * is active */
			if (value < 50) {
				backlight.set(11 + value);
			} else if (value < 100) {
				backlight.set(150);
			} else {
				backlight.set(200);
			}
			
		} catch (std::runtime_error const &e) {
			std::cerr << e.what() << "\n";
		}
		sleep(1);
	}

	return 0;
}
