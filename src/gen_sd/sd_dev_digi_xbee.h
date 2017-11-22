/*******************************
 *
 * File: sd_dev_digi_xbee.h
 *
 * Contains prototypes for XBee Transceiver functions
 *
 ******************************/

#include <Arduino.h>
#include <XBee.h>
#include <SoftwareSerial.h>

#define _SD_DEV_DIGI_XBEE_BUFSIZE_ 150

#ifndef SD_DEV_DIGI_XBEE
#define SD_DEV_DIGI_XBEE
void sd_dev_digi_xbee_open(void);
int sd_dev_digi_xbee_avail(void);
int sd_dev_digi_xbee_read(void);
void sd_dev_digi_xbee_write(uint8_t* data, int data_len);

static XBee xbee = XBee();

#endif
