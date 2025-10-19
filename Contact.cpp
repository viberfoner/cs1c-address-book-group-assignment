#include "Contact.h"

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
    this->phoneNumber = " ";
    this->address = " ";
    this->email = " ";
    this->type = NONE;
}
Contact::Contact(const std::string& firstName, const std::string& lastName, std::string& phoneNumber, const std::string& address, const std::string& email, Contact::Type type){
    id = incrementId();
    this->firstName = firstName;
    this->lastName = lastName;
    this->phoneNumber = phoneNumber;
    this->address = address;
    this->email = email;
    this->type = type;
}
Contact::Contact(const std::string& firstName, const std::string& lastName, std::string& phoneNumber){
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
void Contact::setPhoneNumber(std::string newPhoneNumber){ 
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
    return phoneNumber;
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
int Contact::getId(){
    return id;
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
        case VENDOR: return "Vendor";
        case BUSINESS: return "Business";
        case EMERGENCY: return "Emergency";
    }
return "Unknown";
}
void Contact::printContact(){
    std::cout << firstName << " " << lastName << ":" << "\n";
    if (phoneNumber == " " && address == " " && email == " " && type == NONE && tags.empty()){
        std::cout << "No contact information\n\n";
    }
    else{
        std::cout << "Phone Number: " << formatPhoneNumber() << "\n";
        std::cout << "Email: " << email << "\n";
        std::cout << "Address: " << address << "\n";
        if(type != NONE){
            std::cout << "Type: " << typeToString(this->type) << "\n";
        }
        else{
            std::cout << "Type: " << "\n\n";
        }
        std::cout << "Tags: ";
        for (int i = 0; i < tags.size(); i++){
            if(i != tags.size() - 1){std::cout << tags[i] << ", ";}
            else{std::cout << tags[i];}
        }
        std::cout << "\n\n";
    } 
}
std::string Contact::formatPhoneNumber(){
    if (phoneNumber == " "){
        return "(000) 000-000";
    }
    else{
        return ("(" + phoneNumber.substr(0,3) + ")" + phoneNumber.substr(3,3) + "-" + phoneNumber.substr(6,4));
    }
}
void Contact::addTag(std::string tag){
    if(find(tags.begin(), tags.end(), tag) != tags.end()){
        std::cout << tag << " is already assigned to this contact \n\n";
    }
    else{
        tags.push_back(tag);
    }
}
void Contact::deleteTag(std::string tag){
    std::vector<std::string>::iterator toDelete = find(tags.begin(), tags.end(), tag);
    tags.erase(toDelete);
}
std::vector<std::string> Contact::getTags(){
    return tags;
}
std::vector<std::string> Contact::getGroups(){
    return groups;
}