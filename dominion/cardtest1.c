/**************************************
 * Title: adventurer function unit test
 * Author: Mark Piccirilli
 * Date: 2/10/19
 * Description: This is a unit test for the adventurer card
 * *******************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

	int numberOfPlayers = 2;
	int currentPlayer = 0;
	int kCards[10] = {curse, estate, province, adventurer, feast, gardens, smithy, minion, steward, salvager};
	int seed = 1000;
	struct gameState G, testG;
	int i; //counters
	int choice1 = 0, choice2 = 0, choice3 = 0, handpos = 0, bonus = 0;
	int numTreasureBefore = 0;
	int numTreasureAfter = 0;


	initializeGame(numberOfPlayers,  kCards, seed, &G);

	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("TESTING ADVENTURER CARD\n");
	printf("\n");

	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

	for(i = 0; i<G.deckCount[currentPlayer]; i++) {
		if(G.deck[currentPlayer][i] == copper || testG.deck[currentPlayer][i] == silver || testG.deck[currentPlayer][i] == gold) {
			numTreasureBefore++;
		}
	}

	for(i = 0; i<testG.deckCount[currentPlayer]; i++) {
		if(testG.deck[currentPlayer][i] == copper || testG.deck[currentPlayer][i] == silver || testG.deck[currentPlayer][i] == gold) {
			numTreasureAfter++;
		}
	}

	if(numTreasureBefore + 2 == numTreasureAfter) {
		printf("TREASURE CARD TEST PASSED\nActual number of treasure cards: %d\nExpected number of treasure cards: %d\n", numTreasureBefore + 2, numTreasureAfter);
	}
	else {
		printf("TREASURE CARD TEST FAILED\nActual number of treasure cards: %d\nExpected number of treasure cards: %d\n", numTreasureBefore + 2, numTreasureAfter);
	}

	printf("\n");

	return 0;
}
