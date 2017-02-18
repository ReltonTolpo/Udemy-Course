#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() {reset(); return;}

void FBullCowGame::reset() {
	constexpr int32 MAX_TRIES = 8;
	myCurrentTry = MAX_TRIES;
	myMaxTries = 8;
	return;
}

int32 FBullCowGame::getMaxTries() const {return myMaxTries;}
int32 FBullCowGame::getCurrentTry() const {return myCurrentTry;}
FString FBullCowGame::getHiddenWord() const{return myHiddenWord;}

void FBullCowGame::setCurrentTry(int32 changeAmount) { myCurrentTry = changeAmount; return; }
void FBullCowGame::setHiddenWord(FString h) { myHiddenWord = h; return; }

bool FBullCowGame::isGameWon() const {
	return false;
}

bool FBullCowGame::checkGuessValid(FString){
	return false;
}

bullCowCount FBullCowGame::SubmitGuess(FString){
	//Don't increase turn number
	
	//Setup a return variable
	bullCowCount bullCowCount;

	int hiddenWordLength = myHiddenWord.length;

	for (int32 i = 0; i < hiddenWordLength; i++) {
		for (int32 j = 0; j < hiddenWordLength; j++) {
			/*if they match then
				increase bulls
			else
				increase cows
	*/
		}
	}

	return bullCowCount;
}