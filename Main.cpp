 /* Assisted by and Assisted line numbers: Dr.Su lines 39-44, 82-101, 152-222(Assignment 4 driver)
 
 * Matthew Young
 
 *This program will perform mathmatical functions with fractions, including addition, subtraction, multiplication,
 Division, and it will compare 2 fractions. It will also reduce fractions.
 
 */

// a Fraction object holds one Fraction number, one fraction
#include "frac2.h"
#include <iostream>
using namespace std;

Fraction::Fraction(int n, int d) {
    numerator = (d < 0 ? -n : n);   // Will determine the sign of the numerator
    denominator = (d < 0 ? -d : d); // Will determine the sign of the numerator
    reduce();
    
}

Fraction Fraction::operator+(const Fraction & r) {
    Fraction t;
    t.numerator = r.numerator * denominator + r.denominator * numerator; // Equation for addition in numerator
    t.denominator = r.denominator * denominator;                         // Equation for addition in denominator
    t.reduce();                                                          // Will reduce fraction
    return t;
    
}


Fraction Fraction::operator-(const Fraction & r) {
    Fraction t;
    t.numerator = numerator * denominator - r.numerator * r.denominator; // Equation for subtraction in numerator
    t.denominator = r.denominator * denominator;                         // Equation for subtraction in denominator
    t.reduce();                                                          // Will reduce fraction
    return t;
}


Fraction Fraction::operator*(const Fraction & r) {
    Fraction t;
    t.numerator = r.numerator * numerator;                               // Equation for multiplication in numerator
    t.denominator = r.denominator * denominator;                         // Equation for multiplication in denominator
    t.reduce();                                                          // Will reduce fraction
    return t;
}


Fraction Fraction::operator/(const Fraction & r) {
    Fraction t;
    t.numerator = r.denominator * numerator;                            // Equation for division in numerator
    t.denominator = r.numerator * denominator;                          // Equation for division in denominator
    t.reduce();                                                         // Will reduce fraction
    return t;
}

void Fraction::reduce() {
    int n = numerator < 0 ? -numerator : numerator; // Determines sign of numerator
    int d = denominator;
    int largest = n > d ? n : d;
    int gcd = 0;
    
    for (int loop = largest; loop >= 2; loop--) // Loop to reduce fractions
        if (numerator % loop == 0 && denominator % loop == 0) {
            gcd = loop;
            break;
            
        }
    
    if (gcd != 0) {
        numerator /= gcd;
        denominator /= gcd;
        
    }
    
}

std::ostream& operator<<(std::ostream& out, const Fraction& r){
    if (r.denominator == 0) {
        cout << endl << "DIVIDE BY ZERO ERROR!!!" << endl;
    }
    
    else if (r.denominator == 1) {
        cout << r.numerator << " or ";
        
    }
    
    return out << r.numerator << "/" << r.denominator;
}


bool Fraction::operator<(const Fraction & r) {
    bool g = true;
    
    if (numerator/denominator <  r.numerator/r.denominator){    // Lines 120-124 are the if/else statements to compare two fractions
        g = true;
    }
    
    else if (numerator/denominator >  r.numerator/r.denominator){
        g = false;
    }

    return g;
}




bool Fraction::operator>(const Fraction & r) {
    bool g = true;
    
    if (numerator/denominator >  r.numerator/r.denominator){      // Lines 137-143 are the if/else statements to compare two fractions
        g = true;
    }
    
    else if (numerator/denominator <=  r.numerator/r.denominator){
        g = false;
    }

    return g;
}





// driver for Fraction project part 2

#include <iostream>
#include "frac2.h"
using namespace std;

int main()
{
    Fraction c( 7, 3 ), d( 3, 9 ), x;

    //   c.printFraction();
    cout << c;
    cout << " + " ;
    //  d.printFraction();
    cout << d;
    cout << " = ";
    x = c + d;
    //   x.printFraction();
    cout << x;
    
    cout << '\n';
    //   c.printFraction();
    cout <<c;
    
    cout << " - " ;
    //   d.printFraction();
    cout << d;
    cout << " = ";
    x = c - d;
    //   x.printFraction();
    cout <<x;
    
    cout << '\n';
    //   c.printFraction();
    cout << c;
    cout << " * " ;
    //   d.printFraction();
    cout << d;
    cout << " = ";
    x = c * d;
    //   x.printFraction();
    cout <<x;
    
    cout << '\n';
    //   c.printFraction();
    cout <<c;
    cout << " / " ;
    //   d.printFraction();
    cout << d;
    cout << " = ";
    x = c / d;
    //   x.printFraction();
    cout << x;
    
    cout << '\n';
    //   c.printFraction();
    cout << c;
    cout << " is:\n";
    
    cout << ( ( c > d ) ? "  > " : "  <= " );
    //   d.printFraction();
    cout << d;
    cout << " according to the overloaded > operator\n";
    
    cout << ( ( c < d ) ? "  < " : "  >= " );
    //   d.printFraction();
    cout << d;
    cout << " according to the overloaded < operator\n";
    
    return 0;
}
