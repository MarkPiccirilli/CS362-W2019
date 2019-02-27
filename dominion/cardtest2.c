/**************************************
 * Title: smithy function unit test
 * Author: Mark Piccirilli
 * Date: 2/27/19
 * Description: This is a unit test for the smithy card
 * *******************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void smithyCardTests(struct gameState G, struct gameState testG, int currentPlayer) {
	//handCount test
	//3 cards added, one dicarded
	if(G.handCount[currentPlayer] + 2 == testG.handCount[currentPlayer]) {
		printf("HANDCOUNT TEST PASSED\nActual handCount: %d\nExpected handCount %d\n", testG.handCount[currentPlayer], G.handCount[currentPlayer] + 2);
	}
	else {
		printf("HANDCOUNT TEST FAILED\nActual handCount: %d\nExpected handCount %d\n", testG.handCount[currentPlayer], G.handCount[currentPlayer] + 2);
	}
	printf("\n");

	//deckCount test
	//3 cards removed
	if(G.deckCount[currentPlayer] - 3 == testG.deckCount[currentPlayer]) {
		printf("DECKCOUNT TEST PASSED\nActual deckCount: %d\nExpected deckCount %d\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer] - 3);
	}
	else {
		printf("DECKCOUNT TEST FAILED\nActual deckCount: %d\nExpected deckCount %d\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer] - 3);
	}
	printf("\n");

	printf("%d\n", G.deck[currentPlayer][G.deckCount[currentPlayer] - 1]);
	printf("%d\n", G.deck[currentPlayer][G.deckCount[currentPlayer] - 2]);
	printf("%d\n", G.deck[currentPlayer][G.deckCount[currentPlayer] - 3]);
	printf("%d\n", G.deck[currentPlayer][G.deckCount[currentPlayer] - 4]);
	printf("%d\n", testG.hand[currentPlayer][testG.handCount[currentPlayer] - 1]);
	printf("%d\n", testG.hand[currentPlayer][testG.handCount[currentPlayer] - 2]);
	printf("%d\n", testG.hand[currentPlayer][testG.handCount[currentPlayer] - 3]);
	printf("%d\n", testG.hand[currentPlayer][testG.handCount[currentPlayer] - 4]);

	//DECK TO HAND TESTS
	printf("Note: DECK TO HAND tests could be missleading if the same card exists several times in a row in the deck\n");
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
	printf("\n");

	//playedCardCount test
	//one card sould be added to played card count
	if(G.playedCardCount + 1 == testG.playedCardCount) {
		printf("PLAYED CARD COUNT COUNT TEST PASSED:\nactual playedCardCount: %d\nexpected playedCardCount: %d", testG.playedCardCount, G.playedCardCount + 1);
	}
	else {
		printf("PLAYED CARD COUNT COUNT TEST FAILED:\nactual playedCardCount: %d\nexpected playedCardCount: %d", testG.playedCardCount, G.playedCardCount + 1);
	}
	printf("\n");
	printf("\n");
}

//main function
int main() {

	int numberOfPlayers;
	int currentPlayer;
	int kCards[10] = {curse, estate, province, adventurer, feast, gardens, smithy, minion, steward, salvager};
	int seed = 500;
	int choice1 = 0, choice2 = 0, choice3 = 0, handpos = 0, bonus = 0;

	printf("TESTING SMITHY CARD\n");
	printf("\n");

	printf("TEST 1: 4 PLAYERS, CURRENT PLAYER = 0\n\n");
	struct gameState G1, testG1;
	numberOfPlayers = 4;
	currentPlayer = 0;
	initializeGame(numberOfPlayers,  kCards, seed, &G1);
	memcpy(&testG1, &G1, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &testG1, handpos, &bonus);
	smithyCardTests(G1, testG1, currentPlayer);
	printf("\n");

	printf("TEST 2: 2 PLAYERS, CURRENT PLAYER = 0\n\n");
	struct gameState G2, testG2;
	numberOfPlayers = 2;
	currentPlayer = 0;
	initializeGame(numberOfPlayers,  kCards, seed, &G2);
	memcpy(&testG2, &G2, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &testG2, handpos, &bonus);
	smithyCardTests(G2, testG2, currentPlayer);
	printf("\n");

	printf("TEST 3: 2 PLAYERS, CURRENT PLAYER = 1\n\n");
	struct gameState G3, testG3;
	numberOfPlayers = 2;
	currentPlayer = 1;
	initializeGame(numberOfPlayers,  kCards, seed, &G3);
	memcpy(&testG3, &G3, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &testG3, handpos, &bonus);
	smithyCardTests(G3, testG3, currentPlayer);
	printf("\n");

	printf("TEST 4: 1 PLAYERS, CURRENT PLAYER = 0\n\n");
	struct gameState G4, testG4;
	numberOfPlayers = 1;
	currentPlayer = 0;
	initializeGame(numberOfPlayers,  kCards, seed, &G4);
	memcpy(&testG4, &G4, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &testG4, handpos, &bonus);
	smithyCardTests(G4, testG4, currentPlayer);
	printf("\n");

	printf("\n");
	return 0;
}
