#ifndef LAMPOTILA_H
#define LAMPOTILA_H
#include <Arduino.h>

class lampotila
{
  public:
    lampotila(int pin);
    float mittaus();
  private:
    int _pin;
    int TAULU[5];       //TAULU muuttuja keskiarvoistamista varten. Varaa 5 tallennuspaikkaa sen käyttöön.
    int INDEX = 0;      //INDEX muuttuja pitämään kirjaa näyttöönottojen määärästä.
};

#endif
