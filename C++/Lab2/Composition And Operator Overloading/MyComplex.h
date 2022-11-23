#pragma once

#include <iostream>

using std::ostream;
using std::istream;

class MyComplex
{
private:
    double real, imaginary;
public:
    MyComplex() : real(0), imaginary(0) {}
    MyComplex(double real) : real(real), imaginary(0) {}
    MyComplex(double real, double imaginary) : real(real), imaginary(imaginary) {}
    
    MyComplex operator + (const MyComplex& c) const { return MyComplex(real + c.real, imaginary + c.imaginary); }
    MyComplex operator - (const MyComplex& c) const { return MyComplex(real - c.real, imaginary - c.imaginary); }
    MyComplex operator * (const MyComplex& c) const
    {
        return MyComplex(
                        (real * c.real - imaginary * c.imaginary),
                        (imaginary * c.real + real * c.imaginary)
        );
    }
    MyComplex operator / (const MyComplex& c) const
    {
        return MyComplex(
                        (real * c.real + imaginary * c.imaginary) / (c.real * c.real + c.imaginary * c.imaginary),
                        (imaginary * c.real - real * c.imaginary) / (c.real * c.real + c.imaginary * c.imaginary)
        );
    }
    
    void operator += (const MyComplex& c) { *this = *this + c; }
    void operator -= (const MyComplex& c) { *this = *this - c; }
    void operator *= (const MyComplex& c) { *this = *this * c; }
    void operator /= (const MyComplex& c) { *this = *this / c; }

    MyComplex& operator ++ ()
    {
        this->real += 1;
        return *this;
    }
    MyComplex operator ++ (int)
    {
        MyComplex myComplexTemp = *this;
        ++*this;
        return myComplexTemp;
    }
    MyComplex& operator -- ()
    {
        this->real -= 1;
        return *this;
    }
    MyComplex operator -- (int)
    {
        MyComplex myComplexTemp = *this;
        --*this;
        return myComplexTemp;
    }

    bool operator == (const MyComplex& c) const { return real == c.real && imaginary == c.imaginary; }
    bool operator != (const MyComplex& c) const { return !(*this == c); }

    friend ostream& operator << (ostream& output, const MyComplex& c);
    friend istream& operator >> (istream& input, MyComplex& c);

};