#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct bullCowCount{
	
	int bulls = 0;
	int cows = 0;
	FString whyIsThisGameNotCalledMastermind = "Because Ben isn't very clever";

};

class FBullCowGame {

	public:
		FBullCowGame(); //Constructor

		int32 getMaxTries() const;
		int32 getCurrentTry() const;
		FString getHiddenWord() const;
		bool isGameWon() const;

		void reset();
		void setCurrentTry(int32 changeAmount);
		void setHiddenWord(FString h);
		bool checkGuessValid(FString);

		bullCowCount SubmitGuess(FString);

	private:
		//See reset for initialisation
		int32 myCurrentTry;
		int32 myMaxTries;
		FString myHiddenWord;

};