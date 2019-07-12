/*
  Клапан
*/

#pragma once

enum ValueFouset
{
  CLOSED = 0, 	//Закрыто
  CLOSING,		//Закрывается
  OPEN,			//Открыто
  OPENING		//Открывается
};

class Tap
{
  private:
    int portTapOpen;
    int portTapClose;
    int portClose;		//порт концевика закрытия
    int portOpen;		//порт концевика открытия
    int statusTap;		//Состояние крана
    bool testTap;		//Тест крана
    bool alarm;				//Режим тревоги


  public:
    Tap(int mainOpen, int mainClose, int closePort, int openPort);
	//Узнать состояние крана
    int getStatus();
    int getPortOpen();
    int getPortClose();
    int getPortTapOpen();
    int getPortTapClose();
	//Узнать включен ли тест крана
    bool getTest();
    bool getAlarm();

	//Статус сотояния крана
    void setStatus(int);
	//Тестовая работа крана (Открытие/Закрытие)
    void setTest(bool);
	//Режим тревоги
    void setAlarm(bool);
};
