#include <iostream>
#include <thread>
#include <chrono>
#include <future>

using namespace std;
using namespace std::chrono_literals;

void asyncThread()
{
    // async = runs the task asynchronously in a separate thread as soon as defined
    auto future = async([](int a, int b)
                        {
        cout<<"t2: started work in async thread\n";
        this_thread::sleep_for(2s);
        cout<<"t2: Finished work in async thread\n";
        return a + b; }, 5, 10);

    cout << "async:Doing some work in main thread\n";
    this_thread::sleep_for(3s);

    int result = future.get(); // waits for the async task to complete and then gets the result
    cout << "async: Result from async thread: " << result << endl;
}

int main()
{
    promise<int> p;

    // thread starts immediately and runs in background
    thread t1([&p]()
              {
        cout<<"t1: started work in t1\n";
        cout<<"t1: sleep for 2 seconds\n";
        this_thread::sleep_for(2s);
        cout<<"t1: Setting value in thread\n";
        p.set_value(5);
        cout<<"t1: sleep for 2 seconds\n";
        this_thread::sleep_for(2s);
        cout<<"t1: finished work in thread\n"; });

    cout << "main: Getting future from promise\n";
    future<int> f = p.get_future();

    cout << "main: sleep 1 seconds\n";
    this_thread::sleep_for(1s);

    cout << "main: Getting value from thread\n";
    int result = f.get(); // waits for the value to be set in promise and then gets it
    cout << "main: Value from thread: " << result << endl;

    cout << "main: Finishing remaining work in thread t1\n";
    t1.join();
    cout << endl
         << endl;
    asyncThread();
}