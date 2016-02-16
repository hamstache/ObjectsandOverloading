#ifndef _Person_h_
#define _Person_h_

#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person();
    Person(const string& name, const string& address, const string& ssn);
    Person(const Person& pOther);   //copy constructor
    Person& operator=(const Person& other); //assignment operator
    ~Person();      //destructor
    
    
    string name() const;
    string address() const;
    string ssn() const;
    
    void name(const string& name);
    void address(const string& address);
    void ssn(const string& ssn);
    
    friend ostream& operator<<(ostream& os, const Person& p);
    bool operator==(const Person& pOther) const;
    bool operator!=(const Person& pOther) const;
    
private:
    Person& copy( const Person& other);
    
private:
    string _name;
    string _address;
    string _ssn;
    
};

#endif

