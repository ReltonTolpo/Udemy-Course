#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetHiddenWordLength() const {return MyHiddenWord.length();}
int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}
void FBullCowGame::IncrementCurrentTry() {MyCurrentTry++;}

void FBullCowGame::Reset(){
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	/*FString wordArray[] = { "HI","ETHO","NO" };
	int32 arrayNum = random(1, 3);
	MyHiddenWord = wordArray[arrayNum];*/
	const FString HIDDEN_WORD = "ETHO";
	MyHiddenWord = HIDDEN_WORD;
	

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon(FString Word) const{
	FBullCowCount BullCowCount;
	if(BullCowCount.Bulls == Word.length())
		return true;
	else {
		return false;
	}
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess){
	if (!IsIsogram(Guess)) {
		return EGuessStatus::Not_Isogram;
	} else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	} else {
		return EGuessStatus::OK;
	}
}

// receives a VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess){

	// setup a return variable
	FBullCowCount BullCowCount;
	
	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) { // if they're in the same place
					BullCowCount.Bulls++; // incriment bulls
				} else {
					BullCowCount.Cows++; // must be a cow
				}
			}
		}
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const {

	return true;

}
