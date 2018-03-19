#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace container{

template<typename T>
struct Node{
    Node(): next(nullptr){}
    Node(T val): next(nullptr){
        data = val; 
    }
    T data;
    Node* next;
};

template<typename T>
class ListQueue{
public:
    ListQueue(): queue_len(0){
        head = new Node<T>();
        tail = head;
        head = tail;
    }

    void enqueue(T val){
        if(queue_len == 0){
            tail->data = val;
            head = tail;
        }else{
            tail->next = new Node<T>(val);
            temp = tail->next;
            tail = temp;
        }
        queue_len++;
    }

    T dequeue(){
        if(!out_of_range()){
            queue_len--;
            T val = head->data;
            temp = head->next;
            head = temp;
            return val;
        }
        else{
            throw std::range_error("Queue is empty!");
        }
    }

    bool empty(){
        if(length() == 0)
            return true;
        return false;
    }

    size_t length(){
        return queue_len;
    }

private:

    bool out_of_range(){
        return length() == 0;
    }

    Node<T>* head;
    Node<T>* tail;
    Node<T>* temp;
    size_t queue_len;
};

}
