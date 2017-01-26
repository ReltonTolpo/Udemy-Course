#pragma once
#include <string>

class FBullCowGame {

	public:
		void reset();
		int getMaxTries();
		int getCurrentTry();
		bool isGameWon();
		bool checkGuessValid(std::string);

	private:
		int myCurrentTry;
		int myMaxTries;

};