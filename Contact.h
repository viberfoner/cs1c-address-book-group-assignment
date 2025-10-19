#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <iostream>
#include <vector>
class Contact{
    public: 
        enum Type{ WORK, PERSONAL, SCHOOL, MISCELLANEOUS, NONE };  
        Contact();
        Contact(const std::string& firstName, const std::string& lastName, long long phoneNumber, const std::string& address, const std::string& email, Type type);
        Contact(const std::string& firstName, const std::string& lastName, long long phoneNumber);

        void setFirstName(std::string newFirstName);
        void setLastName(std::string newLastName);
        void setPhoneNumber(long long newPhoneNumber);
        void setAddress(std::string newAddress);
        void setEmail(std::string newEmail);
        void setType(Type newType);
        std::string getFirstName();
        std::string getLastName();
        std::string getPhoneNumber();
        std::string getAddress();
        std::string getEmail();
        Type getType();
        static int incrementId();
        std:: string typeToString(Type type);
        void printContact();

    private:
        static int idCount;
        int id; 
        std::string firstName;
        std::string lastName;
        long long phoneNumber;
        std::string address;
        std::string email;
        Type type;
        std::vector<std::string> groups;
        std::string formatPhoneNumber();
        
};

#endif