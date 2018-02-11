#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next = NULL;
};

struct LinkedList{
    Node* start;
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
void empty();

// returns the value of the nth item (starting at 0 for first)
int value_at(int index);

// adds an item to the front of the list
void push_front(LinkedList *linkedList, int value);

// remove front item and return its value
void pop_front();

// adds an item at the end
void push_back(LinkedList *linkedList, int value){
    Node* el = new Node();
    el->data = value;
    el->next = linkedList->start;
    linkedList->start = el;
}

// removes end item and returns its value
void pop_back();

// get value of front item
void front();

// get value of end item
void back();

// insert value at index, so current item at that index is pointed to by new item at index
void insert(int index,int value);

// removes node at given index
void erase(int index);

// returns the value of the node at nth position from the end of the list
int value_n_from_end(int n);

// reverses the list
void reverse();

// removes the first item in the list with this value
void remove_value(LinkedList *linkedList, int value){
    Node* el = linkedList->start;
    while(el){
        //if(el->next)
        //Node* prev = el;
        if(el->next && el->next->data == value){
            Node* current = el;
            Node* next = el->next;
            current->next = next->next;
        }
        el=el->next;
    }
    //Node* ptr = el;
    //el = el->next; //todo free memeory

}

// print all elements
void print_whole_list(LinkedList* linkedList){
    Node* el = linkedList->start;
    while(el){
        std::cout << el->data << ", ";
        el=el->next;
    }
    std::cout << '\n';
}

