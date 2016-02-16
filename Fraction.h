#ifndef __Project_Fraction__
#define __Project_Fraction__


#include <iostream>
using namespace std;

class Fraction {
public:
    Fraction();
    Fraction(int num);
    Fraction(int num, int den);
    
    int num() const;
    int den() const;
    
    void num (int num);
    void den(int den);
    void numden(int i, int n);
    
    Fraction& operator+=(const Fraction& fother);
    Fraction& operator-=(const Fraction& fother);
    Fraction& operator*=(const Fraction& fother);
    Fraction& operator/=(const Fraction& fother);
    
    friend ostream& operator<<(ostream& os, const Fraction& fr);
    
    void simplify();
    friend Fraction operator+(const Fraction& f1, const Fraction& f2);
    friend Fraction operator-(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator/(const Fraction& f1, const Fraction& f2);
    
private:
    int _num, _den;
};

#endif

