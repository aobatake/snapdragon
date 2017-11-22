/*******************************
 *
 * File: ga_dev_maxim_DS18B20_temperature.h
 *
 * Contains prototypes for bmp085 sensor functions
 *
 ******************************/

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define _PIN_SD_MAXIM_DS18B20_TEMPERATURE 3

#ifndef SD_DEV_MAXIM_DS18B20_TEMPERATURE_H
#define SD_DEV_MAXIM_DS18B20_TEMPERATURE_H
void sd_dev_maxim_DS18B20_temperature_open(void);
int16_t sd_dev_maxim_DS18B20_temperature_read(void);
#endif
