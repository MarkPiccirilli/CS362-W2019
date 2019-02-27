/************************************
 * Title: Random tester council room card
 * Author: Mark Piccirilli
 * Date: 2/26/19
 * Description: This is a random test of the council room card
 * *********************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <string.h>


int checkCouncilRoomCard(struct gameState* G, int handPos, int currentPlayer) {
	//these variables are needed for the cardEffect function, but are not useed by the council room card
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	
	struct gameState testG;

	memcpy(&testG, G, sizeof(struct gameState));

	//run cardEffect with input variables
	int testReturn;
	testReturn = cardEffect(council_room, choice1, choice2, choice3, &testG, handPos, &bonus);

	//create expected cardEffect behavior for council room card
	//current player draws 4 cards
	int i;
	for(i=0; i < 4; i++) {
		drawCard(currentPlayer, G);
	}
	G->numBuys++; //+1 buy
	//each of the other players draw one card
	for(i=0; i<G->numPlayers; i++) {
		if(i != currentPlayer) {
			drawCard(i, G);
		}
	}
	discardCard(handPos, currentPlayer, G, 0);

	//check to see if the structs are the same
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
	int n, i, p;

	struct gameState G;
	
	SelectStream(2);
	PutSeed(3);

	printf("TESTING COUNCIL ROOM CARD\n");

	for(n=0; n<2000; n++) {
		//fill struct with random bytes
		for(i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = floor(Random() * 256);
		}
		//set critical variables
		G.numPlayers = floor(Random() * MAX_PLAYERS);
		currentPlayer = floor(Random() * G.numPlayers);
		G.whoseTurn = currentPlayer;
		G.numActions = floor(Random() * 3);
		//deck count, discard count, hand count, and handpos must be set for all players since all players can draw cards
		for(p=0; p<=G.numPlayers; p++) {
			G.deckCount[p] = floor(Random() * MAX_DECK);
			G.discardCount[p] = floor(Random() * MAX_DECK);
			G.handCount[p] = floor(Random() * MAX_HAND);
			handpos = floor(Random() * G.handCount[p]);
		}
		G.playedCardCount = floor(Random() * MAX_HAND);

		//run test
		if(checkCouncilRoomCard(&G, handpos, currentPlayer) == 0) {
			numberPassed++;
		}
		else {
			numberFailed++;
		}
	}

	printf("Number of tests passed: %d\n", numberPassed);
	printf("Number of tests failed: %d\n", numberFailed);
}
