#include "Tap.h"



Tap::Tap(int mainOpen, int mainClose, int closePort, int openPort)
{
  portTapOpen = mainOpen;
  portTapClose = mainClose;
  portClose = closePort;
  portOpen = openPort;
  testTap = true;
  statusTap = CLOSED;
  //alarm = false;
}
// Get methods--------------------------------

int Tap::getStatus()
{
  return statusTap;
}

int Tap::getPortOpen()
{
	return portOpen;
}

int Tap::getPortClose()
{
	return portClose;
}

int Tap::getPortTapOpen()
{
	return portTapOpen;
}

int Tap::getPortTapClose()
{
	return portTapClose;
}

bool Tap::getTest()
{
	return testTap;
}

bool Tap::getAlarm()
{
	return alarm;
}

//End get method---------------------------------
//Set method-------------------------------------
void Tap::setStatus(int status)
{
  statusTap = status;
}

void Tap::setTest(bool test)
{
  testTap = test;
}

void Tap::setAlarm(bool statAlarm)
{
  alarm = statAlarm;
}
//End set method-----------------------------------
