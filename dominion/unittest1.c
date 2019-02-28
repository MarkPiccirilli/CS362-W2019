/**************************************
 * Title: shuffle function unit test
 * Author: Mark Piccirilli
 * Date: 2/9/19
 * Description: This is a unit test for the shuffle funtion
 * *******************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

	int numberOfPlayers = 3, numberOfPlayersOne = 1;
	int kCards[10] = {curse, estate, province, adventurer, feast, gardens, smithy, minion, steward, salvager};
	int seed = 1000;
	struct gameState G, testG, G1;
	int i, j; //counters

	initializeGame(numberOfPlayers,  kCards, seed, &G);

	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("TESTING SHUFFLE FUNCTION\n");
	printf("\n");

	//suffle the player decks
	for(i=0; i<numberOfPlayers; i++) {
		shuffle(i, &testG);
	}

	//check that the new deck count is correct
	for(i=0; i<numberOfPlayers; i++) {
		if(testG.deckCount[i] == G.deckCount[i]) {
			printf("PASSED DECK COUNT TEST: expected count: %d, actual count: %d\n", G.deckCount[i], testG.deckCount[i]);
		}	
		else {
			printf("FAILED DECK COUNT TEST: expected count: %d, actual count: %d\n", G.deckCount[i], testG.deckCount[i]);
		}
	}
	printf("\n");

	//check that the cards have been reordered
	printf("Note: if radomization test fails it may not necessarily mean that the function is bad.  See specific data information to make analysis.\n");
	for(i=0; i<numberOfPlayers; i++) {
		int failCount = 0; //for testing if the cards have been sufficently reordered
		for(j=0; j<G.deckCount[i]; j++) {
			if(G.deck[i][j] == testG.deck[i][j]) {
				failCount++;
			}
		}
		if(failCount >= G.deckCount[i]/2) {
			printf("FAILED RANDOMIZATION TEST: cards may not sufficiently randomized\n");
		}
		else {
			printf("PASSED RANDOMIZATION TEST: cards were sufficiently randomized\n");
		}
		printf("failCount: %d\n", failCount);
		printf("deckCount: %d\n", G.deckCount[i]);
	}
	printf("\n");

	//test deckCount < 1
	initializeGame(numberOfPlayersOne,  kCards, seed, &G1);
	G.deckCount[0] = 0;
	if(shuffle(0, &G1) == -1) {
		printf("PASSED DECKCOUNT < 1 TEST\n");
	}
	else {
		printf("FAILED DECKCOUNT < 1 TEST\n");
	}

	printf("\n\n\n");

	return 0;
}
