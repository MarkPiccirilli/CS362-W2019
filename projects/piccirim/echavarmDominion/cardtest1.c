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

void adventurerCardTests(struct gameState G, struct gameState testG, int currentPlayer) {

	int i; //counters
	int numTreasureDeckBefore = 0, numTreasureDeckAfter = 0;
	int numTreasureHandBefore = 0, numTreasureHandAfter = 0;

	//number treasure cards removed from deck
	for(i = 0; i<G.deckCount[currentPlayer]; i++) {
		if(G.deck[currentPlayer][i] == copper || testG.deck[currentPlayer][i] == silver || testG.deck[currentPlayer][i] == gold) {
			numTreasureDeckBefore++;
		}
	}

	for(i = 0; i<testG.deckCount[currentPlayer]; i++) {
		if(testG.deck[currentPlayer][i] == copper || testG.deck[currentPlayer][i] == silver || testG.deck[currentPlayer][i] == gold) {
			numTreasureDeckAfter++;
		}
	}

	if(numTreasureDeckBefore - 2 == numTreasureDeckAfter) {
		printf("PASSED TREASURE CARDS IN DECK TEST\nActual number of treasure cards: %d\nExpected number of treasure cards: %d\n", numTreasureDeckBefore - 2, numTreasureDeckAfter);
	}
	else {
		printf("FAILED TREASURE CARDS IN DECK TEST\nActual number of treasure cards: %d\nExpected number of treasure cards: %d\n", numTreasureDeckBefore - 2, numTreasureDeckAfter);
	}

	printf("\n");
	
	//number treasure cards added to hand
	for(i = 0; i<G.handCount[currentPlayer]; i++) {
		if(G.hand[currentPlayer][i] == copper || testG.hand[currentPlayer][i] == silver || testG.hand[currentPlayer][i] == gold) {
			numTreasureHandBefore++;
		}
	}

	for(i = 0; i<testG.handCount[currentPlayer]; i++) {
		if(testG.hand[currentPlayer][i] == copper || testG.hand[currentPlayer][i] == silver || testG.hand[currentPlayer][i] == gold) {
			numTreasureHandAfter++;
		}
	}

	if(numTreasureHandBefore + 2 == numTreasureHandAfter) {
		printf("PASSED TREASURE CARDS IN HAND TEST\nActual number of treasure cards: %d\nExpected number of treasure cards: %d\n", numTreasureHandBefore + 2, numTreasureHandAfter);
	}
	else {
		printf("FAILED TREASURE CARDS IN HAND TEST\nActual number of treasure cards: %d\nExpected number of treasure cards: %d\n", numTreasureHandBefore + 2, numTreasureHandAfter);
	}

	printf("\n");

	//handCount test
	if(G.handCount[currentPlayer] + 2 == testG.handCount[currentPlayer]) {
		printf("PASSED HANDCOUNT TEST\nActual handCount: %d\nExpected handCount %d\n", testG.handCount[currentPlayer], G.handCount[currentPlayer] + 2);
	}
	else {
		printf("FAILED HANDCOUNT TEST\nActual handCount: %d\nExpected handCount %d\n", testG.handCount[currentPlayer], G.handCount[currentPlayer] + 2);
	}
	printf("\n");

	//discardCount test
	if(G.discardCount[currentPlayer] <= testG.discardCount[currentPlayer]) {
		printf("PASSED DISCARDCOUNT TEST\nInitial discardCount: %d\nAfter discardCount %d\n", G.discardCount[currentPlayer], testG.discardCount[currentPlayer]);
	}
	else {
		printf("FAILED DISCARDCOUNT TEST\nInitial discardCount: %d\nAfter discardCount %d\n", G.discardCount[currentPlayer], testG.discardCount[currentPlayer]);
	}
	printf("\n");
	
	//deckCount test
	if(G.deckCount[currentPlayer] - 2 >= testG.deckCount[currentPlayer]) {
		printf("PASSED DECKCOUNT TEST\nInitial deckCount: %d\nAfter deckCount %d\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer] - 2);
	}
	else {
		printf("FAILED DECKCOUNT TEST\nInitial deckCount: %d\nAfter deckCount %d\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer] - 2);
	}
	printf("\n");

	//differnce discard deckout test
	if(G.deckCount[currentPlayer] - 2 - testG.discardCount[currentPlayer] != testG.discardCount[currentPlayer] - G.discardCount[currentPlayer]) {
		printf("PASSED discardCount vs deckCount comparison test, see discardCount and deckCount data above\n");
	}
	else {
		printf("FAILED discardCount vs deckCount comparison test, see discardCount and deckCount data above\n");
	}
}

int main() {

	int numberOfPlayers;
	int currentPlayer;
	int kCards[10] = {curse, estate, province, adventurer, feast, gardens, smithy, minion, steward, salvager};
	int seed = 1000;
	int choice1 = 0, choice2 = 0, choice3 = 0, handpos = 0, bonus = 0;

	printf("TESTING ADVENTURER CARD\n");
	printf("\n");

	printf("TEST 1: 4 PLAYERS, CURRENT PLAYER = 0\n\n");
	struct gameState G1, testG1;
	numberOfPlayers = 4;
	currentPlayer = 0;
	initializeGame(numberOfPlayers,  kCards, seed, &G1);
	G1.whoseTurn = currentPlayer;
	memcpy(&testG1, &G1, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG1, handpos, &bonus);
	adventurerCardTests(G1, testG1, currentPlayer);
	printf("\n");

	printf("TEST 2: 2 PLAYERS, CURRENT PLAYER = 1\n");
	struct gameState G2, testG2;
	numberOfPlayers = 2;
	currentPlayer = 1;
	initializeGame(numberOfPlayers,  kCards, seed, &G2);
	G2.whoseTurn = currentPlayer;
	memcpy(&testG2, &G2, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG2, handpos, &bonus);
	adventurerCardTests(G2, testG2, currentPlayer);
	printf("\n");

	printf("TEST 3: 4 PLAYERS, CURRENT PLAYER = 2\n");
	struct gameState G3, testG3;
	numberOfPlayers = 4;
	currentPlayer = 2;
	initializeGame(numberOfPlayers,  kCards, seed, &G3);
	G3.whoseTurn = currentPlayer;
	memcpy(&testG3, &G3, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG3, handpos, &bonus);
	adventurerCardTests(G3, testG3, currentPlayer);
	printf("\n");


	printf("TEST 4: 3 PLAYERS, CURRENT PLAYER = 0\n");
	struct gameState G4, testG4;
	numberOfPlayers = 3;
	currentPlayer = 0;
	initializeGame(numberOfPlayers,  kCards, seed, &G4);
	G4.whoseTurn = currentPlayer;
	memcpy(&testG4, &G4, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG4, handpos, &bonus);
	adventurerCardTests(G4, testG4, currentPlayer);
	printf("\n");

	printf("TEST 5: 2 PLAYERS, CURRENT PLAYER = 0\n");
	struct gameState G5, testG5;
	numberOfPlayers = 2;
	currentPlayer = 0;
	initializeGame(numberOfPlayers,  kCards, seed, &G5);
	G5.whoseTurn = currentPlayer;
	G5.deckCount[currentPlayer] = MAX_DECK;
	int i;
	for(i=0; i<G5.deckCount[currentPlayer]; i++) {
		G5.deck[currentPlayer][i] = village;
	}
	memcpy(&testG5, &G5, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG5, handpos, &bonus);
	adventurerCardTests(G5, testG5, currentPlayer);

	printf("\n");
	printf("\n");
	printf("\n");
	return 0;
}