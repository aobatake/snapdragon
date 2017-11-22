/*******************************
 *
 * File: sd_dev_solar_panel.h
 *
 * Contains prototypes for solar panel functions
 *
 ******************************/

#include <Arduino.h>

#define _PIN_SD_SOLAR_PANEL_ A1

#ifndef SD_DEV_SOLAR_PANEL
#define SD_DEV_SOLAR_PANEL
void sd_dev_solar_panel_open(void);
int sd_dev_solar_panel_read(void);
#endif
