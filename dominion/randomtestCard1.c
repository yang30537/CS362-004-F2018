
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "interface.h"

int main() {
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
	printf ("Starting card1 random test.\n");


	int i, j, p, n;
	int money, moneyActual;
	int adventurerPos = -1;
	int numPlayers = 2;
	int curPlayer = 0;
	int seed = 1000;
	
	int deckCount, handCount;

	int failedTestCount = 0;
	int passTestCount = 0;

	int copperCount, silverCount, goldCount;

	for (i = 0; i < 2000; i++) {
	    initializeGame(numPlayers, k, seed, &G);
		
		// TODO: 

	}
	return 0;
}