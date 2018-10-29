/**********************************

cardtest3.c
This tests smithy:
	1. draw 3 card - drawCard()
	2. discardCard()

***********************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main (int argc, char* argv[]) {
	printf("=====start of cardtest3, smithy====== \n");
	struct gameState G, testG;
	int seed = 1000;
	int numPlayers = 2;
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	G.handCount[0] = 1;
	G.handCount[1] = 0;
	G.hand[0][0] = smithy;
	G.numActions = 0;
	G.numBuys = 1;

	int effectResult;
	effectResult = cardEffect(smithy, 0, 0, 0, &testG, 0, 0);

	assert(G.handCount[0] + 3 == testG.handCount[0]);
	
	assert(G.discardCount[0] + 4  == testG.discardCount[0]);
	
	assert(effectResult == 0);

	
	printf("=============passed smithy========== \n");
	return 0;
}