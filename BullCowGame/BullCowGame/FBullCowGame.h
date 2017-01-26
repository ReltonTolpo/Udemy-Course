#pragma once
#include <string>

class FBullCowGame {

	public:
		FBullCowGame(); //Constructor

		int getMaxTries() const;
		int getCurrentTry() const;
		bool isGameWon() const;

		void reset();
		void changeCurrentTry(int changeAmount);
		bool checkGuessValid(std::string);

	private:
		//See reset for initialisation
		int myCurrentTry;
		int myMaxTries;

};