//Hakee eri toimintojen omat header tiedostot
#include "tuuletin.h"
#include "lampotila.h"
#include "asetusarvo.h"

//Hakee konstruktorit omilla nimillään, isolla kirjoitetut nimitykset määrittää tähän .iso tiedostoon määritykset ja mitkä pinnit tai halutut arvot ovat käytössä.
tuuletin FAN(11, 1, 7, 60, 13, 12);   //Pinnit ja halutut arvot määritetään header tiedostoissa
lampotila ANTURI(A0);
asetusarvo POT(A1, 16, 30);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float lampotila = ANTURI.mittaus();   //Lukee lämpötilan lampotila konstruktorin kautta
  Serial.print("Mitattu lampotila: ");
  Serial.print(lampotila);              //Tulostaa luetun lämpötilan
  Serial.println(" astetta");
  float asetettu = POT.potentio();      //Lukee potentiometrin arvon asetusarvo konstruktorin kautta
  Serial.print("Asetus-arvo: ");
  Serial.print(asetettu);
  Serial.println(" astetta");
  delay(1000);
  FAN.ohjaus(asetettu, lampotila);      //Ohjaa tuuletinta tuuletin konstruktorin kautta
}
