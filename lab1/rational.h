#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <iostream>

class rational
{
    int num, den;

    int get_gcd();
    void normalize();

public:
    rational(int _num, int _den);
    ~rational();
    rational (const rational& other);

    operator double();

    rational operator+(rational other);
    rational operator+(int other);

    void operator+=(rational other);
    void operator+=(int other);

    friend std::ostream& operator<<(std::ostream& stream, rational& x);
};

#endif // RATIONAL_H_INCLUDED
