#include<iostream>
#include<concepts>

using namespace std;

// C++ 23 compatible "g++ -std=c++23 .\Templates\ConceptsConstraints.cpp"

// defining custom concept
// template<typename T>
// concept Numeric =  requires(T a){
//     a + 1; a*1;
// };

template<typename T>
// constraint requires concept
requires integral<T> || floating_point<T>

// template<typename T>
// // using custom defined conceppt
// requires Numeric<T>
T addIt(T a){
    return a + 1;
}

// also allowed with auto
// auto addIt(const Numeric auto& a){
//     return a + 1;
// };

int main(){
 cout<<addIt(5)<<"-"<<addIt(5.6);
 char c = 'c';
 // passes as int
 cout<<"-"<<addIt('c');
}