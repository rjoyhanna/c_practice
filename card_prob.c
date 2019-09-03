// card_prob.c

// calculate what are the odds that you will get at least one copy of the card you are
// looking for by the desired turn

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// calculates probability of drawing special card in the initital draw
double InitialDrawProbability(int initialHandSize, double negProbability, int numCardsInDeck, int numSpecialCard);
// calculates probability of drawing special card during the mulligan
double MulliganDrawProbability(int numCardsMulliganing, double negProbability, int numCardsInDeck, int numSpecialCard);
// calculates probability of drawing special card after the mulligan
double FinalDrawProbability(int turnToDrawCardBy, double negProbability, int numCardsInDeck, int numSpecialCard);

int main() {
	int numCardsInDeck;
	int numSpecialCard;
	int initialHandSize;
	int numCardsMulliganing;
	int turnToDrawCardBy;
	double yourProbability;
	double negProbability = 1;

	// accept user input
	printf("Enter how many total cards there are in the deck: ");
	scanf("%d", &numCardsInDeck);
	printf("Enter how many copies of the card that you are looking for are in the deck: ");
	scanf("%d", &numSpecialCard);
	printf("Enter your initial hand size: ");
	scanf("%d", &initialHandSize);
	printf("Enter how many cards you are mulliganing: ");
	scanf("%d", &numCardsMulliganing);
	printf("Enter what turn you want to draw the card by: ");
	scanf("%d", &turnToDrawCardBy);

	negProbability = InitialDrawProbability(initialHandSize, negProbability, numCardsInDeck, numSpecialCard);

	// subtracts cards in hand from cards in deck
	numCardsInDeck = numCardsInDeck - initialHandSize;

	negProbability = MulliganDrawProbability(numCardsMulliganing, negProbability, numCardsInDeck, numSpecialCard);

	negProbability = FinalDrawProbability(turnToDrawCardBy, negProbability, numCardsInDeck, numSpecialCard);

	// computes probability of finding a special card using the probability of not finding a special card
	yourProbability = 1 - negProbability;

	printf("The probability of drawing at least one of the cards by turn %d ", turnToDrawCardBy);
	printf("given you mulliganed %d cards is %.2lf", numCardsMulliganing, yourProbability);

	return 0;
}

// calculates probability of drawing special card in the initital draw
// initialHandSize is the number of cards you draw before the mulligan
// negProbability is the probability of not drawing a special card
// numCardsInDeck is the number of cards in the deck
// numSpecialCard is the number of cards you are looking for in the deck
double InitialDrawProbability(int initialHandSize, double negProbability, int numCardsInDeck, int numSpecialCard) {
	int numCardsDrawn;
	for (numCardsDrawn = 0; numCardsDrawn < initialHandSize; numCardsDrawn++) {
		negProbability = negProbability * ((double) (numCardsInDeck - numSpecialCard) / (double) (numCardsInDeck));
		numCardsInDeck = numCardsInDeck - 1;
	}
	return negProbability;
}

// calculates probability of drawing special card during the mulligan
// numCardsMulliganing is the number of cards removed from your hand in the mulligan
// negProbability is the probability of not drawing a special card
// numCardsInDeck is the number of cards in the deck
// numSpecialCard is the number of cards you are looking for in the deck
double MulliganDrawProbability(int numCardsMulliganing, double negProbability, int numCardsInDeck, int numSpecialCard) {
	int numCardsDrawn;
	for (numCardsDrawn = 0; numCardsDrawn < numCardsMulliganing; numCardsDrawn++){
		negProbability = negProbability * ((double) (numCardsInDeck - numSpecialCard) / (double) (numCardsInDeck));
		numCardsInDeck = numCardsInDeck - 1;
	}
	return negProbability;
}

// calculates probability of drawing special card after the mulligan
// turnToDrawCardBy is the turn you want to draw the special card by
// negProbability is the probability of not drawing a special card
// numCardsInDeck is the number of cards in the deck
// numSpecialCard is the number of cards you are looking for in the deck
double FinalDrawProbability(int turnToDrawCardBy, double negProbability, int numCardsInDeck, int numSpecialCard) {
	int numCardsDrawn;
	for (numCardsDrawn = 0; numCardsDrawn < turnToDrawCardBy; numCardsDrawn++) {
		negProbability = negProbability * ((double) (numCardsInDeck - numSpecialCard) / (double) (numCardsInDeck));
		numCardsInDeck = numCardsInDeck - 1;
	}
	return negProbability;
}
