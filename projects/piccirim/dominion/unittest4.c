/**************************************
 * Title: gainCard function unit test
 * Author: Mark Piccirilli
 * Date: 2/27/19
 * Description: This is a unit test for the gainCard funtion
 * *******************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

	int numberOfPlayers = 3;
	int kCards[10] = {curse, estate, province, adventurer, feast, gardens, smithy, minion, steward, salvager};
	int seed = 1000;
	struct gameState G, G1, testG1, G2, testG2, G3, testG3;
	int player = 0;
	int toFlag = 0;

	
	printf("TESTING GAINCARD FUNCTION\n");
	printf("\n");

	//test for supply count of 0
	initializeGame(numberOfPlayers,  kCards, seed, &G);
	G.supplyCount[village] = 0;
	if(gainCard(village, &G, 0, toFlag) == -1) {
		printf("PASSED SUPPLY COUNT = 0 TEST: -1 returned\n");
	}
	else {
		printf("FAILED SUPPLY COUNT = 0 TEST: -1 not returned\n");
	}
	printf("\n");

	//toFlag = 0
	toFlag = 0;
	printf("TEST: toFlag = 0\n");
	initializeGame(numberOfPlayers,  kCards, seed, &G1);
	memcpy(&testG1, &G1, sizeof(struct gameState));
	gainCard(minion, &testG1, toFlag, player);
	//dicardCount test
	if(testG1.discardCount[player] == G1.discardCount[player] + 1) {
		printf("PASSED DISCARD COUNT TEST:\nacutal discardCount = %d\nexpected discardCount = %d\n", testG1.discardCount[player], G1.discardCount[player] + 1);
	}
	else {
		printf("FAILED DISCARD COUNT TEST:\nacutal discardCount = %d\nexpected discardCount = %d\n", testG1.discardCount[player], G1.discardCount[player] + 1);
	}
	//discard test
	if(testG1.discard[player][G1.discardCount[player]] == minion) {
		printf("PASSED DISCARD PILE TEST:\ncorrect card in correct position\n");
	}
	else {
		printf("FAILED DISCARD PILE TEST:\ncorrect card not in correct position\n");
	}
	printf("\n");

	//toFlag = 1
	toFlag = 1;
	printf("TEST: toFlag = 1\n");
	initializeGame(numberOfPlayers,  kCards, seed, &G2);
	memcpy(&testG2, &G2, sizeof(struct gameState));
	gainCard(smithy, &testG2, toFlag, player);
	//deckCount test
	if(testG2.deckCount[player] == G2.deckCount[player] + 1) {
		printf("PASSED DECK COUNT TEST:\nacutal deckCount = %d\nexpected deckCount = %d\n", testG2.deckCount[player], G2.deckCount[player] + 1);
	}
	else {
		printf("FAILED DECK COUNT TEST:\nacutal deckCount = %d\nexpected deckCount = %d\n", testG2.deckCount[player], G2.deckCount[player] + 1);
	}
	//deck test
	if(testG2.deck[player][G2.deckCount[player]] == smithy) {
		printf("PASSED DECK TEST:\ncorrect card in correct position\n");
	}
	else {
		printf("FAILED DECK TEST:\ncorrect card not in correct position\n");
	}
	printf("\n");

	//toFlag = 2
	toFlag = 2;
	printf("TEST: toFlag = 2\n");
	initializeGame(numberOfPlayers,  kCards, seed, &G3);
	memcpy(&testG3, &G3, sizeof(struct gameState));
	gainCard(adventurer, &testG3, toFlag, player);
	//handCount test
	if(testG3.handCount[player] == G3.handCount[player] + 1) {
		printf("PASSED HAND COUNT TEST:\nacutal handCount = %d\nexpected handCount = %d\n", testG3.handCount[player], G3.handCount[player] + 1);
	}
	else {
		printf("FAILED HAND COUNT TEST:\nacutal handCount = %d\nexpected handCount = %d\n", testG3.handCount[player], G3.handCount[player] + 1);
	}
	//hand test
	if(testG3.hand[player][G3.handCount[player]] == adventurer) {
		printf("PASSED HAND TEST:\ncorrect card in correct position\n");
	}
	else {
		printf("FAILED HAND TEST:\ncorrect card not in correct position\n");
	}

	printf("\n\n\n");
	return 0;
}
