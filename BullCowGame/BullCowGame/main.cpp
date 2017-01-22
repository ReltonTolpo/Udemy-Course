#include <iostream>
#include <string>
#include <algorithm>
#include <random>

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
void print(string info) {
	cout << info;
	return;
}
void println(string info) {
	cout << info << endl;
	return;
}
//Upper function
string upper(string upperWord) {
	transform(upperWord.begin(), upperWord.end(), upperWord.begin(), ::toupper);
	return upperWord;
}
//Generate random number
int random(int start, int end) {
	mt19937 rng;
	rng.seed(random_device()());
	uniform_int_distribution<mt19937::result_type> dist6(start, end);
	return dist6(rng);
}

//Main function
int main() {

	//Declare vars
	string wordArray[] = {"HI","GARY","NO"};
	int arrayNum = random(1,3);
	string wordGuess = wordArray[arrayNum];

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
string guessLoop(string word) {

	string Guess;
	int limit = 5;
	
	for (int i = 1; i <= limit; i++) {
		freeline(1);
		print("\nEnter your guess: (");
		cout << 6-i;
		Guess = input(" left)");
		print("Your guess was: ");
		println(Guess);
		if (upper(Guess) == word) {
			println("Well done! You got the correct word!");
			break;
		} else if(i != 5) {
			print("Try again! Remember, it is ");
			cout << word.length();
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
	} while (true);
}

//Playing the game!
void playGame(string word) {
	print("The isogram is ");
	cout << word.length();
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