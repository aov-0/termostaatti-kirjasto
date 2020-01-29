#ifndef TUULETIN_H
#define TUULETIN_H
#include <Arduino.h>

class tuuletin
{
  public:
    tuuletin(int fan, float minErotus, float maxErotus, char minNopeus, int LEDVIH, int LEDSIN);
    void ohjaus(float tempAsetus, float tempMittaus);
  private:
    int _fan, _LEDVIH, _LEDSIN;
    float _minErotus, _maxErotus;
    char _minNopeus;
};

#endif
