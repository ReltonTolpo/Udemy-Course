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
FString guessLoop(FString word);
bool promtPlayAgain();
void playGame(FString wordGuess);

FBullCowGame BCGame; //Instantiate a new gameb

//Main function
int32 main() {

	//Declare vars
	FString wordArray[] = {"HI","GARY","NO"};
	int32 arrayNum = random(1,3);
	BCGame.setHiddenWord(wordArray[arrayNum]);

	//PrintIntro
	printIntro();

	//Play game!
	playGame(BCGame.getHiddenWord());

	system("PAUSE");
	return 0;

}

//Introduce the game
void printIntro() {
	println("Welcome to Bulls and Cows, a fun word game.");
	println("Can you guess the isogram I'm thinking of?");
	return;
}

//Play the game's guess loop
FString guessLoop(FString word) {

	FString Guess = "";
	
	for (int32 i = 1; i <= BCGame.getMaxTries(); i++) {
		freeline(1);
		print("\nEnter your guess: (");
		print(std::to_string(6-i));
		Guess = input(" left)");
		bullCowCount bullCowCount = BCGame.SubmitGuess(Guess);
		print("Your guess was: ");
		println(Guess);
		if (upper(Guess) == word) {
			println("Well done! You got the correct word!");
			break;
		} else if(i != 5) {
			print("Try again! Remember, it is ");
			print(std::to_string(word.length()));
			print(" letters long.");
		} else {
			println("Sorry, you didn't make it in time!");
		}
		BCGame.setCurrentTry(i);
	}
	freeline(3);
	return Guess;

}

//Ask the player if they want to play again
bool promtPlayAgain() {
	do{
		FString response = input("Do you want to play again? (y/n)");
		FString s; s.push_back(response[0]);
		if (lower(s) == "y") {
			return true;
			break;
		} else if (lower(s) == "n") {
			return false;
			break;
		} else {
			println("Please enter a valid answer.");
		}
	} while (true);
}

//Playing the game!
void playGame(FString word) {
	BCGame.reset();
	print("The isogram is ");
	print(std::to_string(word.length()));
	print(" letters long");
	while (true) {
		//GuessLoop
		guessLoop(word);

		//Prompt to play again
		if (promtPlayAgain() == true) {
			println("Have a go!");
		} else {
			freeline(3);
			println("We hope you enjoyed your stay!");
			break;
		}
	}
	return;
}