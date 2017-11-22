#ifndef SD_BOARD_H
#define SD_BOARD_H

#include "sd_dev_digi_xbee.h"
#include "sd_dev_sensirion_SHT1X_humidity.h"
#include "sd_dev_battery.h"
#include "sd_dev_solar_panel.h"
#include "sd_dev_eeprom_node_address.h"
#include "sd_dev_apogee_SP215_irradiance.h"
#include "sd_dev_maxim_DS18B20_temperature.h"
#include "sd_dev_adafruit_MPL115A2_pressure.h"

struct sd_packet{
    uint16_t schema;
    uint16_t node_address;                                  // Address of Arduino
    uint32_t uptime_milliseconds;                           // Time since start of program
    uint16_t battery_millivolts;                            // Battery Voltage (in milli volts)
    uint16_t panel_millivolts;                              // Panel Voltage (in milli volts)
    uint32_t mpl115a2_pressure_pascals;                       // Pressure Value (in pascals)
    int16_t ds18b20_temperature_kelvin;                      // Temperature Value (in celsius) (ideally we change this to Kelvin)
    uint16_t sht1x_humidity_percent;                        // Humidity Value (in percentage)
    uint16_t sp215_irradiance_watts_per_square_meter;       // Solar Irradiance Value (in w/m^2)
};

/* Lesdcy Heartbeat 1.0 Packet */
struct sd_heartbeat_packet{
    uint16_t schema;
    uint16_t node_address;         // Address of Arduino
    uint32_t uptime_milliseconds;   // Time since start of program
    uint16_t battery_millivolts;    // Battery Voltage (in milli volts)
};

/* Heartbeat 2.0 Packet
struct sd_heartbeat_packet {
  uint16_t schema;
  uint16_t node_addr;
  uint32_t uptime_ms;
  uint16_t batt_mv;
  float latitude;
  float longitude;
  float altitude;
  uint8_t generation;
  uint8_t version;
  uint8_t revision;
  uint32_t deployment_date; //Epoch date
};
*/


struct sd_board{
    void (*setup)(struct sd_board* b);
    void (*post)(void);
    void (*sample)(struct sd_board* b);
    void (*run_cmd)(struct sd_board* b);
    void (*print_build_opts)(void);
    void (*tx)(struct sd_board* b);
    int (*ready_tx)(struct sd_board* b);
    int (*ready_sample)(struct sd_board* b);
    int (*ready_run_cmd)(struct sd_board* b);

    int (*ready_heartbeat_tx)(struct sd_board* b);
    void (*heartbeat_tx)(struct sd_board* b);

    unsigned long prev_sample_ms;
    unsigned long prev_heartbeat_ms;
    int sample_count;
    uint16_t node_address;
    struct sd_packet data_packet;
};


void sd_board_init(struct sd_board*);

#endif
