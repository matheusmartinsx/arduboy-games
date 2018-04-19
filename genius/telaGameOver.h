#ifndef TELAGAMEOVER_H
#define TELAGAMEOVER_H

#include "sprites.h"

int frameTelaFinal = 0;

void animaFinal(){
  if(arduboy.everyXFrames(20)){
    if(frameTelaFinal != 2){
      frameTelaFinal++;    
      }else{
        frameTelaFinal = 0;
    }
  }
}

void desenhaPontuacao(){
  unidadePontuacao = rodada_atual % 10;
  decimalPontuacao = (rodada_atual/10);
  
    
  sprites.drawSelfMasked(89,38,spritesNumeros, frameNumero(decimalPontuacao));
  sprites.drawSelfMasked(97,38,spritesNumeros, frameNumero(unidadePontuacao));
}

void telaGameOver(){
  animaFinal();
  if(arduboy.notPressed(A_BUTTON) == 1){
    arduboy.clear();
    sprites.drawSelfMasked(0,0,spriteTelaGameOver, frameTelaFinal);
    desenhaPontuacao();
    arduboy.display();
  }else{
    sequencia[100] = {};
    rodada_atual = 0;
    passo_atual_na_sequencia = 0; 
    botao_pressionado = 0;
    perdeu_o_jogo = false; 
    delay(500);
    estadoJogo = Inicial;
  }
}

#endif
