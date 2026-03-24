#include <iostream>
using namespace std;

class Function
{
public:
    int power;
    Function(int power) : power(power) {};
    // Class object that can be called like a function
    // overloading operator "()" to make the class a functor
    int operator()(int x)
    {
        int result = 1;
        for (int i = 0; i < power; i++)
        {
            result *= x;
        }
        return result;
    };
};

int main()
{
    Function cube = Function(3);
    Function square = Function(2);
    cout << cube(2) << endl;
    // calculates 2^3
    cout << square(2) << endl;
    // calculates 2^2
    return 0;
}