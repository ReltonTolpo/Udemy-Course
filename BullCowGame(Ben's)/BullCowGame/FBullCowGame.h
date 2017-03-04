#pragma once
#include <string>
#include "functions.h"

using FString = std::string;
using int32 = int;

// all values intialised to zero
struct FBullCowCount{

	int32 Bulls = 0;
	int32 Cows = 0;

};

enum class EGuessStatus {

	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length

};

class FBullCowGame{
public:
	FBullCowGame(); // constructor

	int32 GetHiddenWordLength() const;
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	void IncrementCurrentTry();
	bool IsGameWon(FString Word) const;
	bool FBullCowGame::IsIsogram(FString Word) const;
	
	void Reset();
	EGuessStatus CheckGuessValidity(FString);
	FBullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};