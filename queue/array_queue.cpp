#include <iostream>
#include <sstream>
#include <stdexcept>

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
        }
    }

    T dequeue(){
        T el = array[head];
        bool success = inc_head();
        if(success){
            return el;
        }
        else{
            //throw std::runtime_error("Queue is empty.");
            std::cerr << "Queue is empty\n";
            return -1;
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
    arr_queue.enqueue(6);

    std::cout << "Pint queue \n";
    for(int i = 0; i<4; i++){
        std::cout<<arr_queue.dequeue()<<std::endl;
    }

    return 0;
}
