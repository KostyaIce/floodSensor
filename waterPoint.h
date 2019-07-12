/*
  Точка сканирования протечки
*/
#pragma once

class waterPoint {
  private:
    static int allPoint;
    int numPoint;
    int portNumber;
    bool alarmPoint;
    const char* pNamePoint;
  public:

    waterPoint(const char *name, int number);

    //Гетеры
    const char* getNamePoint() const;
    const bool getAlarm() const;
    static int getAllPoint();
    const int getNumber() const;
    const int getPort();
    //Сетеры
    void setAlarm(bool);
};
