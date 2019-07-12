/*
  1. Сканирование всех точек на предмет протечки
  2. Проверка состояния крана
  3. Тест крана через определенное вреня
  4. Отображение состояния на дисплей
*/

#pragma once

#include "Tap.h"
#include "waterPoint.h"
#include "Variables.h"
#include <Arduino.h>


class WorkOut
{
    Tap tap;
    waterPoint scanRoom[4];
    bool startTime;
    bool actionDisplay;               //Для уменьшения количества обновлений экрана если true то дисплей обновляется
    unsigned long testTime;
  public:
    WorkOut(): tap(GO_TAP_OPEN, GO_TAP_CLOSE, BUTTON_TAP_OPEN, BUTTON_TAP_CLOSE),						//Инициализация крана (Порт для открытия,Порт для закрытия,Порт концевика открытия,Порт концевика закрытия)
      scanRoom{								        //Инициализация точек сканирования
      waterPoint("Washing machine", POINT_SCAN_1),
      waterPoint("Kitchen", POINT_SCAN_2),
      waterPoint("Drain", POINT_SCAN_3),
      waterPoint("Tub", POINT_SCAN_4)},
      startTime(false),
      actionDisplay(true),
      testTime(0)							//Время начала отсчета до на чала теста
    {

    }
    /*Сканирование портов. Приобнаружении утечки инициализация закрытия крана
      Далее режим ожидания пользователя
      При нажатии кнопки сброса необходимо проверить порты и есло все нормально открыть кран.
      Отдельный режим тест крана. Открыть и закрыть.
      Все отображать на дисплей
    */

    //Проверяет указанный порт, если 0 = OK, 1 = тревога
    bool scanPoint(int port);

    //Проход всех портов и при необходимости замена данных о порте если true значит тревога
    bool scanAllPoint();

    //Проверка точек и управление краном
    void actionTap();

    //Проверка концевиков крана
    bool statTapButton();

    //Пуск закрытия или открытия
    void goTap();

    //Остановка крана
    void stopTap();

    //Формирование изображения
    friend void showDisplay();

    //
    void setAction(bool act);

    bool getAction();

	//Снятие тревоги со всех точек
    void nullPoint();
};
