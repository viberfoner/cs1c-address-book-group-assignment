#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <vector>
#include <string>
#include <algorithm>

#include "ContactList.h"

using namespace std;

// using ContactList = vector<Contact>;

// =============================================
// CLASS: AddressBook
// Author: Oleksii
// Description:
//   Manages all contacts in the address book.
//   Allows adding, removing, and filtering contacts
//   by type or by group. Supports CSV I/O.
// Dependencies: Contact, ContactList, CsvWriter, Group
// =============================================
class AddressBook {
private:
    // -----------------------------
    // Data fields:
    // -----------------------------
    ContactList contacts;  // contacts: ContactList
    string csvPath;        // path to save/load CSV

public:
    // -----------------------------
    // Getters / Setters
    // -----------------------------
    ContactList getContacts() const {
        return contacts;
    }

    void setContacts(const ContactList& newContacts) {
        contacts = newContacts;
    }

    string getCsvPath() const {
        return csvPath;
    }

    void setCsvPath(const string& path) {
        csvPath = path;
    }

    // -----------------------------
    // Add / Remove Contacts
    // -----------------------------
    
    void addContact(const Contact& c) {
        contacts.addContact(c);
    }

    
    void removeContact(int id) {
	contacts.removeContact(id);
        /*auto it = remove_if(contacts.begin(), contacts.end(),
                            [&](const Contact& c) { return c.getId() == id; });
        contacts.erase(it, contacts.end());
	*/
    }

    // -----------------------------
    // Get Contacts of a Specific Type
    // -----------------------------
    
    ContactList getContactsOfType(Contact::Type type) const {
        ContactList result;
        for (const auto& c : contacts.getContacts()) {
            if (c.getType() == type)
                result.addContact(c);
        }
        return result;
    }

    // -----------------------------
    // Get Contacts by Group
    // -----------------------------
    
    ContactList getContactGroup(const string& groupName) const {
        ContactList result;
        string key = toLower(groupName);
        for (const auto& c : contacts.getContacts()) {
            const vector<string>& groups = c.getGroups();
            for (const auto& g : groups) {
                if (toLower(g) == key) {
                    result.addContact(c);
                    break;
                }
            }
        }
        return result;
    }

    // -----------------------------
    // CSV I/O
    // -----------------------------
    
    void writeToCSV() const {
        //CsvWriter::writeCsv(csvPath, contacts);
	cout << "ERROR: CSVWriter not implemented";
    }


    ContactList readFromCSV(const string& filePath) const {
        //return CsvWriter::readCsv(filePath);
	return ContactList();
    }

private:
    // -----------------------------
    // Helper: convert string to lowercase
    // -----------------------------
    static string toLower(string s) {
        for (auto& ch : s)
            if (ch >= 'A' && ch <= 'Z')
                ch = ch - 'A' + 'a';
        return s;
    }
};

#endif
