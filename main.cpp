/*
	Potential improvements: instead of entering numbers, user types in command name
	TODO: implement contact type enum string map
*/


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

void printPrompt();
void getUserInput();
void processUserInput();

void addContact();
void editContact();
void deleteContact();
void viewContact();
void listAllContacts();

void saveContacts();

void exitProgram();


AddressBook addressBook;
string csvPath = "contacts.csv";
string response;
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
	{"Save all contacts to CSV file", &saveContacts},

	// 5. Reports
	{"List contacts by type"},
	{"Show contacts missing email or phone number"},
	{"Display group summaries"},

	{"Exit", &exitProgram}
};

int main() {
	addressBook.readFromCSV(csvPath);

	bool inputIsValid = false;

	printPrompt();

	while (true) {

		getUserInput();
		processUserInput();

	}

	// cout << "Input must be a number" << endl;


	return 0;
}


void printPrompt() {

	// cout << endl << "Enter a number to choose one of the following options:" << endl << endl;
	for (int i = 0; i < options.size(); i++) {
		cout << i+1 << ") " << options[i].prompt << endl;
	}
	cout << endl << "Enter a number to choose one of the listed options: ";
}

Contact enterContact() {
	string firstName;
	string lastName;
	string phoneNumber;
	string address;
	string email;
	string type;
	//Contact::Type type(Contact::Type::NONE);

	cout << "First name: ";
	getline(cin, firstName);

	cout << "Last name: ";
	getline(cin, lastName);

	cout << "Phone number: ";
	getline(cin, phoneNumber);
	
	cout << "Address: ";
	getline(cin, address);
	
	cout << "Email: ";
	getline(cin, address);
	
	cout << "Enter one of the following numbers to select the type: " << endl;
	cout << "0, 1, 2, 3, 4, 5" << endl; // need to implement contact type enum map
	getline(cin, type);
	
	if (type.empty()) type = "0";
	

	return Contact(firstName, lastName, phoneNumber, address, email, Contact::Type(stoi(type)));
}

void addContact() {
	Contact newContact = enterContact();
	addressBook.addContact(newContact);
	cout << "Contact " << newContact.getFirstName() << " " << newContact.getLastName() << " added!" << endl << endl;
}

void editContact() {
	unsigned int id;
	Contact* pContact;
	cout << "Enter the contact's ID to edit: ";
	cin >> id;
	/*pContact = addressBook.getContactById(id);
	if (pContact == nullptr) {
		cout << "Invalid ID" << endl;
		return;
	}
	*/
	//pContact->printContact();
	
	//Contact modifiedContact = enterContact();
	//pContact = &modifiedContact;
	/*
	cout << "Enter the field you would like to edit: " << endl;
	cout << "1) First name" << endl;
	cout << "2) Last name" << endl;
	cout << "3) Phone number" << endl;
	cout << "4) Address" << endl;
	cout << "5) Email" << endl;
	cout << "6) Type" << endl;
	
	unsigned int choice;
	cin >> choice;
	*/
	


}
void deleteContact() {
	cout << "deleteContact" << endl;
}
void viewContact() {
	cout << "Enter the contact's ID to view: ";
	
}
void listAllContacts() {
	cout << "listAllContacts" << endl;
}

void saveContacts() {
	addressBook.writeToCSV(csvPath);
}

void getUserInput() {
	getline(cin, response);
}

void processUserInput() {
	if (response.empty()) return;
	
	if (response == "help"){
		printPrompt();
		return;
	}

	options[stoi(response)-1].execute();

	cout << "Enter another command or type \"help\" to display options: ";

}

void exitProgram() {
	// TODO: check if user wants to save, then exit
	exit(EXIT_SUCCESS);
}
