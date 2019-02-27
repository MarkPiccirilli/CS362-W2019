/**************************************
 * Title: council room function unit test
 * Author: Mark Piccirilli
 * Date: 2/27/19
 * Description: This is a unit test for the village card
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
		printf("HANDCOUNT TEST PASSED\nActual handCount: %d\nExpected handCount %d\n", testG.handCount[currentPlayer], G.handCount[currentPlayer] + 3);
	}
	else {
		printf("HANDCOUNT TEST FAILED\nActual handCount: %d\nExpected handCount %d\n", testG.handCount[currentPlayer], G.handCount[currentPlayer] + 3);
	}
	printf("\n");

	//deckCount test
	//deckCount should be decremented by 4
	if(G.deckCount[currentPlayer] - 4 >= testG.deckCount[currentPlayer]) {
		printf("DECKCOUNT TEST PASSED\nActual deckCount: %d\nExpected deckCount %d\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer] - 4);
	}
	else {
		printf("DECKCOUNT TEST FAILED\nActual deckCount: %d\nExpected deckCount %d\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer] - 4);
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
				printf("OTHER PLAYER HANDCOUNT TEST PASSED\nActual handCount: %d\nExpected handCount %d\n", testG.handCount[i], G.handCount[i] + 1);
			}
			else {
				printf("OTHER PLAYER HANDCOUNT TEST FAILED\nActual handCount: %d\nExpected handCount %d\n", testG.handCount[i], G.handCount[i] + 1);
			}
			printf("\n");

			//other player deckCount test
			//deckCount should be decremented by 1
			if(G.deckCount[i] - 4 >= testG.deckCount[i]) {
				printf("OTHER PLAYER DECKCOUNT TEST PASSED\nActual deckCount: %d\nExpected deckCount %d\n", testG.deckCount[i], G.deckCount[i] - 1);
			}
			else {
				printf("OTHER PLAYER DECKCOUNT TEST FAILED\nActual deckCount: %d\nExpected deckCount %d\n", testG.deckCount[i], G.deckCount[i] - 1);
			}
			printf("\n");
		}
	} //end for loop
	
	//DECK TO HAND TESTS
	printf("Note: DECK TO HAND tests could be missleading if the same card exists several times in a row in the deck, or if the handpos variable is in the top 4 cards\n");
	if(G.deck[currentPlayer][G.deckCount[currentPlayer] - 1] == testG.hand[currentPlayer][testG.handCount[currentPlayer] - 4]) {
		printf("DECK TO HAND TEST PASSED: first deck card drawn is in correct hand positon");
	}
	else {
		printf("DECK TO HAND TEST FAILED: first deck card drawn in not in correct hand position.");
	}
	printf("\n");

	if(G.deck[currentPlayer][G.deckCount[currentPlayer] - 2] == testG.hand[currentPlayer][testG.handCount[currentPlayer] - 3]) {
		printf("DECK TO HAND TEST PASSED: second deck card drawn is in correct hand positon");
	}
	else {
		printf("DECK TO HAND TEST FAILED: second deck card drawn in not in correct hand position.");
	}
	printf("\n");

	if(G.deck[currentPlayer][G.deckCount[currentPlayer] - 3] == testG.hand[currentPlayer][testG.handCount[currentPlayer] - 2]) {
		printf("DECK TO HAND TEST PASSED: third deck card drawn is in correct hand positon");
	}
	else {
		printf("DECK TO HAND TEST FAILED: third deck card drawn in not in correct hand position.");
	}
	printf("\n");

	if(G.deck[currentPlayer][G.deckCount[currentPlayer] - 4] == testG.hand[currentPlayer][testG.handCount[currentPlayer] - 1]) {
		printf("DECK TO HAND TEST PASSED: fourth deck card drawn is in correct hand positon");
	}
	else {
		printf("DECK TO HAND TEST FAILED: fourth deck card drawn in not in correct hand position.");
	}
	printf("\n");
	printf("\n");
	
	//numBuys test
	//numBuys should be increased by two
	if(G.numBuys + 1 == testG.numBuys) {
		printf("NUM BUYS TEST PASSED:\nactual numBuys: %d\nexpected numBuys: %d\n", testG.numBuys, G.numBuys + 1);
	}
	else {
		printf("NUM BUYS TEST FAILED:\nactual numBuys: %d\nexpected numBuys: %d\n", testG.numBuys, G.numBuys + 1);
	}
	printf("\n");
	
	//playedCardCount test
	//one card sould be added to played card count because of dicard
	if(G.playedCardCount + 1 == testG.playedCardCount) {
		printf("PLAYED CARD COUNT COUNT TEST PASSED:\nactual playedCardCount: %d\nexpected playedCardCount: %d", testG.playedCardCount, G.playedCardCount + 1);
	}
	else {
		printf("PLAYED CARD COUNT COUNT TEST FAILED:\nactual playedCardCount: %d\nexpected playedCardCount: %d", testG.playedCardCount, G.playedCardCount + 1);
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
	memcpy(&testG1, &G1, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testG1, handpos, &bonus);
	councilRoomCardTests(G1, testG1, currentPlayer);
	printf("\n");

	printf("TEST 2: 2 PLAYERS, CURRENT PLAYER = 0\n\n");
	struct gameState G2, testG2;
	numberOfPlayers = 2;
	currentPlayer = 0;
	initializeGame(numberOfPlayers,  kCards, seed, &G2);
	memcpy(&testG2, &G2, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testG2, handpos, &bonus);
	councilRoomCardTests(G2, testG2, currentPlayer);
	printf("\n");

	printf("TEST 3: 2 PLAYERS, CURRENT PLAYER = 1\n\n");
	struct gameState G3, testG3;
	numberOfPlayers = 2;
	currentPlayer = 1;
	initializeGame(numberOfPlayers,  kCards, seed, &G3);
	memcpy(&testG3, &G3, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testG3, handpos, &bonus);
	councilRoomCardTests(G3, testG3, currentPlayer);
	printf("\n");

	printf("TEST 4: 1 PLAYERS, CURRENT PLAYER = 0\n\n");
	struct gameState G4, testG4;
	numberOfPlayers = 1;
	currentPlayer = 0;
	initializeGame(numberOfPlayers,  kCards, seed, &G4);
	memcpy(&testG4, &G4, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testG4, handpos, &bonus);
	councilRoomCardTests(G4, testG4, currentPlayer);
	printf("\n");

	printf("\n");

	return 0;
}
