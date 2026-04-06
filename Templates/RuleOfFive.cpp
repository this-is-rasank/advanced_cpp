#include <iostream>
using namespace std;

class BaseClass
{
public:
    BaseClass() {}
    virtual ~BaseClass() {}
    virtual void print() const = 0;
    virtual BaseClass *clone() const = 0;
};

template <typename T>
class childClass : public BaseClass
{
private:
    T data;

public:
    childClass(const T &value) : data(value) {}

    void print() const override
    {
        cout << data << endl;
    }

    BaseClass *clone() const override
    {
        return new childClass<T>(*this);
    }
};

// Rule of 3:
// 1. Destructor
// 2. Copy constructor
// 3. Copy assignment operator
// 4. (Optional) Move constructor
// 5. (Optional) Move assignment operator

class Any
{
private:
    // BaseClass poitner to childClass objects(Polymorphism)
    BaseClass *ptr;

public:
    Any() : ptr(nullptr) {}

    template <typename T>
    // T& -> lvalue
    // const T& -> lvalue + rvalue
    // T&& ->  rvalue (move semantics)
    // T&& -> if Template perfect forwarding (lvalue + rvalue)
    Any(const T &value) : ptr(new childClass<T>(value))
    {
        cout << "=> Any constructor called" << endl;
    }

    // Copy constructor(Will handle only lvalues if move constructor present)
    Any(Any &other) : ptr(other.ptr ? other.ptr->clone() : nullptr) { cout << "=> Any copy constructor called" << endl; }

    // Move constructor
    Any(Any &&other) noexcept : ptr(other.ptr)
    {
        cout << "=> Any move constructor called" << endl;
        other.ptr = nullptr;
    }

    // Copy assignment operator
    Any &operator=(Any &other)
    {
        cout << "=> Any copy assignment operator called" << endl;
        if (this != &other)
        {
            delete ptr;
            ptr = other.ptr ? other.ptr->clone() : nullptr;
        }
        return *this;
    }

    // move assignment operator
    Any &operator=(Any &&other) noexcept
    {
        cout << "=> Any move assignment operator called" << endl;
        if (this != &other)
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    ~Any()
    {
        delete ptr;
    }

    void print() const
    {
        if (ptr)
        {
            ptr->print();
        }
        else
        {
            cout << "Empty Any" << endl;
        }
    }
};

int main()
{
    Any a1 = 777;
    Any a2 = string("I am a String!");
    cout << "a1: ";
    a1.print();
    cout << "a2: ";
    a2.print();

    Any a3 = a1; // Copy constructor
    cout << "a3 (copy of a1): ";
    a3.print();

    Any a4;
    a4 = a2; // Copy assignment operator
    cout << "a4 (copy of a2): ";

    a4.print();

    Any a5 = std::move(a1); // Move assignment operator
    cout << "a5 (moved from a1): ";
    a5.print();

    Any a6;
    a6 = std::move(5.57); // Move constructor
    cout << "a6 (moved from 5.57): ";
    a6.print();

    return 0;
}