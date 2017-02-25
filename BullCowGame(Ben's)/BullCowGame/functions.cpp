#include "functions.h"

/*

-----Int to string-----
STRING = to_string(INT)
STRING = std::to_string(INT)

STRING.push_back(CHAR)

-----String to int-----
INT = stoi(STRING)

*/

//Boolean to string
std::string boolToString(bool value) {
	std::string s; if (value == true) { s = "true"; } else { s = "false"; }
	return s;
}

//Creates freelines
void freeline(int num) {
	for (int i = 0; i < num; i = i + 1) { std::cout << "\n"; }
	return;
}
//Input function
std::string input(std::string info) {
	std::cout << info + " "; std::getline(std::cin, info);
	return info;
}
//Print functions
void print(std::string info) {
	std::cout << info;
	return;
}
void printInt(int info) {
	std::cout << info;
	return;
}
void println(std::string info) {
	std::cout << info << std::endl;
	return;
}
//Upper & Lower functions
std::string upper(std::string upperWord) {
	transform(upperWord.begin(), upperWord.end(), upperWord.begin(), ::toupper);
	return upperWord;
}
std::string lower(std::string lowerWord) {
	transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
	return lowerWord;
}
//Generate random number
int random(int start, int end) {
	std::mt19937 rng; rng.seed(std::random_device()()); std::uniform_int_distribution<std::mt19937::result_type> dist6(start, end);
	return dist6(rng);
}