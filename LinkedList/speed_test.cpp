/*
 * My implement - 1.7s
 * Python 3.8s (only numbers 27, because rand generate takes too long)
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "linked_list.hpp"

#define BIG (50*1000000)

using namespace std;
using namespace std::chrono;


int *randoms = new int[BIG];

void genNumber(){
    srand(time(NULL));
    int number =0;
    for(int i=0; i<BIG; i++){
        number = rand()% 5000+1;
        randoms[i] = number;
    }
}

void test_speed(){
    LinkedList* linkedList = new LinkedList();

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for(int i=0; i<BIG; i++){
        push_back(linkedList ,randoms[i]);
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << "time= " << (float)duration/(float)1000000 << endl; //sec

}

int main(){
    genNumber();
    test_speed();
    return 0;
}
