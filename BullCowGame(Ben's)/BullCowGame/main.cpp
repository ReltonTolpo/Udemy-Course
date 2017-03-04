/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "functions.h"
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// the entry point for our application
int main(){

	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);
	return 0; // exit the application

}

 
// introduce the game
void PrintIntro(){

	int32 WORD_LENGTH = BCGame.GetHiddenWordLength();
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;

}


void PlayGame(){

	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	// loop for the number of turns asking for guesses
	for (int32 count = 1; count <= MaxTries; count++) {
		FText Guess = GetValidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows;
		freeline(2);
	}

}


FText GetValidGuess() {

	int32 CurrentTry = BCGame.GetCurrentTry();
	print("Try "); print(std::to_string(CurrentTry));
	FText Guess = input(". Enter your guess: ");
	EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
	switch (Status) {
	case EGuessStatus::Wrong_Length:
		print("Please enter a "); print(std::to_string(BCGame.GetHiddenWordLength())); println(" letter word");
		return "aaaa";
	case EGuessStatus::Not_Isogram:
		print("Please enter a word without repeating letters");
		return "aaaa";
	default:
		BCGame.IncrementCurrentTry();
		return upper(Guess);
	}
	freeline(1);

}

bool AskToPlayAgain(){

	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');

}
