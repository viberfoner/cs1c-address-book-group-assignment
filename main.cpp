#include "AddressBook.cpp"


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct Command {
	string prompt;
	void (*execute)();
};

void printPrompt(vector<Command>&);
void getUserInput();

void addContact();
void editContact();
void deleteContact();
void viewContact();
void listAllContacts();

void exitProgram();


int main() {
	AddressBook addressBook;

	ifstream inFile;
	inFile.open("address-book.csv");
	inFile.close();

	int response;
	
	bool inputIsValid = false;

	vector<Command> options = {

		// 1. Contact Management
		{"Add a new contact", &addContact},
		{"Edit an existing contact", &editContact},
		{"Delete a contact", &deleteContact},
		{"View a contact's details", &viewContact},
		{"List all contacts", &listAllContacts},

		// 2. Searching and Filtering
		{"Search contacts by name, email or phone number"},
		{"Filter contacts by type, city or tag"},

		// 3. Grouping and Tagging
		{"Assign contacts to groups"},
		{"Add or remove tags"},
		
		// 4. Import/Export (implement loading from CSV at startup)
		{"Save all contacts to CSV file"},

		// 5. Reports
		{"List contacts by type"},
		{"Show contacts missing email or phone number"},
		{"Display group summaries"},

		{"Exit", &exitProgram}
	};

	printPrompt(options);

	cin >> response;

	options[response-1].execute();


	// cout << "Input must be a number" << endl;


	return 0;
}


void printPrompt(vector<Command> &cmdList) {

	cout << endl << "Enter a number to choose one of the following options:" << endl << endl;
	for (int i = 0; i < cmdList.size(); i++) {
		cout << i+1 << ") " << cmdList[i].prompt << endl;
	}
	cout << endl;
}

void addContact() {
	cout << "addContact" << endl;
}

void editContact() {
	cout << "editContact" << endl;
}
void deleteContact() {
	cout << "deleteContact" << endl;
}
void viewContact() {
	cout << "viewContact" << endl;
}
void listAllContacts() {
	cout << "listAllContacts" << endl;
}

void getUserInput() {
	int response;
	cin >> response;
}

void exitProgram() {
	exit(EXIT_SUCCESS);
}
