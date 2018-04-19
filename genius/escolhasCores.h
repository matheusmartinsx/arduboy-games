#ifndef ESCOLHASCORES_H
#define ESCOLHASCORES_H

#include "globais.h"

void escolhaVerde(){
  arduboy.setRGBled(0,255,0);
  sound.tone(250, 50);
  delay(250);
  arduboy.setRGBled(0,0,0);
}

void escolhaVermelho(){
  arduboy.setRGBled(255,0,0);
  sound.tone(550, 50);
  delay(250);
  arduboy.setRGBled(0,0,0);
}

void escolhaAzul(){
  arduboy.setRGBled(0,0,255);
  sound.tone(750, 50);
  delay(250);
  arduboy.setRGBled(0,0,0);
}

void escolhaAmarelo(){
  arduboy.setRGBled(255,255,0);
  sound.tone(950, 50);
  delay(250);
  arduboy.setRGBled(0,0,0);
}

#endif
