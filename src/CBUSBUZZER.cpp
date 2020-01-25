/*

  Copyright (C) Duncan Greenwood 2017 (duncan_greenwood@hotmail.com)
Copyright (C) John Fletcher 2020
(john@bunbury28.plus.com)

  This work is licensed under the:
      Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
   To view a copy of this license, visit:
      http://creativecommons.org/licenses/by-nc-sa/4.0/
   or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.

   License summary:
    You are free to:
      Share, copy and redistribute the material in any medium or format
      Adapt, remix, transform, and build upon the material

    The licensor cannot revoke these freedoms as long as you follow the license terms.

    Attribution : You must give appropriate credit, provide a link to the license,
                  and indicate if changes were made. You may do so in any reasonable manner,
                  but not in any way that suggests the licensor endorses you or your use.

    NonCommercial : You may not use the material for commercial purposes. **(see note below)

    ShareAlike : If you remix, transform, or build upon the material, you must distribute
                 your contributions under the same license as the original.

    No additional restrictions : You may not apply legal terms or technological measures that
                                 legally restrict others from doing anything the license permits.

   ** For commercial use, please contact the original copyright holder(s) to agree licensing terms

    This software is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE

*/

#include "CBUSBUZZER.h"

//
/// class to encapsulate a buzzer
//

CBUSBUZZER::CBUSBUZZER() {

  _state = false;
  _tone = 0U;
}

//  set the pin for this buzzer

void CBUSBUZZER::setPin(byte pin) {

  _pin = pin;
  pinMode(_pin, OUTPUT);
}

//  set the tone for this buzzer

void CBUSBUZZER::setTone(unsigned int tone) {

  _tone = tone;
}

//  get the tone set for this buzzer

unsigned int CBUSBUZZER::getTone()
{
  return _tone;
}

// return the current state, on or off

bool CBUSBUZZER::getState() {

  return _state;
}

// turn buzzer state on

void CBUSBUZZER::on(void) {

  _state = true;
  tone(_pin,_tone);
}

// turn buzzer state off

void CBUSBUZZER::off(void) {

  _state = false;
  noTone(_pin);
}

// toggle buzzer state from on to off or vv

void CBUSBUZZER::toggle(void) {

   if(_state) { off(); }
   else { on(); }
}
