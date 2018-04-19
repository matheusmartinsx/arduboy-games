#ifndef TELAINICIAL_H
#define TELAINICIAL_H

#include "sprites.h"

int frameTelaInicial = 0;

void animaInicial(){
  if(arduboy.everyXFrames(20)){
    if(frameTelaInicial != 6){
      frameTelaInicial++;    
      }else{
        frameTelaInicial = 0;
    }
  }
}

void telaInicial(){
  animaInicial();
  if(arduboy.notPressed(A_BUTTON) == 1){
    arduboy.clear();
    sprites.drawSelfMasked(0,0,spriteTelaInicial, frameTelaInicial);
    arduboy.display();
  }else{
    estadoJogo = Jogo; 
  }
}

#endif
