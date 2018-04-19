#ifndef SORTEIARODADA_H
#define SORTEIARODADA_H

#include "globais.h"
#include "escolhasCores.h"

// Sorteia um novo item e adiciona na sequência.
void proximaRodada() {
  int numero_sorteado = random(0, 4);
  sequencia[rodada_atual++] = numero_sorteado;
}

void reproduzirSequencia() {
  for (int i = 0; i < rodada_atual; i++) {
        switch(sequencia[i]){
      case 0:
        escolhaVerde();
      break;

      case 1:
        escolhaVermelho();
      break;

      case 2:
        escolhaAzul();
      break;

      case 3:
       escolhaAmarelo();
      break;
    }
    delay(250);
  }
}

#endif
