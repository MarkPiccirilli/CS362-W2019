/**************************************
 * Title: isGameOver function unit test
 * Author: Mark Piccirilli
 * Date: 2/27/19
 * Description: This is a unit test for the isGameOver funtion
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
	struct gameState G, G1, G2, G3;

	
	printf("TESTING ISGAMEOVER FUNCTION\n");
	printf("\n");

	//provice supply count is zero so game is over
	initializeGame(numberOfPlayers,  kCards, seed, &G);
	G.supplyCount[province] = 0;

	if(isGameOver(&G) == 1) {
		printf("PASSED PROVINCE SUPPLY COUNT TEST\n");
	}
	else {
		printf("FAILED PROVINCE SUPPLY COUNT TEST\n");
	}

	//if 3 supply piles have a supply count of 0
	initializeGame(numberOfPlayers,  kCards, seed, &G1);
	G1.supplyCount[4] = 0;
	G1.supplyCount[15] = 0;
	G1.supplyCount[18] = 0;
	if(isGameOver(&G1) == 1) {
		printf("PASSED 3 PILE SUPPLY AT ZERO TEST\n");
	}
	else {
		printf("FAILED 3 PILE SUPPLY AT ZERO TEST\n");
	}


	//if more than 3 supply piles have a count of 0
	initializeGame(numberOfPlayers,  kCards, seed, &G2);
	G2.supplyCount[0] = 0;
	G2.supplyCount[3] = 0;
	G2.supplyCount[14] = 0;
	G2.supplyCount[19] = 0;
	G2.supplyCount[25] = 0;
	if(isGameOver(&G2) == 1) {
		printf("PASSED 5 PILE SUPPLY AT ZERO TEST\n");
	}
	else {
		printf("FAILED 5 PILE SUPPLY AT ZERO TEST\n");
	}
	
	//if two piles have a supply count of 0
	initializeGame(numberOfPlayers,  kCards, seed, &G3);
	G3.supplyCount[12] = 0;
	G3.supplyCount[13] = 0;
	if(isGameOver(&G3) == 0) {
		printf("PASSED 2 PILE SUPPLY AT ZERO TEST\n");
	}
	else {
		printf("FAILED 2 PILE SUPPLY AT ZERO TEST\n");
	}

	printf("\n\n\n");
	return 0;
}
