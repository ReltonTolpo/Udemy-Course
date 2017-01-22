#include <iostream>
#include <string>
#include <algorithm>

#define ITS( x ) static_cast< std::ostringstream & >(( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

void printIntro();
string guessLoop(string word);
bool promtPlayAgain();
void playGame(string wordGuess);

//Creates freelines
void freeline(int num) {
	for (int i = 0; i < num; i = i + 1) {
		cout << "\n";
	}
	return;
}

//Input function
string input(string info) {
	cout << info + " ";
	getline(cin, info);
	return info;
}

//Print functions
int print(string info) {
	cout << info;
	return 0;
}

int println(string info) {
	cout << info << endl;
	return 0;
}

//Upper function
string upper(string upperWord) {
	transform(upperWord.begin(), upperWord.end(), upperWord.begin(), ::toupper);
	return upperWord;
}

//Main function
int main() {

	//Declare vars
	string wordGuess = "HI";

	//PrintIntro
	printIntro();

	//Play game!
	playGame(wordGuess);

	system("PAUSE");
	return 0;

}

//Introduce the game
void printIntro() {
	constexpr int WORLD_LENGTH = 9;
	println("Welcome to Bulls and Cows, a fun word game.");
	print("Can you guess the ");
	cout << WORLD_LENGTH;
	println(" letter isogram I'm thinking of?");
	return;
}

//Play the game's guess loop
string guessLoop(string word) {

	string Guess;
	int limit = 5;
	
	for (int i = 1; i <= limit; i++) {
		freeline(1);
		print("Enter your guess: (");
		cout << 6-i;
		Guess = input(" left)");
		print("Your guess was: ");
		println(Guess);
		if (upper(Guess) == word) {
			println("Well done! You got the correct word!");
			break;
		} else if(i != 5) {
			println("Try again!");
		} else {
			println("Sorry, you didn't make it in time!");
		}
	}
	freeline(3);
	return Guess;

}

//Ask the player if they want to play again
bool promtPlayAgain() {
	while (true) {
		string response = input("Do you want to play again? (y/n)");
		if (response[0] == 'y' || response[0] == 'Y') {
			return true;
			break;
		} else if (response[0] == 'n' || response[0] == 'N') {
			return false;
			break;
		} else {
			println("Please enter a valid answer.");
		}
	}
}

//Playing the game!
void playGame(string wordGuess) {
	while (true) {
		//GuessLoop
		guessLoop(wordGuess);

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