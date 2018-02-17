#include <iostream>
#include <stdexcept>

// using namespace std;

namespace container{
namespace linked_list{

struct Node{
    int data;
    Node* next = NULL;
};

struct LinkedList{
    Node* start = NULL;
};

//returns number of data elements in list
size_t size(LinkedList *linkedList){
    Node *el = linkedList->start;
    size_t size = 0;
    while(el){
        size++;
        el = el->next;
    }
    return size;
}

//  bool returns true if empty
bool empty(LinkedList* linkedList){
    if(linkedList->start == NULL)
        return true;
    return false;
}

// returns the value of the nth item (starting at 0 for first)
int value_at(LinkedList *linkedList, size_t index){
    if(empty(linkedList)) throw std::runtime_error("list is empty"); //except
    if(size(linkedList) < index) throw std::runtime_error("out of list index"); //except
    Node* el = linkedList->start;
    if(index == 0) return el->data;
    size_t count = 0;
    while(el){
        el = el->next;
        count++;
        if(count == index)
            return el->data;
    } 
    throw std::runtime_error("List out of range.");
}

// adds an item at the end
void push_back(LinkedList *linkedList, int value){
    Node* el = new Node();
    el->data = value;
    el->next = linkedList->start;
    linkedList->start = el;
}

// adds an item to the front of the list
void push_front(LinkedList *linkedList, int value){
    if(linkedList->start == NULL) {push_back(linkedList, value); return;}
    Node* el = new Node();
    el->data = value;

    Node *last = linkedList->start;
    while(last->next){last = last->next;}
    last->next = el;
}

// remove front item and return its value
int pop_front(LinkedList *linkedList){
    Node *last = linkedList->start;

    if(last->next == NULL){
        int var = last->data;
        delete last;
        return var;
    }
    
    while(last->next->next){
        last = last->next;
    }
    Node *toDelete = last->next;
    last->next = last->next->next;
    int val = toDelete->data;
    delete toDelete;
    return val;
}

// removes end item and returns its value
int pop_back(LinkedList *linkedList){
    Node* el = linkedList->start;
    Node* tmp = linkedList->start;
    linkedList->start = tmp->next;
    int val = el->data;
    delete(el);
    return val;
}

// get value of front item
int front(LinkedList* linkedList){
    Node* el = linkedList->start;
    if(el->next == NULL) return el->data;
    while(el->next){
        el=el->next;
    }
    int var = el->data;
    return var;
}

// get value of end item
int back(LinkedList* linkedList){
    Node* el = linkedList->start;
    return el->data;
}

// insert value at index, so current item at that index is pointed to by new item at index
void insert(LinkedList* linkedList, int index, int value){
    Node* el = linkedList->start;
    Node* current;
    Node* next;
    Node* newValue = new Node();
    newValue->data = value;
    int counter = 0;
    while(el){
        if(counter == index){
            current = el;
            next = el->next;
            current->next = newValue;
            newValue->next = next;
        }
        counter++;
        el = el->next;
    }

}

// removes node at given index
void erase(LinkedList* linkedList, int index){
    Node* el = linkedList->start;
    int counter = 0;
    if(index == 0){ pop_back(linkedList); return;}
    for(;el;counter++){
        if(counter == index-1){
            // remove el
            Node* current = el;
            Node* next = el->next;
            current->next = next->next;
            delete next;
        }
        el = el->next;
    }
}

// returns the value of the node at nth position from the end of the list
int value_n_from_end(LinkedList* linkedList, int n){
    int nn = size(linkedList) - n - 1;
    Node *el = linkedList->start;
    int counter = 0;
    
    for(;el && (counter != nn); counter++){
        el = el->next;
    }
    
    return el->data;
}

// reverses the list
void reverse(LinkedList* linkedList){
    Node* el = linkedList->start;
    Node* prev = NULL;
    Node* current = el;
    Node* next = el->next;
    while(current){
        next= current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    linkedList->start = prev;
}

// removes the first item in the list with this value
void remove_value(LinkedList *linkedList, int value){
    Node* el = linkedList->start;
    if(el->data == value){
        Node *tmp = linkedList->start;
        linkedList->start = tmp->next;
        delete(tmp);
        
    }
    while(el){
        if(el->next && el->next->data == value){
            Node* current = el;
            Node* next = el->next;
            current->next = next->next;
            delete(next);
        }
        el=el->next;
    }
}

// print all elements
// add to stringstream and compare with each appended element
/*
 *stringstream ss;
 EXPECT_EQ(ss.str() "1 2 3 4 5") //chech if out has expected varlue
 *
 * */
void print_whole_list(LinkedList* linkedList){
    Node* el = linkedList->start;
    if(el == NULL){
        std::cout << "List is empty" << std::endl;
        return;
    }
    while(el){
        std::cout << el->data << ", ";
        el=el->next;
    }
    std::cout << '\n';
}

}
}
