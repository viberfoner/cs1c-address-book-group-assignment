/*
#include "Contact.cpp"
#include "ContactList.cpp"
#include "AdressBook.cpp"

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printPrompt();
void getUserInput();

int main() {
	int response;

	//while(true) {
		printPrompt();
		if (cin >> response) {;
			cout << response;
		} else {
			cout << input must

		//getUserInput();
	//}

	return 0;
}


void printPrompt() {
	vector<string> options = {
		"List all contacts",
		"List contacts by type",
		"Show info about a contact group",
		"Add a contact",
		"Update an existing contact",
		"Remove a contact",
		"Search by contact name",
		"Display info about a contact",
		"Exit"
	};

	cout << "Enter a number to choose one of the following options:" << endl << endl;
	for (int i = 0; i < options.size(); i++) {
		cout << i+1 << ") " << options[i] << endl;
	}
}

void getUserInput() {
	int response;
	cin >> response;
}
