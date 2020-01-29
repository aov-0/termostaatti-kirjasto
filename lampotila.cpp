#include <Arduino.h>
#include "lampotila.h"

lampotila::lampotila(int pin){
  Serial.begin(9600);
  _pin = pin;
  for(int i = 0; i<5; i++){       //for silmukassa "i" muuttujaan tallennetaan i:n arvoksi 0, ja niin kauan kunnes i:n arvo on 5, lisätään lukemaan joka kierron jälkeen +1.
   TAULU[i] = 540;                //Tähän lisättiin keskimääräisen huonelämpötilan AD-arvo, koska keskiarvoistus ei jostain syystä toiminut tässä; laite alkoi heti käynnistettäessä puhaltaa täydellä teholla, kunnes ohjelma teki keskiarvoistuksen seuraavassa mittaus osiossa. 
  }
}

float lampotila::mittaus(){                 //Keskiarvoistus ja lukemien muuntaminen celsius asteiksi.
   TAULU[INDEX++] = analogRead(_pin);       //Luetaan anturin arvo. INDEX pitää kirjaa mittauksien lukumäärästä.
  if(INDEX == 5){                             //Jos luettuja arvoja on 5,
    INDEX = 0;                                //palataan laskuissa takaisin 0:aan.
  }
  float SUMMA = 0;                          //Alustaa SUMMA:n lähtöarvoksi 0.
  for(int i = 0; i<5; i++){               //Niin kauan kunnes on luettu 5 näytettä,
    SUMMA = SUMMA+TAULU[i];               //tallentuu aiemmin luettu arvo SUMMA yhteenlaskuun.
  } 
  return (-5.30/34.00)*(SUMMA/5.0)+105.9;          //Lukemien muuntamisessa on käytetty suoran yhtälöä.  
}
