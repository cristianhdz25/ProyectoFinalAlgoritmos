#include "Client.h"

Client::Client(string age, string name, string gender, string numPassport, string nationality) {
    this->age=age;
    this->name=name;
    this->gender=gender;
    this->numPassport=numPassport;
    this->nationality=nationality;
}//constructor

void Client::SetNationality(string nationality) {
    this->nationality = nationality;
}

string Client::GetNationality() const {
    return nationality;
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

