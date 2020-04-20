/*------------------------------------------------------------*-
  Library for controlling PS2X controller with Raspberry Pi
  Tested on: Raspberry Pi 3B/3B+
  (c) Minh-An Dao 2020  <bit.ly/DMA-HomePage>.
  version 1.00 - 19/04/2020
 --------------------------------------------------------------
 * Module created for the purpose of communicate 
 * with the PS2X controller.
 *
 * Ported from Arduino-PS2X library (https://github.com/madsci1016/Arduino-PS2X)
 * Documents:
 *  - https://store.curiousinventor.com/guides/PS2
 *  - https://gist.github.com/scanlime/5042071
 --------------------------------------------------------------*/
#ifndef __PI_PS2X_H
#define __PI_PS2X_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>

// ------ Public constants ------------------------------------
typedef unsigned char byte;
// typedef uint8_t bool
// ------ Public function prototypes --------------------------

// ------ Public variable -------------------------------------

//--------------------------------------------------------------
// CLASS DEFINITIONS
//--------------------------------------------------------------
class PS2X {
  public:
    PS2X(int, int, int, int, bool, bool, bool); // constructor
    ~PS2X();                // destructor
    // bool reconfig(bool, bool, bool); // reconfig the controller
    // void update(void); // very important function to put in the loop


    
  private:
    byte __shiftout(byte); // performs a simultaneous write/read transaction over the selected SPI bus
    int __sendCommand(byte*);
    int __getData(byte*);
    // byte spi_channel;
    // int spi_speed;
    int dat;
    int cmd;
    int sel;
    int clk;
    bool en_analog;
    bool en_pressure;
    bool en_rumble;
    byte ps2data[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    unsigned long last_millis;
    int last_buttons;
    int buttons = 0;

};
#endif //__PI_PS2X_H