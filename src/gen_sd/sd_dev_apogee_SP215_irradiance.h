/*******************************
 *
 * File: sd_dev_apogee_sp215.h
 *
 * Contains prototypes for solar irradiance functions
 *
 ******************************/

#include <Arduino.h>

#define _PIN_SD_APOGEE_SP215_IRRADIANCE_ A4

#ifndef SD_DEV_APOGEE_SP215_IRRADIANCE_H
#define SD_DEV_APOGEE_SP215_IRRADIANCE_H
void sd_dev_apogee_SP215_irradiance_open(void);
int sd_dev_apogee_SP215_irradiance_read_raw(void);
int sd_dev_apogee_SP215_irradiance_read(void);
#endif
