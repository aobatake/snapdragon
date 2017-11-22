/*******************************
 *
 * File: sd_dev_adafruit_MPL115A2_pressure.h
 *
 * Contains prototypes for pressure sensor functions
 *
 ******************************/

#include <Arduino.h>
#include "Adafruit_MPL115A2.h"

#ifndef SD_DEV_MPL115A2_H
#define SD_DEV_MPL115A2_H
void sd_dev_adafruit_MPL115A2_pressure_open(void);
uint32_t sd_dev_adafruit_MPL115A2_pressure_pa_read(void);
void sd_dev_adafruit_MPL115A2_pressure_pa_test(void);
#endif
