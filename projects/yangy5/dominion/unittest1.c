/**********************************

unitest1.c
This tests getWinners

***********************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main () {
  printf("=====start of unittest1, getWinners()====== \n");
  struct gameState g;
  int numPlayers = 3;

  initializeGame(numPlayers, k, seed, &g);

  g->hand[0][0] == estate;
  g->hand[1][0] == duchy;
  g->hand[2][0] == province;

  
  int functionReturn;
  functionReturn = getWinners(g.players[numPlayers], g);

  assert(players[2] == 1);
  assert(players[1] == 0);
  assert(players[0] == 0);
  assert(functionReturn == 0);

  printf("=============passed getWinners========== \n");



  return 0;
}
