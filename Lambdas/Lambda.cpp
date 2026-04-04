#include<iostream>
#include<vector>
using namespace std;

int main(){
    auto x = [](){cout<<"void lambda"<<endl;};
    // sort of a functor
    x();

    // always auto not int
    // input parameter + return type
    // function<int(int)> will also work
    int (*square) (int) = [](int x)->int{return x*x;};
    cout<< square(5)<< endl;

    int f = 5;
    // capture list(for passing scope into the lambda function)
    // [=] for copy  all, [&] for refernce all parameters in current scope
    // mutable allows to change the copy of f otherwise it is treated as const
    auto cube = [f]()mutable{f=3;return f*f*f;};
    cout<< cube()<<endl<<"f = "<<f<<endl;

    vector<int> v = {1, 2, 3, 4};
    vector<int> cubes;

    // auto assigns some different datatype and this function does not take that type as lambda parameter
    // transform works with c++ 23
    // transform(v.begin(), v.end(), back_inserter(cubes), square);
    // cout << "cubes";
    // for(int i: cubes){
    //     cout<< i<< " ";
    // }

}