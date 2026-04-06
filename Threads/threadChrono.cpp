#include <iostream>
#include <thread>
#include <chrono>
#include <typeinfo>

using namespace std;
// using namespace std::chrono_literals; // for 2s instead of 2000ms

int main()
{
    auto start = chrono::steady_clock::now();

    thread t1([]()
              {
        //sleep_for or sleep_until
        this_thread::sleep_for(chrono::milliseconds(2000)); });
    // join = wait till done, detach = run in background
    t1.join();

    auto end = chrono::steady_clock::now();
    // way 1
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // way 2
    chrono::duration<double> d = end - start;

    cout << typeid(duration).name() << endl;
    cout << typeid(d).name() << endl;

    cout << "Time taken: " << duration.count() << " or " << d.count() << " milliseconds";
}