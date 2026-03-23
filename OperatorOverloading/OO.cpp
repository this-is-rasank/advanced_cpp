#include <iostream>
using namespace std;

class Rational
{
public:
    int num, den;
    Rational(int num, int den);
    Rational operator+(Rational r);
};

Rational::Rational(int num = 0, int den = 1) : num(num), den(den) {};

Rational Rational::operator+(Rational r)
{
    Rational temp;
    temp.num = this->num * r.den + this->den * r.num;
    temp.den = this->den * r.den;
    return temp;
}

int main()
{
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational r3 = r1 + r2;
    cout << r3.num << "/" << r3.den;
    return 0;
}