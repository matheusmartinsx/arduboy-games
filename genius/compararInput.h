#ifndef COMPARARINPUT_H
#define COMPARARINPUT_H

#include "globais.h"
#include "escolhasCores.h"

void aguardarJogada() {
  boolean jogada_efetuada = false;
  while (!jogada_efetuada) {
      if(arduboy.pressed(UP_BUTTON) == 1){
        botao_pressionado = 0;
        escolhaVerde();
        jogada_efetuada = true;
      }
      if(arduboy.pressed(LEFT_BUTTON) == 1){
        botao_pressionado = 1;
        escolhaVermelho();
        jogada_efetuada = true;
      }
      if(arduboy.pressed(DOWN_BUTTON) == 1){
        botao_pressionado = 2;
        escolhaAzul();
        jogada_efetuada = true;
      }
      if(arduboy.pressed(RIGHT_BUTTON) == 1){
        botao_pressionado = 3;
        escolhaAmarelo();
        jogada_efetuada = true;
      }
      delay(10);
  }
}

void verificarJogada() {
  if (sequencia[passo_atual_na_sequencia] != botao_pressionado) {
    // GAME OVER. 
    perdeu_o_jogo = true;
  }
}
void somGameOver(){
  arduboy.setRGBled(0,255,0);
  sound.tone(500, 100);
  arduboy.setRGBled(0,0,0);
  delay(100);
  arduboy.setRGBled(255,0,0);
  sound.tone(450,100);
  arduboy.setRGBled(0,0,0);
  delay(100);
  arduboy.setRGBled(0,255,0);
  sound.tone(300, 100);
  arduboy.setRGBled(0,0,0);
  delay(100);
  arduboy.setRGBled(0,0,255);
  sound.tone(250,100);
  arduboy.setRGBled(0,0,0);
  delay(100);
}
// Aguarda o jogador iniciar sua jogada.
void aguardarJogador() {
  for (int i = 0; i < rodada_atual; i++) {
    aguardarJogada();
    verificarJogada();
 
    if (perdeu_o_jogo) {
      i = rodada_atual;
      somGameOver();
      estadoJogo = GameOver;
    }
    passo_atual_na_sequencia++;
  }
  // Redefine a variável para 0.
  passo_atual_na_sequencia = 0;
}

#endif
