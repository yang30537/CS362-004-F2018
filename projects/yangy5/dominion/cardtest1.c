/**********************************

cardtest1.c
This tests council_room:
	1. draw 4 card - drawCard()
	2. Add 1 buy - state->numBuys+1
	3. Each player draws a card 
 	4. discardCard()

***********************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "interface.h"




int main (int argc, char* argv[]) {
	printf("=====start of cardtest1, council_room====== \n");
	int k[10] = {copper, minion, mine, silver, gold, cutpurse, sea_hag, tribute, smithy, council_room};
		

	struct gameState G, testG;
	int seed = 1000;
	int numPlayers = 2;
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	G.handCount[0] = 1;
	G.handCount[1] = 0;
	G.hand[0][0] = council_room;
	G.numBuys = 1;
	G.numActions = 0;

	int effectResult;
	effectResult = cardEffect(council_room, 0, 0, 0, &testG, 0, 0);

	assert(G.handCount[0] + 5 == testG.handCount[0]);
	assert(G.handCount[1] + 1 == testG.handCount[1]);
	
	assert(G.discardCount[0] + 6  == testG.discardCount[1]);
	assert(G.discardCount[1] + 1 == testG.discardCount[1]);
	
	assert(effectResult == 0);

	assert(G.numBuys[0] + 1 = testG.numBuys[0]);


	assert(G.discardCount == 1);
	
	printf("=============passed council_room========== \n");
	return 0;
}