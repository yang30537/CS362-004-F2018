#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#include "interface.h"


int main() {
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
	printf ("Starting adventurer random test.\n");

	int i, j, n;

	int numPlayers = 2;
	int curPlayer = 0;
	int seed = 1000;
	int money, actualMoney;

	int failedTestCount = 0;
	int passTestCount = 0;

	int copperCount, silverCount, goldCount;

	for (i = 0; i < 200000; i++) {
	    
	    initializeGame(numPlayers, k, seed, &G);

	    // init both players 
	    G.deckCount[0] = 0;
	    G.discardCount[0] = 0;
	    G.handCount[0] = 0;

		copperCount = 0;
		silverCount = 0;
		goldCount = 0;

		money = 0;
		actualMoney = 0;

		// fill deck with random cards
		
		for (n = 0; n < 50; n++) {
	    	int randNum, randCard;
	    	randNum = rand() % 10;
	    	randCard = rand() % 10;
	    	if(randNum == 1){
            	G.deck[curPlayer][n] = copper;
            } else if(randNum == 2){
                G.deck[curPlayer][n] = silver;
            } else if(randNum == 3){
                G.deck[curPlayer][n] = gold;
            } else {
                G.deck[curPlayer][n] = k[randCard];
            }
	    }

	    // call adventure card effect function,
	    adventurerEffect(&G, curPlayer, G.hand[curPlayer]); 

	    // get number of each treasure cards drawn
	    for (j = 0; j < G.handCount[curPlayer]; j++) {
	    	if (G.hand[curPlayer][j] == copper) {
	    		copperCount++;
	    		money += COPPER_VALUE;
	    	} 
	    	if (G.hand[curPlayer][j] == gold) {
	    		goldCount++;
	    		money += SILVER_VALUE;
	    	}
	    	if (G.hand[curPlayer][j] == silver) {
	    		silverCount++;
	    		money += GOLD_VALUE;
	    	}
	    }

	    actualMoney = countHandCoins(curPlayer, &G);
	    if (money != actualMoney) {
	    	failedTestCount++;
	    }

	    int discardCopper = 0;
        int discardSilver = 0;
        int discardGold = 0;

        int totalCoinsCount = goldCount + copperCount + silverCount;

	    // get the actual discard cards
        for (j = 0; j < G.discardCount[curPlayer]; j++) {
	    	if (G.hand[curPlayer][j] == copper) {
	    		discardCopper++;
	    	} 
	    	if (G.hand[curPlayer][j] == gold) {
	    		discardGold++;
	    	}
	    	if (G.hand[curPlayer][j] == silver) {
	    		discardSilver++;
	    	}
	    }

	    // check the discard cards 
	    // if any of the quantity fails to match, test fails
	    if (discardCopper != copperCount) {
	    	failedTestCount++;
	    }
	    if (discardGold != goldCount) {
	    	failedTestCount++;
	    }
	    if (discardSilver != silverCount) {
	    	failedTestCount++;
	    }

	    printf("%d\n", totalCoinsCount);
	    
	    // if no fails, this test passes
	    if (failedTestCount == 0) {
	    	passTestCount++;
	    }

	}
	printf("after (%d) tests, number of passed tests is: (%d) \n", i, passTestCount);
	return 0;
}

