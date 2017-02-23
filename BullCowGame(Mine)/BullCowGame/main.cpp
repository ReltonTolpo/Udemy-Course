/*
This is the console exe that makes use of the BullCow class,
this acts as the view in a MVC pattern and is responsible for all
user interaction. For game logic see the FBullCowClass.
*/

#include "functions.h"
#include "FBullCowGame.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <random>

using FString = std::string;
using int32 = int;

void printIntro();
bool promtPlayAgain();
void playGame(FString wordGuess);
bool playAgain;

FBullCowGame BCGame; //Instantiate a new game

//Main function
int32 main() {

	//Declare vars
	FString wordArray[] = {"HI","GARY","NO"};
	int32 arrayNum = random(1,3);
	BCGame.setHiddenWord(wordArray[arrayNum]);
	bool bPlayAgain = false;

	do {
		printIntro();
		playGame(BCGame.getHiddenWord());
		bPlayAgain = promtPlayAgain();
		if (bPlayAgain == true) {
			arrayNum = random(1, 3);
			BCGame.setHiddenWord(wordArray[arrayNum]);
		}
	} while (bPlayAgain);

	system("PAUSE");
	return 0;

}

//Introduce the game
void printIntro() {

	println("Welcome to Bulls and Cows, a fun word game.");
	println("Can you guess the isogram I'm thinking of?");
	return;

}

//Get the user's guess
FString getGuess(int32 currentTry) {

	print("Enter your guess: (");
	printInt(6 - currentTry);
	FString guess = input(" left)");
	return guess;

}

//Ask the player if they want to play again
bool promtPlayAgain() {

	do{
		FString response = input("Do you want to play again? (y/n)");
		FString s; s.push_back(response[0]);
		if (lower(s) == "y") {
			println("Have a go!");
			playAgain = true;
			break;
		} else if (lower(s) == "n") {
			freeline(3);
			println("We hope you enjoyed your stay!");
			playAgain = false;
			break;
		} else {
			println("Please enter a valid answer.");
		}
	} while (true);
	return playAgain;

}

//Playing the game!
void playGame(FString word) {

	BCGame.reset();
	print("The isogram is ");
	printInt(word.length());
	print(" letters long");

	FString playerGuess = "";

	for (int32 i = 1; i <= BCGame.getMaxTries(); i++) {
		BCGame.setCurrentTry(i);
		freeline(2);
		playerGuess = getGuess(i);
		bullCowCount bullCowCount = BCGame.SubmitGuess(playerGuess);
		print("Your guess was: ");
		println(playerGuess);
		print("You have ");printInt(bullCowCount.bulls);println(" bulls");
		print("You have ");printInt(bullCowCount.cows);println(" cows");
		if (upper(playerGuess) == word) {
			println("Well done! You got the correct word!");
			break;
		} else if (i != 5) {
			print("Try again! Remember, it is ");
			printInt(word.length());
			print(" letters long.");
		} else {
			println("Sorry, you didn't make it in time!");
		}
	}
	freeline(3);
	return;

}