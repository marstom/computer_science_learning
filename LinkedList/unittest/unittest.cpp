#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "../linked_list.hpp"

using namespace std;
using namespace container::linked_list;

LinkedList<int> test_list_four_int(){
    LinkedList<int> linked_list;
    linked_list.push_back(11);
    linked_list.push_back(22);
    linked_list.push_back(33);
    linked_list.push_back(44);
    linked_list.push_back(55);
    linked_list.push_back(66);
    linked_list.push_back(77);
    linked_list.push_back(88);
    linked_list.push_back(99);
    return linked_list;
}

TEST(LinkedList, push_back) { 
    LinkedList<int> linked_list;
    linked_list.push_back(23);
    linked_list.push_back(123);
    linked_list.push_back(433);
    linked_list.push_back(888);
    cout << linked_list.get_size() << endl;
    ASSERT_EQ("888, 433, 123, 23, ", linked_list.to_string_whole_list());
}
 

TEST(LinkedList, get_size) { 
    LinkedList<int> linked_list= test_list_four_int();
    ASSERT_EQ(linked_list.get_size(), 9);
    LinkedList<int> e_list;
    ASSERT_EQ(e_list.get_size(), 0);
}

TEST(LinkedList, empty) { 
    LinkedList<float> e_list;
    ASSERT_TRUE(e_list.empty());

    LinkedList<float> linked_list;
    linked_list.push_back(23.423);
    ASSERT_FALSE(linked_list.empty());
}

TEST(LinkedList, value_at) { 
    LinkedList<int> linked_list= test_list_four_int();
    ASSERT_EQ(linked_list.value_at(2), 77);
}

TEST(LinkedList, push_front) { 
    LinkedList<int> linked_list;
    linked_list.push_back(1);
    linked_list.push_back(2);
    linked_list.push_front(3);
    linked_list.push_front(4);
    ASSERT_EQ("2, 1, 3, 4, ", linked_list.to_string_whole_list());
    //cout << linked_list.to_string_whole_list() << endl;    
    LinkedList<int> linked_list2;
    linked_list2.push_front(1);
    linked_list2.push_front(2);
    linked_list2.push_front(3);
    linked_list2.push_back(4);
    // cout << linked_list2.to_string_whole_list() << endl;  
    ASSERT_EQ("4, 1, 2, 3, ", linked_list2.to_string_whole_list());
}

TEST(LinkedList, pop_back) { 
    LinkedList<int> linked_list= test_list_four_int();
    ASSERT_EQ("99, 88, 77, 66, 55, 44, 33, 22, 11, ", linked_list.to_string_whole_list());
    ASSERT_EQ(linked_list.get_size(),9);
    ASSERT_EQ(linked_list.pop_back(), 99);
    ASSERT_EQ(linked_list.get_size(),8);
    ASSERT_EQ("88, 77, 66, 55, 44, 33, 22, 11, ", linked_list.to_string_whole_list());

}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
