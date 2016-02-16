#include <iostream>
#include <iomanip>
using namespace std;
#include "Fraction.h"
#include "Person.h"
#include "Student.h"
#include "wk7Stack.h"

void init(char c, Fraction x[], int n) {
    for (int i = 0; i<n;i++){
        x[i].numden(i, n);
        cout<< c <<"=[" << setw(2) <<i<<"]="<<x[i]<<"  ";
        if (i % 5 == 4) {cout <<endl;}
    }
    cout << endl;
}

string trueOrFalse(bool condition) { return (condition ? "true" : "false"); }

int main() {
    cout<<right;
    
    Fraction x[20], y[10];
    init('x', x, sizeof(x)/sizeof(x[0]));
    init('y', y, sizeof(y)/sizeof(y[0]));
    
    for (int i = 1; i<3; i++) {
        cout<<x[i] << "+" << y[i] << " = " << (x[i] +y[i]) <<endl;
        cout<<x[i] << "-" << y[i] << " = " << (x[i] -y[i]) <<endl;
        cout<<x[i] << "*" << y[i] << " = " << (x[i] *y[i]) <<endl;
        cout<<x[i] << "/" << y[i] << " = " << (x[i] /y[i]) <<endl;
        
    }
    
    Fraction f = x[9];
    Fraction g = y[9];
    cout<<f<<" += " << g << " = " << (f+=g)<<endl;
    cout<<f<<" -= " << g << " = " << (f-=g)<<endl;
    cout<<f<<" *= " << g << " = " << (f*=g)<<endl;
    cout<<f<<" /= " << g << " = " << (f/=g)<<endl<<endl;
    
    cout << " . . . done." << endl<<endl;
    
    //////////////////////////////////////////////////////////////////////// Exercise 2:
    
    Person p("John Smith", "321 Wilson St.", "123-45-6789");
    Person q("John Smith", "123 Wilson St.", "123-45-6789");
    Person r("Joe Waters", "111 Main St.", "111-22-3333");
    
    cout<<"p is: " << p <<endl;
    //cout<<"q is: " << q << endl;
    //cout<<"r is: " << r << endl;
    
    Person aq;
    aq = q;
    cout << endl <<"assignment operator aq = q";
    cout << endl <<" q is: " << q;
    cout << endl <<"aq is: " << aq <<endl;
    
    cout<<endl <<"copy constructor cr = r";
    cout << endl << " r is: " << r;
    Person cr = r;
    cout<< endl << "cr is: " << cr << endl;
    
    cout << endl << "p == q ? " <<trueOrFalse(p == q) << endl << endl;
    
    Student st1(p, "CSUF", "CS");
    Student st2(p, "CSUF", "EE");
    
    cout << "st1 is: " << st1 << endl;
    cout<<"st2 is: " << st2 << endl;
    cout << "st1 == st2: " <<trueOrFalse(st1 == st2) <<endl<<endl;
    cout<<". . .done."<<endl<<endl;
    
    //////////////////////////////////////////////////////////////////////// Exercise 3:
    
    Stack st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(1);
    st.push(5);
    st.push(9);
    st.push(2);
    
    cout << st << endl;
    cout<<"now popping off the Stack entries one-by-one onto an undo Stack" << endl<<endl;
    Stack stUndo;
    while(!st.empty()) {
        int x = st.top();
        stUndo.push(x);
        st.pop();
    }
    cout<<"Stack is now: " << st << endl;
    cout<<"Undo stack is now: " << stUndo << endl;
    cout << ". . .done." << endl;
    
    return 0;
}
