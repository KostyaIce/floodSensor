#include "WorkOut.h"

//Возвращает true если тревога на точке сканирования
bool WorkOut::scanPoint(int port)
{
	if (analogRead(port)<MIN_VALUE_WATER)return true;
	return false;
}


//Если в какой ниудь точке сработала тревога кран ставится по тревоге и возвращается true 
bool WorkOut::scanAllPoint()
{
	int counter = 0;
	for (int i = 0; i < waterPoint::getAllPoint(); i++)
	{
		if (scanPoint(scanRoom[i].getPort()))
		{
      if(!scanRoom[i].getAlarm())
        scanRoom[i].setAlarm(true);

       counter++; 
       
			if(!tap.getAlarm()) 
			    tap.setAlarm(true);
		}			
	}
 actionDisplay = true; 
	if(!counter)return false;
	else return true;
}


void WorkOut::nullPoint()
{
  for (int i = 0; i < waterPoint::getAllPoint(); i++)
  {
    scanRoom[i].setAlarm(false);
  }
}

//Если обнаружена течь(Тревога) Клапан закрывается. Если при открытии клапана появилась течь, то инициируется закрытие клапана.
void WorkOut::actionTap()
{
	if(scanAllPoint())
	{
	  tap.setAlarm(true);
  		if(tap.getStatus()==OPENING)
		  {
			  tap.setStatus(OPEN);
		  }
		goTap();
	}
	
	if(VALUE_TEST_TIME > millis()-testTime)
	{
			tap.setTest(true);
	}
	
	if(!tap.getAlarm() && tap.getTest())
	{
    if(tap.getStatus() == OPEN)
    {
		  tap.setTest(false);
		  goTap();
		  testTime = millis();
    }
    if(tap.getStatus() == CLOSED)
    {
      tap.setTest(false);
      goTap();
    }
	}
 
}


//Нажатие кнопки
bool WorkOut::statTapButton()
{
  if (digitalRead(BUTTON))
  {
    if(!scanAllPoint())
	{
    
		nullPoint();
		tap.setAlarm(false);
		goTap();
	}
	actionDisplay = true;
    return true;
  }
  return false;
}

//Действие крана(Открыти/Закрытие
void WorkOut::goTap()
{
	if(tap.getAlarm() || tap.getTest())
	{
		if (tap.getStatus() == OPEN) {
			tap.setStatus(CLOSING);
			digitalWrite(tap.getPortTapOpen(),LOW);
			digitalWrite(tap.getPortTapClose(),HIGH);
			actionDisplay = true;
			}
	}
	if(!tap.getAlarm())
	{		
		if (tap.getStatus() == CLOSED )
			{
      
			tap.setStatus(OPENING);
			digitalWrite(tap.getPortTapClose(),LOW);
			digitalWrite(tap.getPortTapOpen(),HIGH);
			actionDisplay = true;
			}
  }
}

//Остановка крана
void WorkOut::stopTap()
{
	if (tap.getStatus() == OPENING && digitalRead(tap.getPortOpen())) {
		tap.setStatus(OPEN);
		digitalWrite(tap.getPortTapOpen(),LOW);
		
		actionDisplay = true;
	}
	if (tap.getStatus() == CLOSING && digitalRead(tap.getPortClose())) {
		digitalWrite(tap.getPortTapClose(),LOW);
		tap.setStatus(CLOSED);
		actionDisplay = true;
	}
}


void WorkOut::setAction(bool act)
{
   actionDisplay = act;
}


bool WorkOut::getAction()
{
  return actionDisplay;
}
