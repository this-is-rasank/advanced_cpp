#include<iostream>
using namespace std;

class Rational
{   
    public:
        int num,den;
        Rational(int num,int den)
        {
            this->num=num;
            this->den=den;
        }
        Rational operator +(Rational r)
        {
            int num=this->num*r.den + this->den*r.num;
            int den=this->den*r.den;
            return Rational(num, den);
        }
};

int main()
{
    Rational r1(1,2);
    Rational r2(1,3);
    Rational r3=r1+r2;
    cout<<r3.num<<"/"<<r3.den;
    return 0;
}