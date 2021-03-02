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

    explicit operator double();

    rational operator+(rational other);
    rational operator+(int other);

    rational operator+=(rational other);
    rational operator+=(int other);

    friend std::ostream& operator<<(std::ostream& stream, rational& x);
};

#endif // RATIONAL_H_INCLUDED
