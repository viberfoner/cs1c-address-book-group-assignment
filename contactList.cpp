//contactList.cpp

#include <iostream>
#include "ContactList.h"
using namespace std;

// the default constructor - creates an empty contact list / no contacts are added yet
ContactList::ContactList() {}

// the overloaded constructor with initial vector 
// this constructor is to initialize the contact list with a predefined set of contacts
ContactList::ContactList(const vector<Contact>& contacts)
{
    this->contacts = contacts; // this -> refers to the objects own variable
}

// addContact - adds a new contact to the vecotor of contacts
void ContactList::addContact(const Contact& contact)
{
    contacts.push_back(contact); // add the new contact to the end of the vector
}

// Remove contact by ID
// it loops through the vector of contacts to find a contact with the specified ID
// and if it finds it, it removes that contact from the vector
// if there is no contact with the id, it should print a message that says its not found
void ContactList::removeContact(unsigned int id)
{
    // use an iterator for the vector
    for (auto it = contacts.begin(); it != contacts.end(); ++it)
    {
        // this just checks if the id of the current contact matches the id we want to remove
        if (it->getId() == id)
        {
            contacts.erase(it);
            cout << "Contact with ID " << id << " removed.\n";
            return;
        }
    }
    // in case the contact had no matching ID
    cout << "Contact with ID " << id << " not found.\n";
}

// Clear the list - this just clears the vector using the clear() method
//which removes all elements from the vector to 0 
void ContactList::clearContactList()
{
    contacts.clear();
    cout << "All contacts have been removed.\n";
}

// printContactList - this checks if the vector is empty first, and if its not
// it loops through the vector and calls the printContact method for each contact
//which should print all its fields
void ContactList::printContactList() const
{
    // tells the user if the list is empty, and exits the function early
    if (contacts.empty())
    {
        cout << "No contacts to display.\n";
        return;
    }

    cout << "\n--- Contact List ---\n";

    // loops through every contact in the vector 
    for (const auto& contact : contacts)
    {
        contact.printContact();
        cout << "---------------------\n"; // just a separator between contacts
    }
}

// Filter contacts by type and return a new ContactList - it should return 
//a new ContactList object that contains only the contacts of the specified type
// by creating a new vector and returning a new ContactList initialized with that vector
ContactList ContactList::filter(const string& type) const
{
    // temporary vector to hold the filtered contacts
    vector<Contact> filtered;

    for (const auto& contact : contacts)
    {
    
    // If the contact's type matches the given type, add it to the new list
    if (contact.getType() == type)
        filtered.push_back(contact);
    }

    return ContactList(filtered);
}



