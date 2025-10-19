//ContactList.h
#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <string>
#include <vector>
#include "Contact.h"
using namespace std;


class ContactList {
private:
    vector<Contact> contacts;
public:

    // Constructors
    ContactList();
    ContactList(const vector<Contact>& contacts);

    // Core functions
    void addContact(const Contact& contact);
    void removeContact(unsigned int id);
    void clearContactList();
    void printContactList() const;

    // Filter by type (returns a new ContactList)
    ContactList filter(const string& type) const;

    // Optional helper
    const vector<Contact>& getContacts() const { return contacts; }
};

#endif
