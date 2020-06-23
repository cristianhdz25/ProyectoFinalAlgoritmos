#include "Client.h"



Client::Client(string age, string name, string gender, string numPassport, string password, Pais* nationality) {
    this->age=age;
    this->name=name;
    this->gender=gender;
    this->numPassport=numPassport;
    this->nationality=nationality;
    this->password=password;
    this->travel=NULL;
}//constructor

Client::Client(){
}

void Client::SetNumPassport(string numPassport) {
    this->numPassport = numPassport;
}

string Client::GetNumPassport() const {
    return numPassport;
}

void Client::SetGender(string gender) {
    this->gender = gender;
}

string Client::GetGender() const {
    return gender;
}

void Client::SetName(string name) {
    this->name = name;
}

string Client::GetName() const {
    return name;
}

void Client::SetAge(string age) {
    this->age = age;
}

string Client::GetAge() const {
    return age;
}

void Client::SetTravel(Itinerario* travel) {
    this->travel = travel;
}

Itinerario* Client::GetTravel() const {
    return travel;
}

void Client::SetNationality(Pais* nationality) {
    this->nationality = nationality;
}

Pais* Client::GetNationality() const {
    return nationality;
}

void Client::SetPassword(string password) {
    this->password = password;
}

string Client::GetPassword() const{
    return password;
}

string Client::toString() {
    stringstream s;
    s<<this->age<<this->name<<this->gender<<this->nationality<<this->numPassport<<this->travel->toString();
    return s.str();
}//toString