#include <iostream>
#ifndef __Student_
#define __Student_

#include <string>
#include "Person.h"
using namespace std;

class Student: public Person {
public:
    Student();
    Student(const Person& p, const string& schoolName, const string& major);
    Student(const Student& other); //copy constructor
    Student& operator=(const Student& other); //assignment operator
    ~Student();   //destructor
    
    string schoolName() const;
    string major() const;
    
    void schoolName(const string& schoolName);
    void major(const string& major);
    
    friend ostream& operator<<(ostream& os, const Student& st);
    bool operator==(const Student& stOther) const;
    bool operator!=(const Student& stOther) const;
    
private:
    void copy(const Student& other);
    
private:
    string _schoolName;
    string _major;
};

#endif