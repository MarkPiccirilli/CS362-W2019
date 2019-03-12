/**************************************
 * Title: council room function unit test
 * Author: Mark Piccirilli
 * Date: 2/27/19
 * Description: This is a unit test for the council room card
 * *******************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void councilRoomCardTests(struct gameState G, struct gameState testG, int currentPlayer) {
	//handCount test
	//4 cards added, one dicarded
	if(G.handCount[currentPlayer] + 3 == testG.handCount[currentPlayer]) {
		printf("PASSED HANDCOUNT TEST\nActual handCount: %d\nExpected handCount %d\n", testG.handCount[currentPlayer], G.handCount[currentPlayer] + 3);
	}
	else {
		printf("FAILED HANDCOUNT TEST\nActual handCount: %d\nExpected handCount %d\n", testG.handCount[currentPlayer], G.handCount[currentPlayer] + 3);
	}
	printf("\n");

	//deckCount test
	//deckCount should be decremented by 4
	if(G.deckCount[currentPlayer] - 4 == testG.deckCount[currentPlayer]) {
		printf("PASSED DECKCOUNT TEST\nActual deckCount: %d\nExpected deckCount %d\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer] - 4);
	}
	else {
		printf("FAILED DECKCOUNT TEST\nActual deckCount: %d\nExpected deckCount %d\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer] - 4);
	}
	printf("\n");

	//deck count test and hand count test for all other players
	//each players hand cound should incremented by 1 and their deck count should be decremented by 1
	int i;
	for(i=0; i<G.numPlayers; i++) {
		if(i != currentPlayer) {
	
			//other player handCount test
			//1 card added
			if(G.handCount[i] + 1 == testG.handCount[i]) {
				printf("PASSED OTHER PLAYER HANDCOUNT TEST\nActual handCount: %d\nExpected handCount %d\n", testG.handCount[i], G.handCount[i] + 1);
			}
			else {
				printf("FAILED OTHER PLAYER HANDCOUNT TEST\nActual handCount: %d\nExpected handCount %d\n", testG.handCount[i], G.handCount[i] + 1);
			}
			printf("\n");

			//other player deckCount test
			//deckCount should be decremented by 1
			if(G.deckCount[i] - 1 == testG.deckCount[i]) {
				printf("PASSED OTHER PLAYER DECKCOUNT TEST\nActual deckCount: %d\nExpected deckCount %d\n", testG.deckCount[i], G.deckCount[i] - 1);
			}
			else {
				printf("FAILED OTHER PLAYER DECKCOUNT TEST\nActual deckCount: %d\nExpected deckCount %d\n", testG.deckCount[i], G.deckCount[i] - 1);
			}
			printf("\n");
		}
	} //end for loop
	
	//DECK TO HAND TESTS
	printf("Note: DECK TO HAND tests could be missleading if the same card exists several times in a row in the deck, or if the handpos variable is in the top 4 cards\n");
	if(G.deck[currentPlayer][G.deckCount[currentPlayer] - 1] == testG.hand[currentPlayer][testG.handCount[currentPlayer] - 4]) {
		printf("PASSED DECK TO HAND TEST: first deck card drawn is in correct hand positon");
	}
	else {
		printf("FAILED DECK TO HAND TEST: first deck card drawn in not in correct hand position.");
	}
	printf("\n");

	if(G.deck[currentPlayer][G.deckCount[currentPlayer] - 2] == testG.hand[currentPlayer][testG.handCount[currentPlayer] - 3]) {
		printf("PASSED DECK TO HAND TEST: second deck card drawn is in correct hand positon");
	}
	else {
		printf("FAILED DECK TO HAND TEST: second deck card drawn in not in correct hand position.");
	}
	printf("\n");

	if(G.deck[currentPlayer][G.deckCount[currentPlayer] - 3] == testG.hand[currentPlayer][testG.handCount[currentPlayer] - 2]) {
		printf("PASSED DECK TO HAND TEST: third deck card drawn is in correct hand positon");
	}
	else {
		printf("FAILED DECK TO HAND TEST: third deck card drawn in not in correct hand position.");
	}
	printf("\n");

	if(G.deck[currentPlayer][G.deckCount[currentPlayer] - 4] == testG.hand[currentPlayer][testG.handCount[currentPlayer] - 1]) {
		printf("PASSED DECK TO HAND TEST: fourth deck card drawn is in correct hand positon");
	}
	else {
		printf("FAILED DECK TO HAND TEST: fourth deck card drawn in not in correct hand position.");
	}
	printf("\n");
	printf("\n");
	
	//numBuys test
	//numBuys should be increased by two
	if(G.numBuys + 1 == testG.numBuys) {
		printf("PASSED NUM BUYS TEST:\nactual numBuys: %d\nexpected numBuys: %d\n", testG.numBuys, G.numBuys + 1);
	}
	else {
		printf("FAILED NUM BUYS TEST:\nactual numBuys: %d\nexpected numBuys: %d\n", testG.numBuys, G.numBuys + 1);
	}
	printf("\n");
	
	//playedCardCount test
	//one card sould be added to played card count because of dicard
	if(G.playedCardCount + 1 == testG.playedCardCount) {
		printf("PASSED PLAYED CARD COUNT COUNT TEST:\nactual playedCardCount: %d\nexpected playedCardCount: %d", testG.playedCardCount, G.playedCardCount + 1);
	}
	else {
		printf("FAILED PLAYED CARD COUNT COUNT TEST:\nactual playedCardCount: %d\nexpected playedCardCount: %d", testG.playedCardCount, G.playedCardCount + 1);
	}
	printf("\n");
	printf("\n");
}

int main() {
	int numberOfPlayers;
	int currentPlayer;
	int kCards[10] = {curse, estate, province, adventurer, feast, gardens, smithy, minion, steward, salvager};
	int seed = 500;
	int choice1 = 0, choice2 = 0, choice3 = 0, handpos = 0, bonus = 0;

	printf("TESTING COUNCIL ROOM CARD\n");
	printf("\n");

	printf("TEST 1: 4 PLAYERS, CURRENT PLAYER = 0\n\n");
	struct gameState G1, testG1;
	numberOfPlayers = 4;
	currentPlayer = 0;
	initializeGame(numberOfPlayers,  kCards, seed, &G1);
	G1.whoseTurn = currentPlayer;
	memcpy(&testG1, &G1, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testG1, handpos, &bonus);
	councilRoomCardTests(G1, testG1, currentPlayer);
	printf("\n");

	printf("TEST 2: 2 PLAYERS, CURRENT PLAYER = 0\n\n");
	struct gameState G2, testG2;
	numberOfPlayers = 2;
	currentPlayer = 0;
	initializeGame(numberOfPlayers,  kCards, seed, &G2);
	G2.whoseTurn = currentPlayer;
	memcpy(&testG2, &G2, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testG2, handpos, &bonus);
	councilRoomCardTests(G2, testG2, currentPlayer);
	printf("\n");

	printf("TEST 3: 2 PLAYERS, CURRENT PLAYER = 1\n\n");
	struct gameState G3, testG3;
	numberOfPlayers = 2;
	currentPlayer = 1;
	initializeGame(numberOfPlayers,  kCards, seed, &G3);
	G3.whoseTurn = currentPlayer;
	memcpy(&testG3, &G3, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testG3, handpos, &bonus);
	councilRoomCardTests(G3, testG3, currentPlayer);
	printf("\n");

	printf("TEST 4: 3 PLAYERS, CURRENT PLAYER = 1\n\n");
	struct gameState G4, testG4;
	numberOfPlayers = 3;
	currentPlayer = 1;
	initializeGame(numberOfPlayers,  kCards, seed, &G4);
	G4.whoseTurn = currentPlayer;
	memcpy(&testG4, &G4, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testG4, handpos, &bonus);
	councilRoomCardTests(G4, testG4, currentPlayer);
	printf("\n");

	printf("\n");

	return 0;
}
