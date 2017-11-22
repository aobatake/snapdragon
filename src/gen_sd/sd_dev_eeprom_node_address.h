/*******************************
 *
 * File: sd_dev_eeprom_node_address.h
 *
 * Contains prototypes for EEPROM functions
 *
 ******************************/

#include <Arduino.h>
#include <EEPROM.h>

#ifndef SD_DEV_EEPROM_NODE_ADDRESS_H
#define SD_DEV_EEPROM_NODE_ADDRESS_H
void sd_dev_eeprom_node_address_open(void);
uint16_t sd_dev_eeprom_node_address_read(void);
#endif
