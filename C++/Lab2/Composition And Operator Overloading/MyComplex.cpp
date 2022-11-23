#include "MyComplex.h"

ostream& operator << (ostream& output, const MyComplex& c)
{
    if (c.real != 0)
    {
        if (c.imaginary > 0)  output << c.real << '+' << c.imaginary << 'i';
        else if (c.imaginary == 0) output << c.real;
        else if (c.imaginary < 0) output << c.real << c.imaginary << "i";
    }
    else if(c.real == 0)
    {
        if (c.imaginary != 0)  output << c.imaginary << 'i';
        else if (c.imaginary == 0) output << 0;
    }
    return output;
}
istream& operator >> (istream& input, MyComplex& c)
{
    double a, b;
    char sign, i;
    input >> a >> sign >> b >> i;
    c.real = a;
    c.imaginary = (sign == '+') ? b : -b;
    return input;
}