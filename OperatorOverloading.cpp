#include<bits/stdc++.h>

using namespace std;

class Complex {
    int real, imag;
public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // normal function
    Complex add(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // operator overloading
    Complex operator + (const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() {
        cout << real << " + " << imag << "i\n";
    }
};



int main() {
    Complex c1(3, 2), c2(1, 7);

    Complex c3 = c1.add(c2); // looks clumsy
    c3.display();            // 4 + 9i

    Complex c4 = c1 + c2;   // ✅ looks natural
    c4.display();           // 4 + 9i
}


/*
Operator overloading means redefining how an operator works for user-defined types (classes/structs).

Rules of Operator Overloading

    You can overload most operators, but not all.
    ❌ Cannot overload: :: (scope resolution), . (dot), .*, sizeof, ?:, typeid.

    At least one operand must be a user-defined type (you can’t redefine int + int).

    Overloaded operators are just functions with a special name:
    operator+ for +
    operator- for -
    etc.

    You can overload operators as member functions or friend functions.

Commonly Overloaded Operators

    Arithmetic: +, -, *, /, %
    Comparison: ==, !=, <, >, <=, >=
    Assignment: =, +=, -=, *=
    Stream: <<, >> (for cout, cin)
    Index: []
    Function call: ()
    Increment/decrement: ++, --
*/