#include <Arduino.h>
#include "tuuletin.h"

//Konstruktori
tuuletin::tuuletin(int fan, float minErotus, float maxErotus, char minNopeus, int LEDVIH, int LEDSIN){
  _fan = fan;
  _LEDVIH = LEDVIH;
  _LEDSIN = LEDSIN;
  _minErotus = minErotus;
  _maxErotus = maxErotus;
  _minNopeus = minNopeus;
  pinMode(_fan, OUTPUT);
  pinMode(_LEDVIH, OUTPUT);
  pinMode(_LEDSIN, OUTPUT);
  analogWrite(_fan, 0);       //Alustetaan puhallin pois päältä, ettei se lähde heti alussa pyörimään.
}

void tuuletin::ohjaus(float tempAsetus, float tempMittaus){   //Nämä varsinaiset mittaukset tehdään void loop:ssa
  float erotus = tempMittaus-tempAsetus;        //Laskee mitatun lämpötilan ja asetetun arvon erotuksen
  if(erotus <= _minErotus/2){                   //Jos erotus on pienempi tai yhtä suuri kuin minimierotus jaettuna kahdella (0,5 astetta), 
    analogWrite(_fan, 0);                       //puhallin menee pois päältä.
    digitalWrite(_LEDSIN, LOW);                 //Sininen ledi sammuu,
    digitalWrite(_LEDVIH, HIGH);                //ja vihreä ledi syttyy.
  }else if(erotus >= _maxErotus){               //Jos erotus on suurempi tai yhtä suuri kuin maksimierotus,
    analogWrite(_fan, 255);                     //pyörii puhallin täydellä nopeudella. Lisätty siksi että jos arvo nousi aiemmin yli 255, hidastui puhaltimen pyöriminen, koska arvo palasi takaisin 0:n.
    digitalWrite(_LEDVIH, LOW);                 //Vihreä ledi sammuu kun puhallin pyörii,
    digitalWrite(_LEDSIN, HIGH);                //ja sininen ledi syttyy indikoidakseen jäähdytystä.
  }else if(erotus >= _minErotus){                                                             //Jos erotus on suurempi tai yhtä suuri kuin minimierotus,
    analogWrite(_fan, map(erotus*1000, _minErotus*1000, _maxErotus*1000, _minNopeus, 255));   //puhallin alkaa pyöriä mäppäyksen mukaisella arvolla.
    digitalWrite(_LEDVIH, LOW);
    digitalWrite(_LEDSIN, HIGH);
  }
}

//tuuletin FAN(11, 1, 7, 60, 13, 12);
