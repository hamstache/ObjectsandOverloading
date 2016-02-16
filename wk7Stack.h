#ifndef __wk7_wk7Stack__
#define __wk7_wk7Stack__

#include <iostream>
using namespace std;
#include <stdexcept>

class Stack {
public:
    Stack(int max = 100);
    Stack(const Stack& other); //copy constructor
    Stack& operator=(const Stack& other); //assignment operator
    ~Stack(); // destructor
    
    int size() const;
    int max() const;
    
    int top() const;
    void pop(); //copy constructor
    void push(int val); // attempting to push onto a full stack. . .ditto
    bool empty() const; // Check first!
    
    bool operator==(const Stack& other) const;
    bool operator!=(const Stack& other) const;
    friend ostream& operator<<(ostream& os, const Stack& st );
    
private:
    void copy(const Stack& other);
private:
    int _top, _max;
    int* _data;
    
};

#endif 