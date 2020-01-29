#include <Arduino.h>    //Hakee tämän header tiedoston yleensäkin toimiakseen
#include "asetusarvo.h" //Hakee asetusarvo header tiedoston 

asetusarvo::asetusarvo(int pin, float minVal, float maxVal){  //Konstruktori, tähän tulee samat määritykset kuin asetuarvo.h tiedoston public osiossa.
  _pin = pin;             //Nimityksille annetaan _-merkki nimen eteen jottei ohjelmassa tule ongelmia samojen nimitysten kanssa. Alaviivatut nimitykset ovat käytössä cpp ja header tiedostoissa.
  _minVal = minVal*100;   //Kerrotaan tässä 100:lla koska siten voidaan lisätä potentiometrin tarkkuutta
  _maxVal = maxVal*100;   //-..-
}

float asetusarvo::potentio(){                   //Käytetään float:ia koska siten saadaan tarkempia lukemia potentiometristä.
  int ASETUS = analogRead(_pin);                //Lukee potentiometrin AD arvon.
  
  return map(ASETUS, 0.0, 1023.0, _minVal, _maxVal)/100.0;    //Muuntaa potentiometrin äärilukemat 0 ja 1023, lukemiksi 1 ja 7 (0 = 1 ja 1023 = 7). Jaetaan sadalla koska aiemmin kerrottiin sadalla.
}
