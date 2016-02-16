#include "Fraction.h"
#include <fstream>
using namespace std;

Fraction::Fraction()
: Fraction(0) {   }

Fraction::Fraction(int num)
: _num(num) , _den(1) {}

Fraction::Fraction(int num, int den)
: _num(num), _den(den) {
    simplify();
}

int Fraction::num() const {return _num;}
int Fraction::den() const {return _den;}

void Fraction::num(int num) {_num = num;}
void Fraction::den(int den) {
    if (den == 0) {cout<<"cannot set denominator = 0 . . .error";}
    else{_den = den;}
}

void Fraction::numden(int i, int n){
    _num = i, _den = n;
    simplify();
}

ostream& operator<<(ostream& os, const Fraction& fr){
    if(fr.den() == 0){return os<<"Fraction cannot be divided with numerator of 0 . . .error";}
    return os<<"Fraction [num=" <<fr._num<<",den=" <<fr._den<<"]";
}

void Fraction::simplify(){
    for (int gcd = _num; gcd > 1; gcd--)
    {
        if (_num != 1)
        {
            if ((_den% gcd == 0) && (_num % gcd == 0))
            {
                _num /= gcd;
                _den /= gcd;
            }
        }
    }
    if (_num == 0){ _den = 1;}
}

Fraction operator+(const Fraction& f1, const Fraction& f2){
    return Fraction (f1.num()*f2.den() + f1.den()*f2.num(), f1.den()*f2.den());
}


Fraction operator-(const Fraction& f1, const Fraction& f2){
    return Fraction (f1.num()*f2.den() - f1.den()*f2.num(), f1.den()*f2.den());
}

Fraction operator*(const Fraction& f1, const Fraction& f2){
    return Fraction(f1.num()*f2.num(), f1.den()*f2.den());
}

Fraction operator/(const Fraction& f1, const Fraction& f2){
    if (f2.num() == 0){cout <<"denominator = 0 . . . error";}
    return Fraction(f1.num()*f2.den(), f1.den()*f2.num());
}

Fraction& Fraction::operator+=(const Fraction& fother){
    _num = _num * fother._den + _den * fother._num;
    _den *= fother._den;
    simplify();
    return  *this;
}

Fraction& Fraction::operator-=(const Fraction& fother){
    _num = _num*fother._den - _den*fother._num;
    _den *= fother._den;
    simplify();
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& fother){
    _num *= fother._num;
    _den *= fother._den;
    simplify();
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& fother){
    _num *= fother._den;
    _den *= fother._num;
    simplify();
    return *this;
}






