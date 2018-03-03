#include <iostream>
#include <sstream>
#include <stdexcept>

namespace container{
template<typename T>
class ArrayQueue{
public:
    ArrayQueue(size_t s): head(0), tail(0), queue_length(0){
        size = s;
        array = new T(size);
    }
    ~ArrayQueue(){
        delete[] array;
    }

    void enqueue(T el){
        if(!full()){
            array[tail] = el;
            inc_tail();
        }else{
            std::cerr << "Queue is full !!!\n";
            throw std::length_error("Queue is full!");
        }
    }

    T dequeue(){
        T el = array[head];
        bool success = inc_head();
        if(success){
            return el;
        }
        else{
            throw std::length_error("Queue is empty.");
        }
            
    }

    bool empty(){
        return head == tail;
    }

    bool full(){
        if(queue_length >= size)
            return true;
        return false;
    }

    size_t length(){
        return queue_length;
    }

private:

    void inc_tail(){
        queue_length++;
        tail = (tail + 1) % size;
    }
    
    bool inc_head(){
        if(empty() == true){
            return false;
        }else{
            queue_length--;
            head = (head + 1) % size;
            return true;
        }
    }

    T* array;
    size_t size;
    size_t head;
    size_t tail;
    size_t queue_length;

};

}
