/**********************************

cardtest4.c
This tests adventure:
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
	printf("=====start of cardtest4, adventure====== \n");
	struct gameState G, testG;
	int seed = 1000;
	int numPlayers = 2;

	G.numActions = 1;
	G.handCount[0] = 1;
	G.hand[0][1] = adventurer;



	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));


	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};


	g.discard[0][0] = copper;
	g.discard[0][1] = copper;
	g.discard[0][2] = copper;
	g.discardCount[0] = 3;
	g.deck[0][0] = duchy;
	g.deck[0][1] = duchy;
	g.deck[0][2] = duchy;
	g.deckCount[0] = 3;
	int coins = g.coins;

	int effectResult;
	effectResult = cardEffect(adventurer, 0, 0, 0, &testG, 0, 0);


	assert(coins + 2 == g.coins);
	
	printf("=============passed adventure========== \n");
	return 0;
}