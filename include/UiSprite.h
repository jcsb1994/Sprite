//***********************************************************************************
// Copyright 2021 jcsb1994
// Written by jcsb1994
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//***********************************************************************************
//
// Description:
//    This file contains a parent class for creating on-screen sprite classes
//
//***********************************************************************************

#ifndef UI_SPRITE_H
#define UI_SPRITE_H

#include <Arduino.h>


class UiSprite
{
public:
  UiSprite(uint8_t nbStates) : _nbStates(nbStates) {}
  ~UiSprite() {}
  void nextState()
  {
    _stateCounter++;
    _isStateChanged = true; 
    if (_stateCounter >= _nbStates)
    {
      _stateCounter = 0;
    }
  }
  void setPos (uint16_t xPos, uint16_t yPos) { _xPos = xPos;
  _yPos = yPos; }
  bool isChanged() {return _isStateChanged; }
protected:
  uint8_t _stateCounter = 0;
  const uint8_t _nbStates;
  uint16_t _xPos;
  uint16_t _yPos;

  bool _isStateChanged = true; 
};

#endif