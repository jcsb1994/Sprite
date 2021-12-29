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
  //    This file contains an example of the UiSprite ColorSprite library implementing
  //    a loading bar sprite class.
  //    Implemented using:
  //      -Arduino core
  //      -TFT_eSPI library to operate a TFT screen
  //      -ESP32TimerInterrupt library to operate a non blocking timer controling the sprite animation
  //
  //***********************************************************************************


  #include <Arduino.h>
  #include "TFT_eSPI.h"
  #include "ESP32TimerInterrupt.h"
  #include "ColorSprite.h"

  #define SPRITE_TIMER_INTERRUPT_MS (500)

  #define NMOS_GATE_PIN 16

  #define LOAD_BAR_NB_STATES (3)

  class LoadBar : public ColorSprite {
  public:
    LoadBar(uint16_t inactiveColor, uint16_t activeColor, TFT_eSPI*tft) : 
    ColorSprite(LOAD_BAR_NB_STATES, inactiveColor, activeColor) { screen = tft; }

    ~LoadBar(){}

  private:
    TFT_eSPI *screen;

    const uint8_t _distBetweenUnits = 25;
    const uint8_t _radius = 10;

    void _drawUnit(uint16_t color, uint8_t idx) {
      screen->fillCircle(_xPos + idx*_distBetweenUnits, _yPos, _radius, color);
    }
  };

  // Global objects
  ESP32Timer timer;

  TFT_eSPI tft;

  LoadBar loadingBar = LoadBar(TFT_YELLOW, TFT_DARKCYAN, &tft);

  static void IRAM_ATTR timerHandler()
  {
    loadingBar.nextState();
  }

  // main
  void setup()
  {
    Serial.begin(9600);
    Serial.print("yo");

    pinMode(NMOS_GATE_PIN, OUTPUT);
    digitalWrite(NMOS_GATE_PIN, HIGH);  // turn NMOS on

    timer = ESP32Timer(1);
    timer.attachInterruptInterval(SPRITE_TIMER_INTERRUPT_MS * 1000, timerHandler);

    loadingBar.setPos(20, 120);

    // initialize screen
    tft.init();
    tft.setRotation(0);
    tft.fillScreen(TFT_BLACK);
    tft.setTextWrap(true);
    tft.setTextSize(3);
  }

  void loop()
  {
    if(loadingBar.isChanged()) {
      loadingBar.draw();
    }
  }