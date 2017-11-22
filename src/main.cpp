/* User Libraries */
#include "gen_sd/sd_board.h"

/* Arduino Libraries */
#include <Wire.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>
#include <SPI.h>

/* External Libraries */
#include <SHT1x.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_MPL115A2.h>
#include <XBee.h>

struct sd_board board;

void setup() {
    // put your setup code here, to run once:
    sd_board_init(&board);

    board.print_build_opts();
    board.setup(&board);
    board.post();
}

void loop() {
    // put your main code here, to run repeatedly:
    if(board.ready_sample(&board))  board.sample(&board);
    if(board.ready_tx(&board))      board.tx(&board);
    if(board.ready_run_cmd(&board))      board.run_cmd(&board);
    if(board.ready_heartbeat_tx(&board))      board.heartbeat_tx(&board);
}
