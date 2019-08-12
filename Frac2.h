 /* Assisted by and Assisted line numbers: Dr.Su lines 47, 65, 56
 
 * Matthew Young
 
 *This program is used in the main.cpp (frac2.cpp) to help perform operations and it is separate to help organize
 and simplify the code.
 
 */

#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;



class Fraction
{
public:
    
    Fraction(int n, int d, char x);
    Fraction (int = 0, int = 1);        // default constructor
    
    Fraction operator+(const Fraction & r); // lines 49-56 are overloaded operators to perform operations within frac2.cpp
    Fraction operator-(const Fraction & r);
    Fraction operator*(const Fraction & r);
    Fraction operator/(const Fraction & r);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& r);
    bool operator<(const Fraction& r);
    bool operator>(const Fraction& r);
    

private:
    
    int numerator;
    int denominator;
    char x; 
    
    
    void reduce();                         // utility function, reduce to lowest terms
};

#endif
