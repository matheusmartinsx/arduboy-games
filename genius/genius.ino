#include <Arduboy2.h>
#include <ArduboyTones.h>

#include "globais.h"
#include "sprites.h"
#include "telaInicial.h"
#include "telaJogo.h"
#include "telaGameOver.h"




void setup() {
  arduboy.begin();
  arduboy.clear();
  arduboy.setFrameRate(60);
  sound.volumeMode(VOLUME_ALWAYS_HIGH);
}

void loop() {
  if (!(arduboy.nextFrame())) return;
  arduboy.clear();
  switch(estadoJogo){
    case Inicial:
      telaInicial();
    break;

    case Jogo:
      executandoJogo();
    break;

    case GameOver:
      telaGameOver();
    break;
  }
  arduboy.display();
}
