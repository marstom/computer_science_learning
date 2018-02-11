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
    remove_value(aa, 4);
    print_whole_list(aa);

}

int main(){
    test_add();
    test_size();
    test_remove_value();
    return 0;
}
