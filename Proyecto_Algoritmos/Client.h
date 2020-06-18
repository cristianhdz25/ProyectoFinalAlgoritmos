#ifndef CLIENT_H
#define CLIENT_H

#include <string>

using namespace std;
class Client {
public:
    Client(string age, string name, string gender, string numPassport, string nationality);
    void SetNationality(string nationality);
    string GetNationality() const;
    void SetNumPassport(string numPassport);
    string GetNumPassport() const;
    void SetGender(string gender);
    string GetGender() const;
    void SetName(string name);
    string GetName() const;
    void SetAge(string age);
    string GetAge() const;

    
private:
    string age;
    string name;
    string gender;
    string numPassport;
    string nationality;
};
#endif /* CLIENT_H */
