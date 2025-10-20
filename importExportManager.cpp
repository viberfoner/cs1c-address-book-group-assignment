#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

// Forward declaration
enum class ContactType;
class Contact;

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
    static vector<Contact> readCsv(const string& filename) {
        vector<Contact> importedContacts;
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: Could not open file for reading.\n";
            return importedContacts;
        }

        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;

            Contact c = parseContact(line);
            importedContacts.push_back(c);
        }

        file.close();
        cout << "Contacts imported successfully.\n";
        return importedContacts;
    }

    // -----------------------------
    // Write Contacts to CSV
    // -----------------------------
    // Saves all contacts from memory into a CSV file.
    static void writeCsv(const vector<Contact>& contacts, const string& filename) {
        ofstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: Could not open file for writing.\n";
            return;
        }

        // Optional: Write a header row
        file << "id,firstName,lastName,phoneNumber,address,email,type\n";

        for (const auto& c : contacts) {
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
        ContactType type = stringToType(typeStr);

        // Example constructor:
        // Contact(unsigned int id, string fn, string ln, string phone,
        //         string addr, string email, ContactType type)
        return Contact(id, firstName, lastName, phoneNumber, address, email, type);
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
    static string typeToString(ContactType type) {
        switch (type) {
        case ContactType::WORK: return "WORK";
        case ContactType::PERSONAL: return "PERSONAL";
        case ContactType::SCHOOL: return "SCHOOL";
        case ContactType::MISCELLANEOUS: return "MISCELLANEOUS";
        case ContactType::NONE: return "NONE";
        case ContactType::BUSINESS: return "BUSINESS";
        case ContactType::VENDOR: return "VENDOR";
        case ContactType::EMERGENCY: return "EMERGENCY";
        default: return "UNKNOWN";
        }
    }

    static ContactType stringToType(const string& str) {
        string s = str;
        for (auto& c : s) c = toupper(c);

        if (s == "WORK") return ContactType::WORK;
        if (s == "PERSONAL") return ContactType::PERSONAL;
        if (s == "SCHOOL") return ContactType::SCHOOL;
        if (s == "MISCELLANEOUS") return ContactType::MISCELLANEOUS;
        if (s == "NONE") return ContactType::NONE;
        if (s == "BUSINESS") return ContactType::BUSINESS;
        if (s == "VENDOR") return ContactType::VENDOR;
        if (s == "EMERGENCY") return ContactType::EMERGENCY;

        // Default fallback
        return ContactType::PERSON;
    }
};
