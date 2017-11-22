/*******************************
 *
 * File: sd_dev_battery.cpp
 *
 * This module is a driver for checking the battery reading in mV.
 *
 ******************************/

#include "sd_dev_battery.h"

/******************************
 *
 * Name:        sd_dev_batt_open
 * Returns:     Nothing
 * Parameter:   Nothing
 * Description: Initialize battery reading pins
 *
 ******************************/

void sd_dev_battery_open(void){
    pinMode(_PIN_SD_BATTERY_, INPUT);
}

/******************************
 *
 * Name:        sd_dev_batt_read_raw
 * Returns:     Battery reading in mV
 * Parameter:   Nothing
 * Description: Reads battery voltage without conversion
 *
 ******************************/

int sd_dev_battery_read_raw(void){
    int value;
    value = analogRead(_PIN_SD_BATTERY_);
    return value;
}

/******************************
 *
 * Name:        sd_dev_batt_read
 * Returns:     Battery reading in mV
 * Parameter:   Nothing
 * Description: Reads battery voltage with conversion
 *
 ******************************/

int sd_dev_battery_read(void){
    int val = 555;

    #ifndef SEN_STUB
    float raw = (float)analogRead(_PIN_SD_BATTERY_) * (5.0/1023.0);
    val = raw * 1000;
    #endif

    return val;
}
