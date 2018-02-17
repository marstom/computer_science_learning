#pragma once
#include <stdio.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
};

typedef struct LinkedList{
    struct Node* start;
};

struct Node* begin_linked_list(struct LinkedList *linkedList){
    struct Node *el = linkedList->start;
    el = malloc(sizeof(struct Node));
    el->data = NULL;
    return el;
}

//returns number of data elements in list
size_t size(struct LinkedList *linkedList){
    struct Node* el = begin_linked_list(linkedList);
    size_t size = 0;
    while(el){
        size++;
        el = el->next;
    }
    return size;
}

//  bool returns true if empty
bool empty(struct LinkedList* linkedList){
    if(linkedList->start == NULL)
        return true;
    return false;
}

// returns the value of the nth item (starting at 0 for first)
int value_at(struct LinkedList *linkedList, size_t index){
    // if(empty(linkedList)) throw std::runtime_error("list is empty"); //except
    // if(size(linkedList) < index) throw std::runtime_error("out of list index"); //except
    struct Node* el = begin_linked_list(linkedList);
    if(index == 0) return el->data;
    size_t count = 0;
    while(el){
        el = el->next;
        count++;
        if(count == index)
            return el->data;
    } 
    //throw std::runtime_error("List out of range.");
}

// adds an item at the end
void push_back(struct LinkedList *linkedList, int value){
    struct Node* el = malloc(sizeof(struct Node*));
    el->data = value;
    el->next = linkedList->start;
    linkedList->start = el;
}

// adds an item to the front of the list
void push_front(struct LinkedList *linkedList, int value){
    if(linkedList->start == NULL) {push_back(linkedList, value); return;}
    struct Node* el = malloc(sizeof(struct Node*));
    el->data = value;

    struct Node *last = linkedList->start;
    while(last->next){last = last->next;}
    last->next = el;
}

// remove front item and return its value
int pop_front(struct LinkedList *linkedList){
    struct Node *last = linkedList->start;

    if(last->next == NULL){
        int var = last->data;
        free(last);
        return var;
    }
    
    while(last->next->next){
        last = last->next;
    }
    struct Node *tofree = last->next;
    last->next = last->next->next;
    int val = tofree->data;
    free(tofree);
    return val;
}

// removes end item and returns its value
int pop_back(struct LinkedList *linkedList){
    struct Node* el = begin_linked_list(linkedList);
    struct Node* tmp = linkedList->start;
    linkedList->start = tmp->next;
    int val = el->data;
    free(el);
    return val;
}

// get value of front item
int front(struct LinkedList* linkedList){
    struct Node* el = begin_linked_list(linkedList);
    if(el->next == NULL) return el->data;
    while(el->next){
        el=el->next;
    }
    int var = el->data;
    return var;
}

// get value of end item
int back(struct LinkedList* linkedList){
    struct Node* el = begin_linked_list(linkedList);
    return el->data;
}

// insert value at index, so current item at that index is pointed to by new item at index
void insert(struct LinkedList* linkedList, int index, int value){
    struct Node* el = begin_linked_list(linkedList);
    struct Node* current;
    struct Node* next;
    struct Node* newValue = malloc(sizeof(struct Node));
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
void erase(struct LinkedList* linkedList, int index){
    struct Node* el = begin_linked_list(linkedList);
    int counter = 0;
    if(index == 0){ pop_back(linkedList); return;}
    for(;el;counter++){
        if(counter == index-1){
            // remove el
            struct Node* current = el;
            struct Node* next = el->next;
            current->next = next->next;
            free(next);
        }
        el = el->next;
    }
}

// returns the value of the node at nth position from the end of the list
int value_n_from_end(struct LinkedList* linkedList, int n){
    int nn = size(linkedList) - n - 1;
    struct Node *el = linkedList->start;
    int counter = 0;
    
    for(;el && (counter != nn); counter++){
        el = el->next;
    }
    
    return el->data;
}

// reverses the list
void reverse(struct LinkedList* linkedList){
    struct Node* el = begin_linked_list(linkedList);
    struct Node* prev = NULL;
    struct Node* current = el;
    struct Node* next = el->next;
    while(current){
        next= current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    linkedList->start = prev;
}

// removes the first item in the list with this value
void remove_value(struct LinkedList *linkedList, int value){
    struct Node* el = begin_linked_list(linkedList);
    if(el->data == value){
        struct Node *tmp = linkedList->start;
        linkedList->start = tmp->next;
        free(tmp);
        
    }
    while(el){
        if(el->next && el->next->data == value){
            struct Node* current = el;
            struct Node* next = el->next;
            current->next = next->next;
            free(next);
        }
        el=el->next;
    }
}

// print all elements
void print_whole_list(struct LinkedList* linkedList){
    struct Node* el = begin_linked_list(linkedList);
    if(el == NULL){
       printf("List is empty");
        return;
    }
    while(el){
        printf("%d\n", el->data);
        el=el->next;
    }
}
