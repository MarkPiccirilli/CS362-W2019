/*****************************************
 * Title: Random Test adventurer card
 * Author: Mark Piccirilli
 * Date: 2/26/19
 * Description: This program performs random testing on the adventure card
 * **************************************************/

//#define _XOPEN_SOURCE

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

/*
int SEGFAULT = 0;

void catch_SIGSEGV(int sig_num) {
	SEGFAULT = 1;
	printf("segfault");
}
*/

int checkAdventurerCard(struct gameState* G, int currentPlayer, int handPos) {

	/*	
	//set up sigaction struct to catch segfault
	struct sigaction *sa;
	sa = malloc(sizeof(struct sigaction));
	sa->sa_handler = catch_SIGSEGV;
	sigaction(SIGSEGV, sa, NULL);
	*/

	//these variables are needed for the cardEffect function, but are not useed by the village card
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	
	struct gameState testG;
	int topCard, topIndex;
	int treasure = 0;
	int temphand[MAX_HAND];
	int count = 0;	


	memcpy(&testG, G, sizeof(struct gameState));

	//run cardEffect with input variables
	int testReturn;
	testReturn = cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);

	//create expected cardEffect behavior for adventurer card
		
	while(treasure < 2) {

		//if(SEGFAULT == 1) {
		//	printf("Segmentation Fault");
		//}

		if(G->deckCount[currentPlayer] < 1) {
			shuffle(currentPlayer, G);
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
			temphand[count] = topCard;
			G->handCount[currentPlayer]--;
			count++;
		}
	}
	while(count > 0) {
		G->discard[currentPlayer][G->discardCount[currentPlayer]++] = temphand[count - 1];
		count--;
	}
	
	//check result
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

	for(n=0; n<2000; n++) {
		//fill struct with random bytes
		for(i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = floor(Random() * 256);
		}
		//set critical variables
		G.numPlayers = floor(Random() * MAX_PLAYERS);
		currentPlayer = floor(Random() * G.numPlayers);
		G.whoseTurn = currentPlayer;
		G.deckCount[currentPlayer] = floor(Random() * MAX_DECK);
		G.discardCount[currentPlayer] = floor(Random() * MAX_DECK);
		G.handCount[currentPlayer] = floor(Random() * MAX_HAND);
		handpos = floor(Random() * G.handCount[currentPlayer]);
		G.playedCardCount = floor(Random() * MAX_HAND);
		for(i=0; i<G.deckCount[currentPlayer]; i++) {
			G.deck[currentPlayer][i] = floor(Random() * 26);
		}
		for(i=0; i<G.handCount[currentPlayer]; i++) {
			G.hand[currentPlayer][i] = floor(Random() * 26);
		}
		for(i=0; i<G.discardCount[currentPlayer]; i++) {
			G.discard[currentPlayer][i] = floor(Random() * 26);
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
	printf("\n\n");
	return 0;
}
