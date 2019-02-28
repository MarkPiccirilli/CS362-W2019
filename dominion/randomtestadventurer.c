/*****************************************
 * Title: Random Test adventurer card
 * Author: Mark Piccirilli
 * Date: 2/26/19
 * Description: This program performs random testing on the adventure card
 * **************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "stdlib.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <bits/sigaction.h>

void catch_SIGSEGV() {
	printf("Segmintaion Fault");
}

int checkAdventurerCard(struct gameState* G, int currentPlayer, int handPos) {
	//these variables are needed for the cardEffect function, but are not useed by the village card
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	
	struct gameState testG;
	int topCard, topIndex;
	int treasure = 0;

	//set up sigaction struct to catch segfault
	struct sigaction SIGSEGV_struct = {0};
	SIGSEGV_struct.sa_handler = catch_SIGSEGV;
	sigfillset(&SIGSEGV_struct.sa_mask);
	SIGSEGV_struct.sa_flags = 0;
	sigaction(SIGSEGV, &SIGSEGV_struct, NULL);

	memcpy(&testG, G, sizeof(struct gameState));

	//run cardEffect with input variables
	int testReturn;
	testReturn = cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);

	//create expected cardEffect behavior for adventurer card
	while(treasure < 2) {
		if(G->deckCount[currentPlayer] < 1) {
			printf("test");
			G->deck[currentPlayer][0] = silver;
			G->deck[currentPlayer][1] = silver;
			G->deckCount[currentPlayer] += 2;
		}
		drawCard(currentPlayer, G);
		topIndex = G->handCount[currentPlayer] - 1;
		topCard = G->hand[currentPlayer][topIndex];
		if(topCard == copper) {
			treasure++;
		}
		else if(topCard == gold) {
			treasure++;
		}
		else if(topCard == silver) {
			treasure++;
		}
		else {
			G->discard[currentPlayer][G->discardCount[currentPlayer]++] = topCard;
			G->handCount[currentPlayer]--;
		}
	}

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

	printf("TESTING ADVENTURER CARD\n");

	for(n=0; n<200; n++) {
		//fill struct with random bytes
		for(i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = floor(Random() * 256);
		}
		//set critical variables
		currentPlayer = floor(Random() * MAX_PLAYERS);
		G.whoseTurn = currentPlayer;
		G.deckCount[currentPlayer] = floor(Random() * MAX_DECK);
		G.discardCount[currentPlayer] = floor(Random() * MAX_DECK);
		G.handCount[currentPlayer] = floor(Random() * MAX_HAND);
		handpos = floor(Random() * G.handCount[currentPlayer]);
		G.playedCardCount = floor(Random() * MAX_HAND);
		for(i=0; i<G.deckCount[currentPlayer]; i++) {
			G.deck[currentPlayer][i] = floor(Random() * 26);
		}

		//run test
		if(checkAdventurerCard(&G, currentPlayer, handpos) == 0) {
			numberPassed++;
		}
		else {
			numberFailed++;
		}
	}

	printf("Number of tests passed: %d\n", numberPassed);
	printf("Number of tests failed: %d\n", numberFailed);
	return 0;
}
