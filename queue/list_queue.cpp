#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

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
            return _dequeue();
        }
        else{
            throw std::range_error("List is out of range!");
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
    T _dequeue(){
        queue_len--;
        T val = head->data;
        temp = head->next;
        head = temp;
        return val;
    }

    bool out_of_range(){
        if(length() == 0)
            return true;
        return false;
    }

    Node<T>* head;
    Node<T>* tail;
    Node<T>* temp;
    size_t queue_len;
};


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
