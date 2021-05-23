# bme280_spi
C++ Version of BME280 Library using SPI for Raspberry Pi Pico

This code is based upon the C-library provided by the Raspberry Pi Foundation.
The library comprises the files bme280_spi.hpp and bme280_spi.cpp

Using this library is very simple. An example is implemented by example.cpp.

Copy the files to your system.

Call 
  
  cmake .
 
and then

  make
  
within the installation folder.

The constructor of BME280 expects a parameter called mode. 
It is of type:

enum MODE {     MODE_SLEEP = 0b00,
                MODE_FORCED = 0b01,
                MODE_NORMAL = 0b11   };
                
MODE_FORCED implies that  the sensor will consume very low  power between measurements. 
It only will wake up when BME280::measure() is called. Thus, use this mode for low
power applications.
