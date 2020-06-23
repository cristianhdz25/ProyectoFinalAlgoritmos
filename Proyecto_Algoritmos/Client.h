#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>
#include "Pais.h"

#include "Aerolinea.h"

using namespace std;
class Client {
public:
    Client(string age, string name, string gender, string numPassport,string password, Pais* nationality);
    Client();
    void SetNumPassport(string numPassport);
    string GetNumPassport() const;
    void SetGender(string gender);
    string GetGender() const;
    void SetName(string name);
    string GetName() const;
    void SetAge(string age);
    string GetAge() const;
    string toString();
    void SetTravel(Itinerario* travel);
    Itinerario* GetTravel() const;
    void SetNationality(Pais* nationality);
    Pais* GetNationality() const;
    void SetPassword(string password);
    string GetPassword() const;

private:
    string age, name, gender, numPassport, password;
    Pais* nationality;
    Itinerario* travel;
};
#endif /* CLIENT_H */
