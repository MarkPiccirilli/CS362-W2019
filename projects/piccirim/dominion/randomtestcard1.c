/************************************
 * Title: Random tester village card
 * Author: Mark Piccirilli
 * Date: 2/26/19
 * Description: This is a random test of the village card
 * *********************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <string.h>


int checkVillageCard(struct gameState* G, int handPos, int currentPlayer) {
	//these variables are needed for the cardEffect function, but are not useed by the village card
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	
	struct gameState testG;

	memcpy(&testG, G, sizeof(struct gameState));

	//run cardEffect with input variables
	int testReturn;
	testReturn = cardEffect(village, choice1, choice2, choice3, &testG, handPos, &bonus);

	//create expected cardEffect behavior for village card
	drawCard(currentPlayer, G);
	G->numActions = G->numActions + 2;
	discardCard(handPos, currentPlayer, G, 0);

	if(memcmp(&testG, G, sizeof(struct gameState)) == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {

	int currentPlayer, handpos;
	int numberPassed = 0, numberFailed = 0;
	int n, i;

	struct gameState G;
	
	SelectStream(2);
	PutSeed(3);

	printf("TESTING VILLAGE CARD\n");

	for(n=0; n<2000; n++) {
		//fill struct with random bytes
		for(i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = floor(Random() * 256);
		}
		//set critical variables
		currentPlayer = floor(Random() * MAX_PLAYERS);
		G.whoseTurn = currentPlayer;
		G.numActions = floor(Random() * 3);
		G.deckCount[currentPlayer] = floor(Random() * MAX_DECK);
		G.discardCount[currentPlayer] = floor(Random() * MAX_DECK);
		G.handCount[currentPlayer] = floor(Random() * MAX_HAND);
		handpos = floor(Random() * G.handCount[currentPlayer]);
		G.playedCardCount = floor(Random() * MAX_HAND);


		//run test
		if(checkVillageCard(&G, handpos, currentPlayer) == 0) {
			numberPassed++;
		}
		else {
			numberFailed++;
		}
	}

	printf("Number of tests passed: %d\n", numberPassed);
	printf("Number of tests failed: %d\n", numberFailed);
}
