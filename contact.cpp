#include "contact.h"

/*int id;
std::string firstName;
std::string lastName;
int phoneNumber;
std::string address;
std::string email;
enum Type {WORK, PERSONAL, SCHOOL, MISCELLANEOUS};
std::string formatPhoneNumber(int phoneNumber);
std::vector<std::string> groups;*/
int Contact::idCount = 0;

Contact::Contact(){
    id = incrementId();
    this->firstName = "No";
    this->lastName = "Name";
    this->phoneNumber = 0;
    this->address = " ";
    this->email = " ";
    this->type = NONE;
}
Contact::Contact(const std::string& firstName, const std::string& lastName, long long phoneNumber, const std::string& address, const std::string& email, Contact::Type type){
    id = incrementId();
    this->firstName = firstName;
    this->lastName = lastName;
    this->phoneNumber = phoneNumber;
    this->address = address;
    this->email = email;
    this->type = type;
}
Contact::Contact(const std::string& firstName, const std::string& lastName, long long phoneNumber){
    id = incrementId();
    this->firstName = firstName;
    this->lastName = lastName;
    this->phoneNumber = phoneNumber;
    this->address = " ";
    this->email = " ";
    this->type = NONE;
}

void Contact::setFirstName(std::string newFirstName){
    firstName = newFirstName;
}
void Contact::setLastName(std::string newLastName){
    lastName = newLastName;
}
void Contact::setPhoneNumber(long long newPhoneNumber){ 
    phoneNumber = newPhoneNumber;
}
void Contact::setAddress(std::string newAddress){
    address = newAddress;
}
void Contact::setEmail(std::string newEmail){
    email = newEmail;
}
void Contact::setType(Contact::Type newType){
    type = newType;
}
std::string Contact::getFirstName(){
    return firstName;
}
std::string Contact::getLastName(){
    return lastName;
}
std::string Contact::getPhoneNumber(){
    return formatPhoneNumber();
}
std::string Contact::getAddress(){
    return address;
}
std::string Contact::getEmail(){
    return email;
}
Contact::Type Contact::getType(){
    return type;
}
int Contact::incrementId(){
    idCount += 1;
    return idCount;
}
std::string Contact::typeToString(Contact::Type type){
    switch (type){
        case WORK: return "Work";
        case PERSONAL: return "Personal";
        case SCHOOL: return "School";
        case MISCELLANEOUS: return "Misc.";
        case NONE: return "None";
    }
return "Unknown";
}
void Contact::printContact(){
    std::cout << firstName << " " << lastName << ":" << "\n";
    if (phoneNumber == 0 && address == " " && email == " " && type == NONE){
        std::cout << "No contact information\n\n";
    }
    else{
        std::cout << "Phone Number: " << getPhoneNumber() << "\n";
        std::cout << "Email: " << getEmail() << "\n";
        std::cout << "Address: " << getAddress() << "\n";
        if(type != NONE){
            std::cout << "Type:" << typeToString(this->type) << "\n\n";
        }
        else{
            std::cout << "Type: " << "\n\n";
        }
    } 
}
std::string Contact::formatPhoneNumber(){
    std::string numberString = std::to_string(phoneNumber);
    if (phoneNumber == 0){
        return "(000) 000-000";
    }
    else{
        return ("(" + numberString.substr(0,3) + ")" + numberString.substr(3,3) + "-" + numberString.substr(6,4));
    }
}