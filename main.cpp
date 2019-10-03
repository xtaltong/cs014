#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm> // random_shuffle
#include <thread>

using namespace std;
using namespace std::chrono;


void doWork(int size) { // TODO: change from sleep to real work
    std::chrono::duration<int, std::milli> timespan(size);
    std::this_thread::sleep_for(timespan);//sleep for time
}

int myrandom(int i) { return rand()%i; }

void print(vector<int> data) {
    for (std::vector<int>::iterator it=data.begin(); it!=data.end(); ++it)
        std::cout << *it << " ";
}

std::vector<int> makeData(int size) {
    vector<int> data;
    data.reserve(size);
    for (int i=0; i<size; ++i ) {
        data.push_back(i);
    }

    cout << "Data:" << endl;
    print(data);
    cout << endl;
    cout << data.size() << endl;

    random_shuffle(data.begin(), data.end(), myrandom);

    cout << "Data shuffled:" << endl;
    print(data);
    cout << endl;
    cout << data.size() << endl;


    return data;
}


int main() {
    srand ( unsigned ( std::time(0) ) );
    vector<int> data = makeData(100000);

    high_resolution_clock::time_point t1 = high_resolution_clock::now(); //google how to time execgution c++
    doWork(5000);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << duration;

    return 0;
}