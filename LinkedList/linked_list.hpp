#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

// using namespace std;

namespace container{
namespace linked_list{

template<typename T>
struct Node{
    T data;
    Node* next = NULL;
};


template<typename T>
class LinkedList{
public:
    
    // adds an item at the end
    void push_back(T value){
        Node<T>* el = new Node<T>();
        el->data = value;
        el->next = head;
        head = el;
        size++;
    }

    //returns number of data elements in list
    size_t get_size(){
        return size;
    }    

    //  bool returns true if empty
    bool empty(){
        if(head == nullptr)
            return true;
        return false;
    }

    // returns the value of the nth item (starting at 0 for first)
    T value_at(size_t index){
        if(empty()) throw std::runtime_error("list is empty");
        if(get_size() < index) throw std::runtime_error("out of list index");
        Node<T>* el = head;
        if(index == 0) return el->data;
        size_t count = 0;
        while(el){
            el = el->next;
            count++;
            if(count == index)
                return el->data;
        } 
        throw std::runtime_error("Error");
    }

    // adds an item to the front of the list
    void push_front(T value){
        if(head == nullptr) {
            push_back(value);
            return;
        }
        
        Node<T>* el = new Node<T>();
        el->data = value;
        Node<T>* last = head;
        
        while(last->next)
            last = last->next;
        last->next = el;
    }

    // removes end item and returns its value
    T pop_back(){
        Node<T>* el = head;
        Node<T>* tmp = head;
        head = tmp->next;
        T val = el->data;
        delete(el);
        size--;
        return val;
    }

    std::string to_string_whole_list(){
        std::stringstream ss;
        Node<T>* el = head;
        if(el == nullptr){
            ss << "List is empty" << std::endl;
            return ss.str();
        }
        while(el != nullptr){
            ss << el->data << ", ";
            el=el->next;
        }
        return ss.str();
    }

    // remove front item and return its value
    T pop_front(){
        Node<T> *last = head;

        if(last->next == nullptr){
            T var = last->data;
            delete last;
            return var;
        }
        
        while(last->next->next){
            last = last->next;
        }
        Node<T> *toDelete = last->next;
        last->next = last->next->next;
        T val = toDelete->data;
        delete toDelete;
        size--;
        return val;
    }

    // get value of front item
    T front(){
        Node<T>* el = head;
        if(el->next == nullptr) 
            return el->data;

        while(el->next)
            el=el->next;

        T var = el->data;
        return var;
    }

    // get value of end item
    T back(){
        return head->data;
    }

    void change_value_at(size_t index){}

    // removes node at given index
    void erase(size_t index){
        Node<T>* el = head;
        if(index == 0){
            pop_back();
            return;
        }

        for(int counter = 0; el != nullptr; counter++){
            if(counter == index-1){
                Node<T>* current = el;
                Node<T>* next = el->next;
                current->next = next->next;
                delete next;
            }
            el = el->next;
        }
        size--;
    }

    // insert value at index, so current item at that index is pointed to by new item at index
    void insert(size_t index, T value){
        Node<T>* el = head;
        Node<T>* current;
        Node<T>* next;
        Node<T>* newValue = new Node<T>();
        newValue->data = value;
        int counter = 0;
        while(el != nullptr){
            if(counter == index){
                current = el;
                next = el->next;
                current->next = newValue;
                newValue->next = next;
            }
            counter++;
            el = el->next;
        }
        size++;
    }

private:
    Node<T> *head = nullptr;
    size_t size = 0;
};



// // returns the value of the node at nth position from the end of the list
// int value_n_from_end(LinkedList* linkedList, int n){
//     int nn = size(linkedList) - n - 1;
//     Node *el = linkedList->start;
//     int counter = 0;
    
//     for(;el && (counter != nn); counter++){
//         el = el->next;
//     }
    
//     return el->data;
// }

// // reverses the list
// void reverse(LinkedList* linkedList){
//     Node* el = linkedList->start;
//     Node* prev = NULL;
//     Node* current = el;
//     Node* next = el->next;
//     while(current){
//         next= current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//     }
//     linkedList->start = prev;
// }

// // removes the first item in the list with this value
// void remove_value(LinkedList *linkedList, int value){
//     Node* el = linkedList->start;
//     if(el->data == value){
//         Node *tmp = linkedList->start;
//         linkedList->start = tmp->next;
//         delete(tmp);
        
//     }
//     while(el){
//         if(el->next && el->next->data == value){
//             Node* current = el;
//             Node* next = el->next;
//             current->next = next->next;
//             delete(next);
//         }
//         el=el->next;
//     }
// }




}
}
