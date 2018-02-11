#include <iostream>
#include <string>
#include <cassert>

#include "linked_list.hpp"
using namespace std;

void test_add(){
    LinkedList* aa = new LinkedList();
    push_back(aa, 3);
    push_back(aa, 12);
    push_back(aa, 24);
    push_back(aa, 1);
    //  push_back(aa, 53);
    print_whole_list(aa);
}

void test_size(){
    LinkedList* aa = new LinkedList();
    push_back(aa, 3);
    push_back(aa, 12);
    push_back(aa, 24);
    push_back(aa, 1);
    cout << size(aa) << endl;
    assert (size(aa) == 4);
}

void test_remove_value(){
    LinkedList* aa = new LinkedList();
    push_back(aa, 1);
    push_back(aa, 2);
    push_back(aa, 3);
    push_back(aa, 4);
    remove_value(aa, 3);
    print_whole_list(aa);

}

void test_remove_value_first(){
    LinkedList* aa = new LinkedList();
    push_back(aa, 1);
    push_back(aa, 2);
    push_back(aa, 3);
    push_back(aa, 4);
    remove_value(aa, 4);
    print_whole_list(aa);

}

void test_empty(){
    LinkedList* aa = new LinkedList();
    push_back(aa, 1);
    push_back(aa, 2);
    push_back(aa, 3);
    assert(empty(aa) == false);
    
    LinkedList* bb = new LinkedList();
    assert(empty(bb) == true);
    cout << "passed\n";
}

void test_value_at(){
    LinkedList* aa = new LinkedList();
    push_back(aa, 1);
    push_back(aa, 2);
    push_back(aa, 3);
    push_back(aa, 4);
    push_back(aa, 5);
    assert(value_at(aa, 1) == 4);
    assert(value_at(aa, 0) == 5);
    assert(value_at(aa, 4) == 1);
    // value_at(aa, 44);
    cout << "passed\n";
}

void test_pip_back(){


}

int main(){
    test_add();
    test_size();
    test_remove_value();
    test_remove_value_first();
    test_empty();
    test_value_at();
    return 0;
}
