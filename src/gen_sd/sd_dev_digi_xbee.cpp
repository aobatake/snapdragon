/*******************************
 *
 * File: sd_dev_digi_xbee.cpp
 *
 * This module is a driver for the XBee Transceiver. This
 * is used to radio communication with the server
 *
 * Product page:
 *
 ******************************/

#include "sd_dev_digi_xbee.h"

/******************************
 *
 * Name:        sd_dev_digi_xbee_open
 * Returns:     Nothing
 * Parameter:   Nothing
 * Description: Initialize XBee pins
 *
 ******************************/

void sd_dev_digi_xbee_open(void)
{
    Serial.begin(9600);
    xbee.begin(Serial);
}

/******************************
 *
 * Name:        sd_dev_digi_xbee_avail
 * Returns:     0 if busy, 1 if available
 * Parameter:   Nothing
 * Description: Check to see if the XBee is busy
 *
 ******************************/

int sd_dev_digi_xbee_avail(void)
{
    return Serial.available();
}

/******************************
 *
 * Name:        sd_dev_digi_xbee_read
 * Returns:     Data from XBee
 * Parameter:   Nothing
 * Description: Read data from the XBee
 *
 ******************************/

int sd_dev_digi_xbee_read(void)
{
    return Serial.read();
}

/******************************
 *
 * Name:        sd_dev_digi_xbee_write
 * Returns:     Nothing
 * Parameter:   Nothing
 * Description: Transmits packet through XBee
 *
 ******************************/

void sd_dev_digi_xbee_write(uint8_t *data, int data_len)
{
    XBeeAddress64 addr64 = XBeeAddress64(0, 0);
    ZBTxRequest zbtx = ZBTxRequest(addr64, data, data_len);

    xbee.send(zbtx);
}
