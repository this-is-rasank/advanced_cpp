#include<iostream>
using namespace std;

class BaseClass{
    public:
    virtual ~BaseClass(){}
    virtual void print() const = 0;
    virtual BaseClass* clone() const = 0;
};

template <typename T>
class childClass : public BaseClass{
    private:
    T data;
    public:
    childClass(const T& value) : data(value) {}
    
    void print() const override {
        cout << data << endl;
    }
    
    BaseClass* clone() const override {
        return new childClass<T>(*this);
    }
};

// Rule of 3:
// 1. Destructor
// 2. Copy constructor
// 3. Copy assignment operator
// 4. (Optional) Move constructor
// 5. (Optional) Move assignment operator

class Any{
    private:
    // BaseClass poitner to childClass objects(Polymorphism)
    BaseClass* ptr;
    
    public:
    Any() : ptr(nullptr) {}
    
    template <typename T>
    // T& -> lvalue
    // const T& -> lvalue + rvalue
    // T&& ->  rvalue (move semantics)
    // T&& -> if Template perfect forwarding (lvalue + rvalue)
    Any(const T& value) : ptr(new childClass<T>(value)) {}
    
    // Copy constructor
    Any(const Any& other) : ptr(other.ptr ? other.ptr->clone() : nullptr) {}
    
    // Copy assignment operator
    Any& operator=(const Any& other) {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr ? other.ptr->clone() : nullptr;
        }
        return *this;
    }
    
    ~Any() {
        delete ptr;
    }
    
    void print() const {
        if (ptr) {
            ptr->print();
        } else {
            cout << "Empty Any" << endl;
        }
    }
};

int main() {
    Any a1 = 777;
    Any a2 = string("I am a String!");
    cout<< "a1: ";
    a1.print();
    cout<< "a2: ";
    a2.print();
    
    Any a3 = a1; // Copy constructor
    cout<< "a3 (copy of a1): ";
    a3.print();
    
    Any a4;
    a4 = a2; // Copy assignment operator
    cout<< "a4 (copy of a2): ";

    a4.print();
    
    return 0;
}