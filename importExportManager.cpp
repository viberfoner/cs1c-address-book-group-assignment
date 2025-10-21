#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "ContactList.h"

using namespace std;

// =============================================
// CLASS: ImportExportManager
// Author: Logan Duer
// Description: 
//   Handles importing and exporting contacts
//   to and from a CSV file.
//   Fields supported:
//     - id, firstName, lastName, phoneNumber,
//       address, email, type
// =============================================

class ImportExportManager {
public:
    // -----------------------------
    // Read Contacts from CSV
    // -----------------------------
    // Reads all contacts from a CSV file and returns
    // them as a vector of Contact objects.
    static ContactList readCsv(const string& filename) {
        ContactList importedContacts;
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: Could not open file for reading.\n";
            return importedContacts;
        }

        string line;

        // discard first line (header row)
        getline(file, line);
        // NOTE: to properly read a CSV with arbitrary header fields,
        //   create a map or struct with a key of the data field name
        //   and value with the data. This is useful incase the header
        //   fields change so you don't have to rewrie parseContact()
        //   to match. -Nick

        while (getline(file, line)) {
            if (line.empty()) continue;

            Contact c = parseContact(line);
            importedContacts.addContact(c);
        }

        file.close();
        cout << "Contacts imported successfully.\n";
        return importedContacts;
    }

    // -----------------------------
    // Write Contacts to CSV
    // -----------------------------
    // Saves all contacts from memory into a CSV file.
    static void writeCsv(const ContactList& contactList, const string& filename) {
        ofstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: Could not open file for writing.\n";
            return;
        }

        // Optional: Write a header row
        file << "id,firstName,lastName,phoneNumber,address,email,type\n";

        for (const auto& c : contactList.getContacts()) {
            file << formatContact(c) << "\n";
        }

        file.close();
        cout << "Contacts exported successfully.\n";
    }

private:
    // -----------------------------
    // Helper: Parse CSV Line
    // -----------------------------
    // Converts one line from the CSV file into a Contact object.
    static Contact parseContact(const string& line) {
        stringstream ss(line);
        string idStr, firstName, lastName, phoneNumber, address, email, typeStr;

        getline(ss, idStr, ',');
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, phoneNumber, ',');
        getline(ss, address, ',');
        getline(ss, email, ',');
        getline(ss, typeStr, ',');
        
        unsigned int id = stoi(idStr);
        Contact::Type type = stringToType(typeStr);

        // Example constructor:
        // Contact(unsigned int id, string fn, string ln, string phone,
        //         string addr, string email, Contact::Type type)
        return Contact(firstName, lastName, phoneNumber, address, email, type);
    }

    // -----------------------------
    // Helper: Format Contact for CSV
    // -----------------------------
    // Converts a Contact object into a properly formatted CSV line.
    static string formatContact(const Contact& c) {
        return to_string(c.getId()) + "," +
            c.getFirstName() + "," +
            c.getLastName() + "," +
            c.getPhoneNumber() + "," +
            c.getAddress() + "," +
            c.getEmail() + "," +
            typeToString(c.getType());
    }

    // -----------------------------
    // Type Conversion Helpers
    // -----------------------------
    static string typeToString(Contact::Type type) {
        switch (type) {
        case Contact::Type::WORK: return "WORK";
        case Contact::Type::PERSONAL: return "PERSONAL";
        case Contact::Type::SCHOOL: return "SCHOOL";
        case Contact::Type::MISCELLANEOUS: return "MISCELLANEOUS";
        case Contact::Type::NONE: return "NONE";
        case Contact::Type::BUSINESS: return "BUSINESS";
        case Contact::Type::VENDOR: return "VENDOR";
        case Contact::Type::EMERGENCY: return "EMERGENCY";
        default: return "UNKNOWN";
        }
    }

    static Contact::Type stringToType(const string& str) {
        string s = str;
        for (auto& c : s) c = toupper(c);

        if (s == "WORK") return Contact::Type::WORK;
        if (s == "PERSONAL") return Contact::Type::PERSONAL;
        if (s == "SCHOOL") return Contact::Type::SCHOOL;
        if (s == "MISCELLANEOUS") return Contact::Type::MISCELLANEOUS;
        if (s == "NONE") return Contact::Type::NONE;
        if (s == "BUSINESS") return Contact::Type::BUSINESS;
        if (s == "VENDOR") return Contact::Type::VENDOR;
        if (s == "EMERGENCY") return Contact::Type::EMERGENCY;

        // Default fallback
        return Contact::Type::PERSONAL;
    }
};
