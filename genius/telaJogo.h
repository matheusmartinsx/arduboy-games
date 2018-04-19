#ifndef TELAJOGO_H
#define TELAJOGO_H

#include "sprites.h"
#include "sorteiaRodada.h"
#include "compararInput.h"

void tocarSomDeInicio(){
  arduboy.setRGBled(0,255,0);
  sound.tone(250, 100);
  arduboy.setRGBled(0,0,0);
  delay(100);
  arduboy.setRGBled(255,0,0);
  sound.tone(300,100);
  arduboy.setRGBled(0,0,0);
  delay(100);
  arduboy.setRGBled(0,255,0);
  sound.tone(450, 100);
  arduboy.setRGBled(0,0,0);
  delay(100);
  arduboy.setRGBled(0,0,255);
  sound.tone(500,100);
  arduboy.setRGBled(0,0,0);
  delay(100);
}

void executandoJogo(){
  if (rodada_atual == 0) {
    tocarSomDeInicio();
    delay(500);
  } 

  unidadePontuacao = (rodada_atual+1) % 10;
  decimalPontuacao = ((rodada_atual+1)/10);
  
  arduboy.clear();
  sprites.drawSelfMasked(0,0,telaJogo,0);
  sprites.drawSelfMasked(110,48,spritesNumeros, frameNumero(decimalPontuacao));
  sprites.drawSelfMasked(120,48,spritesNumeros, frameNumero(unidadePontuacao));
  arduboy.display();
  // Chama a função que inicializa a próxima rodada.
  proximaRodada();
  // Reproduz a sequência atual.
  reproduzirSequencia();
  // Aguarda os botões serem pressionados pelo jogador.
  aguardarJogador();
  // Aguarda 1 segundo entre cada jogada.
  delay(1000);
}

#endif
