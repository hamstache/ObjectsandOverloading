#include "Person.h"

#include "Student.h"



Person::Person()                                            : Person("no name", "no address", "no ssn")                    {}

Person::Person(const string& name, const string& address, const string& ssn)   : _name(name), _address(address) , _ssn(ssn)                   {}

Person::Person(const Person& pOther)                        : _name(pOther._name), _address(pOther._address), _ssn(pOther._ssn)    { copy(pOther);}


string Person::name() const                 {return _name;}
string Person::address() const              {return _address;}
string Person::ssn() const                  {return _ssn;}

void Person::name(const string& name)       {_name = name;}
void Person::address(const string& address) {_address = address;}
void Person::ssn(const string& ssn)         {_ssn = ssn; }

Person& Person::copy(const Person& other) { //private helper function
    _name = other._name;
    _address = other._address;
    _ssn = other._ssn;
    return *this;
}


Person& Person::operator=(const Person& other) {
    if (this != &other) { copy(other); }
    return *this;
}

Person::~Person() {  }

ostream& operator<<(ostream& os, const Person& p) {
    return os<<"Person[name = "<<p._name<<", address = "<<p._address<<", ssn= "<<p._ssn << "]";
}

bool Person::operator==(const Person& pOther) const {
    return _name    == pOther._name     &&
    _address == pOther._address;
}

bool Person::operator!=(const Person& pOther) const {
    
    return !(*this == pOther);
    
}

