#include <iostream>
#include <utility>

#include "rational.h"

// private функции

int rational::get_gcd()
{
    int a = num, b = den;

    if (b > a)
        std::swap(a, b);

    while (b)
    {
        a %= b;
        std::swap(a, b);
    }

    return a;
}

void rational::normalize()
{
    int gcd = get_gcd();
    num /= gcd;
    den /= gcd;
}

// конструктор, деструктор и конструктор копирования

rational::rational(int _num = 0, int _den = 1): num(_num), den(_den)
{
    std::cout << "Создано рациональное число." << std::endl;
}

rational::~rational()
{
    std::cout << "Уничтожено рациональное число." << std::endl;
}

rational::rational (const rational& other): num(other.num), den(other.den)
{
    std::cout << "Скопировано значение." << std::endl;
}

// перегрузки операторов

rational::operator double()
{
    return (double)num / den;
}

rational rational::operator+(rational other)
{
    rational res = rational();

    res.num = num * other.den + other.num * den;
    res.den = den * other.den;

    res.normalize();

    return res;
}

rational rational::operator+(int other)
{
    rational res;

    res.num = num + other * den;
    res.den = den;

    res.normalize();

    return res;
}

rational rational::operator+=(rational other)
{
    num = num * other.den + other.num * den;
    den = den * other.den;

    normalize();

    return *this;
}

rational rational::operator+=(int other)
{
    num += other * den;

    normalize();

    return *this;
}

std::ostream& operator<<(std::ostream& stream, rational& x)
{
    stream << x.num << "/" << x.den;
    return stream;
}
