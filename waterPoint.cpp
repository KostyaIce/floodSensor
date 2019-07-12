#include "waterPoint.h"

int waterPoint::allPoint(0);

waterPoint::waterPoint(const char *name, int number)
{
  portNumber = number;
  pNamePoint = name;
  allPoint++;
  numPoint = allPoint;
  alarmPoint = false;
}

const char* waterPoint::getNamePoint() const
{
  return pNamePoint;
}
const bool waterPoint::getAlarm() const
{
  return alarmPoint;
}

int waterPoint::getAllPoint()
{
  return allPoint;
}

const int waterPoint::getNumber() const
{
  return this->numPoint;
}

const int waterPoint::getPort()
{
  return this->portNumber;
}

void waterPoint::setAlarm(bool valueDangers)
{
  alarmPoint = valueDangers;
}
