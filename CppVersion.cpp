#include<iostream>

int main(){
    std::cout<< "C++ version: " << __cplusplus << std::endl;
    // generally, the value of __cplusplus is: YYYYMM 
    // Version can be checked by YY"YY" part
    // C++98: 199711 (Not exactly 1998, but close enough)
    // C++11: 201103
    // C++14: 201402
    // C++17: 201703
    // C++20: 202002
    // This version is default for your g++ compiler, but you can specify the version using -std=c++XX flag, where XX is the version you want to use (e.g., -std=c++17 for C++17).
    return 0;
}