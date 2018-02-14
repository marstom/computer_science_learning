#include <iostream>
#include <string>
#include <cassert>

#include "linked_list.hpp"
using namespace std;
using namespace container::linked_list;

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

void test_pop_back(){
    LinkedList* aa = new LinkedList();
    push_back(aa, 1);
    push_back(aa, 2);
    push_back(aa, 3);
    push_back(aa, 4);
    push_back(aa, 5);
    assert (pop_back(aa)==5);
    assert (pop_back(aa)==4);
    assert (pop_back(aa)==3);
    print_whole_list(aa);
    cout << "passed\n";

}

void test_back(){
    LinkedList* aa = new LinkedList();
    push_back(aa, 1);
    push_back(aa, 2);
    push_back(aa, 3);
    assert (back(aa)==3);
    assert (back(aa)==3);
    print_whole_list(aa);
    cout << "passed\n";
}

void test_push_front(){
    LinkedList* aa = new LinkedList();
    push_back(aa, 1);
    push_back(aa, 2);
    push_back(aa, 3);
    push_front(aa, 4);
    print_whole_list(aa);
}

void test_push_front_empty(){
    LinkedList* aa = new LinkedList();
    push_front(aa, 12);
    print_whole_list(aa);
}

void test_pop_front(){
    LinkedList* aa = new LinkedList();
    push_back(aa, 1);
    push_back(aa, 2);
    push_back(aa, 3);
    assert (pop_front(aa)==1);
    assert (pop_front(aa)==2);
    assert (pop_front(aa)==3);
    //push_back(aa, 1);
    print_whole_list(aa); // mess from memory, because delete rooti, is it ok?
}

void test_front(){
    LinkedList* aa = new LinkedList();
    push_back(aa, 1);
    push_back(aa, 2);
    push_back(aa, 3);
    cout << "First value " << front(aa) << endl;
    assert (front(aa) == 1);
}

void test_value_n_from_end(){
    LinkedList* aa = new LinkedList();
    push_back(aa, 1);
    push_back(aa, 2);
    push_back(aa, 3);
    push_back(aa, 5);
    push_back(aa, 6);
    push_back(aa, 7);
    cout << "start element =" << aa->start->data << endl;
    print_whole_list(aa);
    assert (value_n_from_end(aa, 0) == 1);
    assert (value_n_from_end(aa, 2) == 3);
    assert (value_n_from_end(aa, 5) == 7);
    cout << "passed\n";

}

void test_reverse(){
    LinkedList* aa = new LinkedList();
    push_back(aa, 1);
    push_back(aa, 2);
    push_back(aa, 3);
    push_back(aa, 5);
    push_back(aa, 6);
    push_back(aa, 7);
    print_whole_list(aa);
    assert (back(aa) == 7);
    reverse(aa);
    print_whole_list(aa);
    assert (front(aa) == 7);
}

void test_erase(){
    LinkedList* aa = new LinkedList();
    push_back(aa, 1);
    push_back(aa, 2);
    push_back(aa, 3);
    push_back(aa, 4);
    push_back(aa, 5);
    erase(aa, 4);
    cout << "test erase \n";
    print_whole_list(aa);

}

void test_insert(){
    LinkedList* aa = new LinkedList();
    push_back(aa, 1);
    push_back(aa, 2);
    push_back(aa, 3);
    push_back(aa, 4);
    insert(aa, 1, 99);
    cout << "insert value"<< size(aa) << endl;
    print_whole_list(aa);
}

int main(){
    test_add();
    test_size();
    test_remove_value();
    test_remove_value_first();
    test_empty();
    test_value_at();
    test_pop_back();
    test_back();
    test_push_front();
    test_pop_front();
    test_front();
    test_value_n_from_end();
    test_reverse();
    test_erase();
    test_insert();
    test_push_front_empty();
    return 0;
}
