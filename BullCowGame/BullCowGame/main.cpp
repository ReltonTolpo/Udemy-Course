#include "functions.h"
#include "FBullCowGame.h"
#include <iostream>
#include <algorithm>
#include <random>

void printIntro();
std::string guessLoop(std::string word);
bool promtPlayAgain();
void playGame(std::string wordGuess);

//Main function
int main() {

	//Declare vars
	std::string wordArray[] = {"HI","GARY","NO"};
	int arrayNum = random(1,3);
	std::string wordGuess = wordArray[arrayNum];

	//PrintIntro
	printIntro();

	//Play game!
	playGame(wordGuess);

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
std::string guessLoop(std::string word) {

	std::string Guess;
	int limit = 5;
	
	for (int i = 1; i <= limit; i++) {
		freeline(1);
		print("\nEnter your guess: (");
		print(std::to_string(6-i));
		Guess = input(" left)");
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
	}
	freeline(3);
	return Guess;

}

//Ask the player if they want to play again
bool promtPlayAgain() {
	do{
		std::string response = input("Do you want to play again? (y/n)");
		if (response[0] == 'y' || response[0] == 'Y') {
			return true;
			break;
		} else if (response[0] == 'n' || response[0] == 'N') {
			return false;
			break;
		} else {
			println("Please enter a valid answer.");
		}
	} while (true);
}

//Playing the game!
void playGame(std::string word) {
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