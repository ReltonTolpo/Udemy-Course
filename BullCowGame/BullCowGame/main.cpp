#include <iostream>
#include <string>
using namespace std;

//Creates freelines
int freeline(int num) {
	for (int i = 0; i < num; i = i + 1) {
		cout << "\n";
	}
	return 0;
}

//Input function
string input(string info) {
	cout << info + " ";
	getline(cin, info);
	return info;
}

//Print function
int print(string info) {
	cout << info << endl;
	return 0;
}

int main() {

	print("Welcome to Bulls and Cows");

	system("PAUSE");
	return 0;

}