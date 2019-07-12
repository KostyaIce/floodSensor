#pragma once
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "WorkOut.h"

WorkOut mainProc;

const int SCREEN_WIDTH = 128;       //displey width on pixel
const int SCREEN_HEIGHT = 32;       //height

const int8_t OLED_RESET = 4;           //pin reset по факту не используется

const char *TEXT_OK = "OK    ";
const char *TEXT_ALARM = "ALARM ";
const char *TEXT_OPEN = "OPEN";
const char *TEXT_CLOSE = "CLOSE";
const char *TEXT_TEST = "TEST";

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


//Инициализация дисплея
void runDisplay()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
}

//Выделить текст
void selectText(const char *text)
{
  display.setTextColor(0, 1);
  display.print(text);
  display.setTextColor(1, 0);
}

//Загрузка изображения.
void showDisplay()
{
  if (mainProc.getAction())
  {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);

    //Заполняем основные пункты
    for (int i = 0; i < waterPoint::getAllPoint(); i++)
    {
      if(!mainProc.scanRoom[i].getAlarm())
        {
          if(mainProc.tap.getStatus()==CLOSING || mainProc.tap.getStatus()==OPENING)
            selectText(TEXT_OK);
          else
            display.print(TEXT_OK);
        }else
          selectText(TEXT_ALARM);
      display.println(mainProc.scanRoom[i].getNamePoint());

    }
    display.setCursor(90, 16);
    
  if(mainProc.tap.getAlarm())
    {
      selectText(TEXT_ALARM);
    }
    
   if(mainProc.tap.getTest())
    {
      selectText(TEXT_TEST);
    }
    //Надпись Open/Close
    display.setCursor(90, 24);
    if(mainProc.tap.getStatus()== OPEN)
      {
        display.print(TEXT_OPEN);
        display.print(mainProc.tap.getStatus());//**
      }
    else
      {
        selectText(TEXT_CLOSE);
        display.print(mainProc.tap.getStatus());//**
      }
    display.display();
    mainProc.setAction(false);
  }
}
