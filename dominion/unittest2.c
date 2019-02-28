/**************************************
 * Title: discardCard function unit test
 * Author: Mark Piccirilli
 * Date: 2/27/19
 * Description: This is a unit test for the discardCard funtion
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
	struct gameState G, testG, G1, testG1, G2, testG2;
	int i; //counter
	int trashFlagZero = 0, trashFlagOne = 1;
	int handPos[numberOfPlayers];

	initializeGame(numberOfPlayers,  kCards, seed, &G);

	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("TESTING DISCARDCARD FUNCTION\n");
	printf("\n");

	handPos[0] = G.handCount[0] - 1; //last card in array
	handPos[1] = G.handCount[1]/2; //middle of array
	handPos[2] = 0; //first card in array

	for(i=0; i<numberOfPlayers; i++) {
		discardCard(handPos[i], i, &testG, trashFlagZero);
	}

	//playedCardCount test
	if(G.playedCardCount + 3 == testG.playedCardCount) {
		printf("PASSED PLAYED CARD COUNT TEST 1:\nactual playedCardCount = %d\nexpected playedCardCount = %d\n", testG.playedCardCount, G.playedCardCount + 3);
	}
	else {
		printf("FAILED PLAYED CARD COUNT TEST 1:\nactual playedCardCount = %d\nexpected playedCardCount = %d\n", testG.playedCardCount, G.playedCardCount + 3);
	}
	printf("\n");

	//playedCardCount test 2, where testFlag == 1
	initializeGame(numberOfPlayers,  kCards, seed, &G1);
	memcpy(&testG1, &G1, sizeof(struct gameState));
	for(i=0; i<numberOfPlayers; i++) {
		discardCard(handPos[i], i, &testG1, trashFlagOne);
	}
	if(G1.playedCardCount == testG1.playedCardCount) {
		printf("PASSED PLAYED CARD COUNT TEST 2:\nactual playedCardCount = %d\nexpected playedCardCount = %d\n", testG1.playedCardCount, G1.playedCardCount);
	}
	else {
		printf("FAILED PLAYED CARD COUNT TEST 2:\nactual playedCardCount = %d\nexpected playedCardCount = %d\n", testG1.playedCardCount, G1.playedCardCount);
	}
	printf("\n");

	//handCount test
	for(i=0; i<numberOfPlayers; i++) {
		if(G.handCount[i] - 1 == testG.handCount[i]) {
			printf("PASSED HAND COUNT TEST FOR PLAYER %d:\nactual handCount = %d\nexpected handCount = %d\n", i, testG.handCount[i], G.handCount[i] - 1);
		}
		else {
			printf("FAILED HAND COUNT TEST FOR PLAYER %d:\nactual handCount = %d\nexpected handCount = %d\n", i, testG.handCount[i], G.handCount[i] - 1);
		}
	}
	printf("\n");

	//card removal test
	for(i=0; i<numberOfPlayers; i++) {
		if(testG.hand[i][G.handCount[i] - 1] == -1) {
			printf("PASSED CARD REMOVAL TEST FOR PLAYER %d\n", i);
		}
		else {
			printf("FAILED CARD REMOVAL TEST FOR PLAYER %d\n", i);
		}
	}
	printf("\n");

	//card substitution test
	for(i=1; i<numberOfPlayers; i++) {
		if(testG.hand[i][handPos[i]] == G.hand[i][G.handCount[i] - 1]) {
			printf("PASSED CARD SUBSTITUTION TEST FOR PLAYER %d\n", i);
		}
		else {
			printf("FAILED CARD SUBSTITUTION TEST FOR PLAYER %d\n", i);
		}
	}
	printf("\n");

	//handCount == 1 test
	initializeGame(numberOfPlayersOne,  kCards, seed, &G2);
	G2.handCount[0] = 1;
	memcpy(&testG2, &G2, sizeof(struct gameState));
	discardCard(handPos[0], 0, &testG2, trashFlagOne);
	if(testG2.handCount[0] == 0) {
		printf("PASSED ONE CARD HAND TEST\n");
	}
	else {
		printf("FAILED ONE CARD HAND TEST\n");
	}
	printf("\n");
	printf("\n");
	printf("\n");
}
