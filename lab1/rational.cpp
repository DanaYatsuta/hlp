#include <iostream>
#include "rational.h"

// private функции

int rational::get_gcd()
{
    int a = num, b = den;

    while (a && b)
    {
        if (a > b) a %= b;
        else b %= a;
    }

    return a + b;
}

void rational::normalize()
{
    int gcd = get_gcd();
    num /= gcd;
    den /= gcd;
}

// конструктор, деструктор и конструктор копирования

rational::rational(int _num = 1, int _den = 1): num(_num), den(_den)
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
    rational res = rational();

    res.num = num + other * den;
    res.den = den;

    res.normalize();

    return res;
}

void rational::operator+=(rational other)
{
    num = num * other.den + other.num * den;
    den = den * other.den;

    normalize();
}

void rational::operator+=(int other)
{
    num += other * den;

    normalize();
}

std::ostream& operator<<(std::ostream& stream, rational& x)
{
    stream << x.num << "/" << x.den;
    return stream;
}