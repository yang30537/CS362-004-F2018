/**********************************

unitest1.c
This tests gainCard

***********************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main () {
  printf("=====start of unittest2, gainCard====== \n");

  int i, j, k;
  struct gameState g, testG;
  int numPlayers = 2;

  initializeGame(numPlayers, k, seed, &G);
  
  i = gainCard(adventurer, g, 0, g.players[0]);
  assert(g.discardCount[g.players[0]] == 1);
  assert(g.discard[g.players[0]][g.discardCount[g.players[0]]] == adventurer);
  assert(g->supplyCount[adventurer] == testG->supplyCount[adventurer]--);

  j = gainCard(estate, g, 1, g.players[0]);
  assert(g.deckCount[g.players] == 1);
  assert(g.deck[g.players[0]][g->deckCount[players[0]]] == estate);
  assert(g->supplyCount[estate] == testG->supplyCount[estate]--);

  k = gainCard(outpost, g, 2, g.players[0]);
  assert(g.handCount[g.players[0]] == 1);
  assert(g.deck[g.players[0]][g.deckCount[players[0]]] == outpost);
  assert(g->supplyCount[outpost] == testG->supplyCount[outpost]--);




  printf("=============passed gainCard========== \n");



  return 0;
}
