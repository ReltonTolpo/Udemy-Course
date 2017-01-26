#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() {reset(); return;}

void FBullCowGame::reset() {
	constexpr int MAX_TRIES = 8;
	myCurrentTry = MAX_TRIES;
	myMaxTries = 8;
	return;
}

void FBullCowGame::changeCurrentTry(int changeAmount) {myCurrentTry = changeAmount; return;}
int FBullCowGame::getMaxTries() const {return myMaxTries;}
int FBullCowGame::getCurrentTry() const {return myCurrentTry;}

bool FBullCowGame::isGameWon() const {
	return false;
}

bool FBullCowGame::checkGuessValid(std::string){
	return false;
}