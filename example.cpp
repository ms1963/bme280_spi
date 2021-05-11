
#include "pico/stdlib.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bme280_spi.hpp"


int main() {
    stdio_init_all();
    sleep_ms(3000); // required for some OSses to make Pico visible

    // using default SPI pins
    // frequency = 0.5 MHz
    // FORCED_MODE to reduce energy consumption
    BME280 myBME280(0, 
            PICO_DEFAULT_SPI_RX_PIN, 
            PICO_DEFAULT_SPI_TX_PIN, 
            PICO_DEFAULT_SPI_SCK_PIN, 
            PICO_DEFAULT_SPI_CSN_PIN, 
            500 * 1000,
            BME280::MODE::MODE_FORCED);
    BME280::Measurement_t values;

    // empty read as a warm-up
    myBME280.measure();
    sleep_ms(100);

    while (true) {
        // get measurement from BME280
        values = myBME280.measure();
        // create formatted strings with measurement results
        printf("temperature: %6.1f C\n",   values.temperature);
        printf("humidity   : %6.1f %c\n",  values.humidity, '%');
        printf("pressure   : %6.1f hPa\n", values.pressure);
        printf("altitude   : %6.1f m\n",   values.altitude);
        printf("\n\n");
        sleep_ms(2000);
    }   
}
