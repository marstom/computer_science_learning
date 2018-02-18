#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "linked_list.h"

void test_push_back(){
    linked_list_t* aa = malloc(sizeof(linked_list_t*));
    push_back(aa, 11);
    push_back(aa, 22);
    push_back(aa, 33);
    push_back(aa, 44);
    print_list(aa);
    printf("size =  %d; empty=%d\n", (int)size(aa), (int)empty(aa));
    //  push_back(aa, 53);
    // print_whole_list(aa);
}

int main(){
    test_push_back();
    return 0;
}


// void test_size(){
//     struct LinkedList* aa = malloc(sizeof(struct LinkedList*));
//     push_back(aa, 3);
//     push_back(aa, 12);
//     push_back(aa, 24);
//     push_back(aa, 1);
//     // assert (size(aa) == 4);
// }

// void test_remove_value(){
//     struct LinkedList* aa = malloc(sizeof(struct LinkedList*));
//     push_back(aa, 1);
//     push_back(aa, 2);
//     push_back(aa, 3);
//     push_back(aa, 4);
//     remove_value(aa, 3);
//     print_whole_list(aa);

// }

// void test_remove_value_first(){
//     struct LinkedList* aa = malloc(sizeof(struct LinkedList*));
//     push_back(aa, 1);
//     push_back(aa, 2);
//     push_back(aa, 3);
//     push_back(aa, 4);
//     remove_value(aa, 4);
//     print_whole_list(aa);

// }

// void test_empty(){
//     struct LinkedList* aa = malloc(sizeof(struct LinkedList*));
//     push_back(aa, 1);
//     push_back(aa, 2);
//     push_back(aa, 3);
//     assert(empty(aa) == false);
    
//     struct LinkedList* bb = malloc(sizeof(struct LinkedList*));
//     assert(empty(bb) == true);
// }

// void test_value_at(){
//     struct LinkedList* aa = malloc(sizeof(struct LinkedList*));
//     push_back(aa, 1);
//     push_back(aa, 2);
//     push_back(aa, 3);
//     push_back(aa, 4);
//     push_back(aa, 5);
//     assert(value_at(aa, 1) == 4);
//     assert(value_at(aa, 0) == 5);
//     assert(value_at(aa, 4) == 1);
//     // value_at(aa, 44);
// }

// void test_pop_back(){
//     struct LinkedList* aa = malloc(sizeof(struct LinkedList*));
//     push_back(aa, 1);
//     push_back(aa, 2);
//     push_back(aa, 3);
//     push_back(aa, 4);
//     push_back(aa, 5);
//     assert (pop_back(aa)==5);
//     assert (pop_back(aa)==4);
//     assert (pop_back(aa)==3);
//     print_whole_list(aa);

// }

// void test_back(){
//     struct LinkedList* aa = malloc(sizeof(struct LinkedList*));
//     push_back(aa, 1);
//     push_back(aa, 2);
//     push_back(aa, 3);
//     assert (back(aa)==3);
//     assert (back(aa)==3);
//     print_whole_list(aa);
// }

// void test_push_front(){
//     struct LinkedList* aa = malloc(sizeof(struct LinkedList*));
//     push_back(aa, 1);
//     push_back(aa, 2);
//     push_back(aa, 3);
//     push_front(aa, 4);
//     print_whole_list(aa);
// }

// void test_push_front_empty(){
//     struct LinkedList* aa = malloc(sizeof(struct LinkedList*));
//     push_front(aa, 12);
//     print_whole_list(aa);
// }

// void test_pop_front(){
//     struct LinkedList* aa = malloc(sizeof(struct LinkedList*));
//     push_back(aa, 1);
//     push_back(aa, 2);
//     push_back(aa, 3);
//     assert (pop_front(aa)==1);
//     assert (pop_front(aa)==2);
//     assert (pop_front(aa)==3);
//     //push_back(aa, 1);
//     print_whole_list(aa); // mess from memory, because delete rooti, is it ok?
// }

// void test_front(){
//     struct LinkedList* aa = malloc(sizeof(struct LinkedList*));
//     push_back(aa, 1);
//     push_back(aa, 2);
//     push_back(aa, 3);
//     assert (front(aa) == 1);
// }

// void test_value_n_from_end(){
//     struct LinkedList* aa = malloc(sizeof(struct LinkedList*));
//     push_back(aa, 1);
//     push_back(aa, 2);
//     push_back(aa, 3);
//     push_back(aa, 5);
//     push_back(aa, 6);
//     push_back(aa, 7);
//     print_whole_list(aa);
//     assert (value_n_from_end(aa, 0) == 1);
//     assert (value_n_from_end(aa, 2) == 3);
//     assert (value_n_from_end(aa, 5) == 7);
// }

// void test_reverse(){
//     struct LinkedList* aa = malloc(sizeof(struct LinkedList*));
//     push_back(aa, 1);
//     push_back(aa, 2);
//     push_back(aa, 3);
//     push_back(aa, 5);
//     push_back(aa, 6);
//     push_back(aa, 7);
//     print_whole_list(aa);
//     assert (back(aa) == 7);
//     reverse(aa);
//     print_whole_list(aa);
//     assert (front(aa) == 7);
// }

// void test_erase(){
//     struct LinkedList* aa = malloc(sizeof(struct LinkedList*));
//     push_back(aa, 1);
//     push_back(aa, 2);
//     push_back(aa, 3);
//     push_back(aa, 4);
//     push_back(aa, 5);
//     erase(aa, 4);
//     print_whole_list(aa);

// }

// void test_insert(){
//     struct LinkedList* aa = malloc(sizeof(struct LinkedList*));
//     push_back(aa, 1);
//     push_back(aa, 2);
//     push_back(aa, 3);
//     push_back(aa, 4);
//     insert(aa, 1, 99);
//     printf("%d\n",size(aa));
//     print_whole_list(aa);
// }


// int main(){
//     test_push_back();
//     test_size();
//     test_remove_value();
//     test_remove_value_first();
//     test_empty();
//     test_value_at();
//     test_pop_back();
//     test_back();
//     test_push_front();
//     test_pop_front();
//     test_front();
//     test_value_n_from_end();
//     test_reverse();
//     test_erase();
//     test_insert();
//     test_push_front_empty();
//     return 0;
// }
