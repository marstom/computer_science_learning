#include <iostream>
#include <sstream>
#include <stdexcept>
#include "array_queue.hpp"

using namespace container;

int main(){
    ArrayQueue<int> arr_queue(6);
    arr_queue.enqueue(1);
    arr_queue.enqueue(2);
    arr_queue.enqueue(3);
    arr_queue.enqueue(4);

    std::cout << "Pint queue \n";
    for(int i = 0; i<4; i++){
        std::cout<<arr_queue.dequeue()<<std::endl;
    }

    arr_queue.enqueue(1);
    arr_queue.enqueue(2);
    arr_queue.enqueue(3);
    arr_queue.enqueue(4);

    std::cout << "Pint queue \n";
    for(int i = 0; i<4; i++){
        std::cout<<arr_queue.dequeue()<<std::endl;
    }


    arr_queue.enqueue(1);
    arr_queue.enqueue(2);
    arr_queue.enqueue(3);
    arr_queue.enqueue(4);
    arr_queue.enqueue(5);
    //arr_queue.enqueue(6);

    std::cout << "Pint queue \n";
    for(int i = 0; i<4; i++){
        std::cout<<arr_queue.dequeue()<<std::endl;
    }

    return 0;
}
