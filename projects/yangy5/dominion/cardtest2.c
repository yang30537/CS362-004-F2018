/**********************************

cardtest2.c
This tests village:
	1. draw 1 card - drawCard()
	2. Add 2 actions- state->numActions+2
	3. discardCard()

***********************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main (int argc, char* argv[]) {
	printf("=====start of cardtest2, council====== \n");
	struct gameState G, testG;
	int seed = 1000;
	int numPlayers = 2;
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	G.handCount[0] = 1;
	G.handCount[1] = 0;
	G.hand[0][0] = village;
	G.numActions = 0;
	G.numBuys = 1;

	int effectResult;
	effectResult = cardEffect(village, 0, 0, 0, &testG, 0, 0);

	assert(G.handCount[0] + 1 == testG.handCount[0]);
	
	assert(G.discardCount[0] + 2  == testG.discardCount[0]);

	assert(G.numActions[0] + 2  == testG.numActions[0]);
	
	assert(effectResult == 0);

	
	printf("=============passed village========== \n");
	return 0;
}

