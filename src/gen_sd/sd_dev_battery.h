/*******************************
 *
 * File: sd_dev_battery.h
 *
 * Contains prototypes for battery reading functions
 *
 ******************************/

#include <Arduino.h>

#define _PIN_SD_BATTERY_ A0

#ifndef SD_DEV_BATTERY_H
#define SD_DEV_BATTERY_H
void sd_dev_battery_open(void);
int sd_dev_battery_read_raw(void);
int sd_dev_battery_read(void);
#endif
