/*****************************************
 * Title: Random Test adventurer card
 * Author: Mark Piccirilli
 * Date: 2/26/19
 * Description: This program performs random testing on the adventure card
 * **************************************************/

#define _XOPEN_SOURCE

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

int SEGFAULT = 0;
int calls = 0;

void catch_SIGSEGV(int sig_num) {
	SEGFAULT = 1;
	printf("segfault");
}

int checkAdventurerCard(struct gameState* G, int currentPlayer, int handPos) {
	
	//set up sigaction struct to catch segfault
	struct sigaction *sa;
	sa = malloc(sizeof(struct sigaction));
	sa->sa_handler = catch_SIGSEGV;
	//sigaction(SIGSEGV, sa, NULL);

	//these variables are needed for the cardEffect function, but are not useed by the village card
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	
	struct gameState testG;
	int topCard, topIndex;
	int treasure = 0;


	memcpy(&testG, G, sizeof(struct gameState));

	//run cardEffect with input variables
	int testReturn;
	testReturn = cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);
	calls++;

	//create expected cardEffect behavior for adventurer card
	/*
	while(treasure < 2) {
		//printf("test1");
		if(SEGFAULT == 1) {
			printf("Segmentation Fault");
			exit(1);
		}
		if(G->deckCount[currentPlayer] < 1) {
			//printf("test");
			//G->deck[currentPlayer][0] = silver;
			//G->deck[currentPlayer][1] = silver;
			//G->deckCount[currentPlayer] += 2;
			break;
		}
		drawCard(currentPlayer, G);
		topIndex = G->handCount[currentPlayer] - 1;
		topCard = G->hand[currentPlayer][topIndex];
		printf("%d", topCard);
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
	*/
	//
	//
	//actual code
	int z = 0;
	int temphand[MAX_HAND];
	int cardDrawn;
	int drawntreasure = 0;
	 while(drawntreasure<2){
		if (G->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, G);
		}
		drawCard(currentPlayer, G);
		cardDrawn = G->hand[currentPlayer][G->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else{
			temphand[z]=cardDrawn;
			G->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	while(z-1>=0){
		G->discard[currentPlayer][G->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
		z=z-1;
	}
	//
	//
	//

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

		//run test
		printf("test");
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
