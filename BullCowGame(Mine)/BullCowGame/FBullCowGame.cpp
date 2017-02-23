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

bullCowCount FBullCowGame::SubmitGuess(FString guess){
	//Don't increase turn number

	//Setup a return variable
	bullCowCount bullCowCount;

	int32 hiddenWordLength = myHiddenWord.length();

	for (int32 HWChar = 0; HWChar < hiddenWordLength; HWChar++) {
		for (int32 GChar = 0; GChar < hiddenWordLength; GChar++) {
			if (guess[HWChar] == myHiddenWord[HWChar]) {
				if (HWChar == GChar) {
					bullCowCount.bulls++;
				} else {
					bullCowCount.cows++;
				}
			}
		}
	}

	return bullCowCount;
}