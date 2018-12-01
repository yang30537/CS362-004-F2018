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

	//ADDED
	srand(time(NULL));

	struct gameState *G;
	
	printf ("Starting adventurer random test.\n");

	int i, j, n, z;

	int numPlayers;
	int curPlayer;
	int seed;
	
	int coinCount;
	int failedTestCount;

	int copperCount, silverCount, goldCount;
	int discardCopper;
    int discardSilver;
    int discardGold;



    failedTestCount = 0;


	for (i = 0; i < 1000; i++) {
	    int k[10] = {adventurer, council_room, cutpurse, embargo, mine,
                         minion, sea_hag, smithy, tribute, village};

        numPlayers = 2;
		curPlayer = 0;

		
		seed = rand();

        G = malloc(sizeof(struct gameState));
	    initializeGame(numPlayers, k, seed, G);

	    // init  
	    G->deckCount[0] = 100;
	    G->handCount[0] = 100;
	    G->discardCount[0] = 100;

		copperCount = 0;
		silverCount = 0;
		goldCount = 0;
		
		coinCount = 0;

		discardCopper = 0;
	    discardSilver = 0;
	    discardGold = 0;


	    // fill deck with random cards, only add treasure cards to deck
		int randNum, randCard;
		for (n = 0; n < 100; n++) {
	    	randNum = rand() % 10;
	    	randCard = rand() % 10;
	    	if(randNum == 0){
            	G->deck[0][n] = copper;
				coinCount++;
            } else if(randNum == 1){
                G->deck[0][n] = silver;
                coinCount++;
            } else if(randNum == 2){
                G->deck[0][n] = gold;
                coinCount++;
            } else {
                G->deck[0][n] = k[randCard];
            }
	    } 

	    if (coinCount < 2) {
	    	failedTestCount++;
            i = i - 1;
            G->deckCount[0] = 100;
		    G->handCount[0] = 0;
		    G->discardCount[0] = 0;
            free(G);
            continue;
	    }


	    cardAdventurer(G, curPlayer);

 

	    // get number of each treasure cards drawn
	    for (j = 0; j < G->handCount[0]; j++) {
	    	if (G->hand[0][j] == copper) {
	    		copperCount++;
	    	} 
	    	if (G->hand[0][j] == gold) {
	    		goldCount++;
	    	}
	    	if (G->hand[0][j] == silver) {
	    		silverCount++;
	    	}
	    }


	    // get the actual discard cards
        for (z = 0; z < G->discardCount[0]; z++) {
	    	
	    	if (G->discard[0][z] == copper) {
	    		discardCopper++;
	    	} 

	    	if (G->discard[0][z] == gold) {
	    		discardGold++;
	    	}

	    	if (G->discard[0][z] == silver) {
	    		discardSilver++;
	    	}

	    }

     
	    // check the discard cards 
	    // if any of the quantity fails to match, test fails
	    if (discardCopper != copperCount || discardGold != goldCount || discardSilver != silverCount) {
	    	failedTestCount++;
	    }

	    printf("silverHand: %d, copperHand: %d, goldHand: %d\n", copperCount, goldCount, silverCount);
	    printf("silverDiscard: %d, copper1: %d, goldDiscard: %d\n\n", discardCopper, discardGold, discardSilver);

	    G->deckCount[0] = 0;
	    G->handCount[0] = 0;
	    G->discardCount[0] = 0;

	    free(G);
	}
	//free(G);
	printf("after (%d) tests, number of failed tests is: (%d) \n", i, failedTestCount);
	return 0;
}

