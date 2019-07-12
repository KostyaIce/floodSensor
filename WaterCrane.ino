#include "Monitor.h"
#include "Variables.h"

void setup() {
pinMode(POINT_SCAN_1,INPUT);//Датчики
pinMode(POINT_SCAN_2,INPUT);
pinMode(POINT_SCAN_3,INPUT);
pinMode(POINT_SCAN_4,INPUT);
pinMode(BUTTON_TAP_OPEN,INPUT);//Концевики
pinMode(BUTTON_TAP_CLOSE,INPUT);
pinMode(GO_TAP_OPEN,OUTPUT);//Управление приводом
pinMode(GO_TAP_CLOSE,OUTPUT);
pinMode(BUTTON,INPUT);//кнопка сброса
digitalWrite(GO_TAP_OPEN,LOW);
digitalWrite(GO_TAP_CLOSE,LOW);
runDisplay();
showDisplay();
}

void loop() {
//Просканировать точки затопления
mainProc.actionTap();

mainProc.stopTap();
//Обработка нажатия кнопки при снятии с тревоги
mainProc.statTapButton();

showDisplay();
}
