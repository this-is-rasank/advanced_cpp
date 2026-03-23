#include <iostream>
using namespace std;

class Rational
{
public:
    int num, den, whole;
    Rational(int num, int den, int whole);
    Rational reduce();
    void print()
    {
        cout << whole << " " << num << "/" << den;
    }
    Rational operator+(Rational r);
};

Rational::Rational(int num = 0, int den = 1, int whole = 0) : num(num), den(den), whole(whole) {};

Rational Rational::reduce()
{
    int gcd = 1;
    for (int i = 1; i <= num && i <= den; i++)
    {
        if (num % i == 0 && den % i == 0)
            gcd = i;
    }
    num /= gcd;
    den /= gcd;
    if (num >= den)
    {
        whole += num / den;
        num %= den;
    }
    return *this;
}

Rational Rational::operator+(Rational r)
{
    Rational temp;
    temp.num = this->num * r.den + this->den * r.num;
    temp.den = this->den * r.den;
    temp.whole = this->whole + r.whole;
    return temp;
}

int main()
{
    Rational r1(3, 2);
    Rational r2(1, 3);
    Rational r3 = (r1 + r2).reduce();
    r3.print();
    return 0;
}