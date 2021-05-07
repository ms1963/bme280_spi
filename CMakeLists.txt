cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)
project(example)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()


add_executable(
  example
  example.cpp
  bme280_spi.cpp
)

pico_enable_stdio_uart(example 0)
pico_enable_stdio_usb(example 1)

pico_add_extra_outputs(example)
target_link_libraries(example pico_stdlib pico_runtime  hardware_spi)
