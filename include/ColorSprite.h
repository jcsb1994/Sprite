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
//    This file contains a child class for creating child classes that manage
//    non-moving UI animations that have moving colors across repetitive shapes 
//    (ex: loading bars)
//
//***********************************************************************************

#ifndef COLOR_SPRITE_H
#define COLOR_SPRITE_H

#include <Arduino.h>
#include "UiSprite.h"

class ColorSprite : public UiSprite
{
public:
    ColorSprite(uint8_t nbStates, uint16_t inactiveColor, uint16_t activeColor) : UiSprite(nbStates), _inactiveColor(inactiveColor), _activeColor(activeColor) {}
    ~ColorSprite() {}

    void draw()
    { // could be a generic fct...
        for (uint8_t i = 0; i < _nbStates; i++)
        {
            uint16_t color;
            (i == _stateCounter) ? color = _activeColor : color = _inactiveColor;
            _drawUnit(color, i);
        }
    }

protected:
    const uint16_t _inactiveColor; // color of the inactive parts of the sprite
    const uint16_t _activeColor;   // color of the active part of the sprite

    virtual void _drawUnit(uint16_t color, uint8_t index) {}
};

#endif