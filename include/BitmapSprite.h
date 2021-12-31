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
//    sprites using a sequence of bitmaps to animate it
//
//***********************************************************************************

#ifndef MOVE_SPRITE_H
#define MOVE_SPRITE_H

#include <Arduino.h>
#include "UiSprite.h"

class BitmapSprite : public UiSprite
{
public:
    BitmapSprite(uint8_t nbStates, uint16_t color, uint16_t backgroundColor) : 
        UiSprite(nbStates), _color(color), _backgroundColor(backgroundColor) {}
    ~BitmapSprite() {}

    void setBitmaps(const unsigned char* bitmaps) {
        _bitmaps = bitmaps;
    }
    void setDimensions(uint16_t x, uint16_t y) { _xDim = x, _yDim = y; }

    void draw()
    {
        _drawUnit(_stateCounter);
    }

protected:
    const uint16_t _color; // color of the inactive parts of the sprite
    const uint16_t _backgroundColor;   // color of the active part of the sprite
    uint16_t _xDim = 0;
    uint16_t _yDim = 0;
    const unsigned char* _bitmaps = NULL;

    virtual void _drawUnit(uint8_t index) {}
};

#endif