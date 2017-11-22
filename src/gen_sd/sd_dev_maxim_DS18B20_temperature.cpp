/*******************************
 *
 * File: sd_dev_apogee_BM180_temperature.cpp
 *
 * This module is a driver for the pressure and
 * temperature sensor.
 *
 * Product Page: https://www.adafruit.com/product/1603
 * Datasheet: https://cdn-shop.adafruit.com/datasheets/BST-BMP180-DS000-09.pdf
 *
 ******************************/

#include "sd_dev_maxim_DS18B20_temperature.h"
static OneWire wire(_PIN_SD_MAXIM_DS18B20_TEMPERATURE);
static DallasTemperature sd_maxim_DS18B20(&wire);

/******************************
 *
 * Name:        sd_dev_apogee_BM180_temperature_open
 * Returns:     Nothing
 * Parameter:   Nothing
 * Description: Initialize BMP180 sensor
 *
 ******************************/

void sd_dev_maxim_DS18B20_temperature_open(void){
    sd_maxim_DS18B20.begin();
}

/******************************
 *
 * Name:        sd_dev_maxim_DS18B20_temperature_read
 * Returns:     Temperature in Celsius (C)
 * Parameter:   Nothing
 * Description: Read the temperature from the BMP180 sensor
 *
 ******************************/

int16_t sd_dev_maxim_DS18B20_temperature_read(void){
    int16_t value = 1000;

    #ifndef SEN_STUB
    sd_maxim_DS18B20.requestTemperatures();
    float value_f = sd_maxim_DS18B20.getTempCByIndex(0);
    value = value_f * 10;
    #endif

    return value;
}
