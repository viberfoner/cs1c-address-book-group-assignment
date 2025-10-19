#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
class Contact{
    public: 
        enum Type{ WORK, PERSONAL, SCHOOL, MISCELLANEOUS, NONE, BUSINESS, VENDOR, EMERGENCY};  
        Contact();
        Contact(const std::string& firstName, const std::string& lastName, std::string& phoneNumber, const std::string& address, const std::string& email, Type type);
        Contact(const std::string& firstName, const std::string& lastName, std::string& phoneNumber);

        void setFirstName(std::string newFirstName);
        void setLastName(std::string newLastName);
        void setPhoneNumber(std::string newPhoneNumber);
        void setAddress(std::string newAddress);
        void setEmail(std::string newEmail);
        void setType(Type newType);
        void addTag(std::string tag);
        void deleteTag(std::string tag);
        int getId();
        std::string getFirstName();
        std::string getLastName();
        std::string getPhoneNumber();
        std::string getAddress();
        std::string getEmail();
        Type getType();
        static int incrementId();
        std:: string typeToString(Type type);
        void printContact();
        std::vector<std::string> getTags();
        std::vector<std::string> getGroups();

    private:
        static int idCount;
        int id; 
        std::string firstName;
        std::string lastName;
        std::string phoneNumber;
        std::string address;
        std::string email;
        Type type;
        std::vector<std::string> groups;
        std::vector<std::string> tags;
        std::string formatPhoneNumber();
        
};

#endif