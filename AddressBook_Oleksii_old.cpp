#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// =============================================
// CLASS: AddressBook
// Author: Oleksii
// Description:
//   Manages all contacts in the address book.
//   Allows adding, removing, and filtering contacts
//   by type or by group.
// =============================================

class AddressBook {
private:
    // -----------------------------
    // Data field:
    // -----------------------------
    // List of all contacts in the address book.
    // (ContactList is defined as vector<Contact>)
    vector<Contact> contacts;

public:
    // -----------------------------
    // Getters / Setters
    // -----------------------------
    // Returns the full list of contacts.
    vector<Contact> getContacts() const {
        return contacts;
    }

    // Replaces the current list of contacts with a new one.
    void setContacts(const vector<Contact>& newContacts) {
        contacts = newContacts;
    }

    // -----------------------------
    // Add / Remove Contacts
    // -----------------------------
    // Adds a new contact to the list.
    void addContact(const Contact& c) {
        contacts.push_back(c);
    }

    // Removes a contact by its ID.
    void removeContact(int id) {
        auto it = remove_if(contacts.begin(), contacts.end(),
                            [&](const Contact& c){ return c.getId() == id; });
        contacts.erase(it, contacts.end());
    }

    // -----------------------------
    // Get Contacts of a Specific Type
    // -----------------------------
    // Returns only contacts that match a given type (Person, Business, etc.)
    vector<Contact> getContactsOfType(ContactType type) const {
        vector<Contact> result;
        for (const auto& c : contacts) {
            if (c.getType() == type)
                result.push_back(c);
        }
        return result;
    }

    // -----------------------------
    // Get Contacts by Group
    // -----------------------------
    // Returns all contacts that belong to a specific group (e.g. "Work", "Family").
    vector<Contact> getContactGroup(const string& groupName) const {
        vector<Contact> result;
        string groupLower = toLower(groupName);
        for (const auto& c : contacts) {
            const vector<string>& groups = c.getGroups();
            for (const auto& g : groups) {
                if (toLower(g) == groupLower) {
                    result.push_back(c);
                    break;
                }
            }
        }
        return result;
    }

private:
    // -----------------------------
    // Helper function: convert string to lowercase
    // -----------------------------
    static string toLower(string s) {
        for (auto& ch : s)
            if (ch >= 'A' && ch <= 'Z')
                ch = ch - 'A' + 'a';
        return s;
    }
};
