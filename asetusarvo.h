#ifndef ASETUSARVO_H
#define ASETUSARVO_H
#include <Arduino.h>

class asetusarvo         //Luokka, jossa luokitellaan mitkä "tiedot" ovat julkisia tai privaatteja.
{
  public:                                               //public osuudessa tiedot välittyvät termostaatti.ino tiedostoon 
    asetusarvo(int pin, float minVal, float maxVal);    //Määritetään mitä tietoa halutaan välittää .iso tiedostoon, esim. pinnit.
    float potentio();
  private:              //Nämä tiedot ovat vain .cpp ja .h tiedoston keskenään välittämää tietoa
    int _pin;
    float _maxVal;
    float _minVal;
};


#endif
