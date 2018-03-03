#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "list_queue.hpp"
using namespace std;
using namespace container;

int main(){
    cout << "Linked list queue: " << endl;

    ListQueue<string> list_queue;
    list_queue.enqueue("tome");
    list_queue.enqueue("Marek");
    list_queue.enqueue("Andrew");
    list_queue.enqueue("Janek");
    cout << "List begin:" << endl;
    for(int i=0; i<4; i++){
        cout << list_queue.dequeue() << endl;
    }


    list_queue.enqueue("Ariel");
    list_queue.enqueue("Kmil");
    list_queue.enqueue("Andrzej");
    list_queue.enqueue("Jaro");
    cout << "List begin:" << endl;
    for(int i=0; i<4; i++){
        cout << list_queue.dequeue() << endl;
    }
    return 0;
}
