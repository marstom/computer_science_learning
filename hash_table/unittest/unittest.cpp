/*
 * expand 2*size
 * shrink size/4
 *
 * */
#include <iostream>
#include <string>
#include <stdexcept>
#include <gtest/gtest.h>
#include "../hash_table.hpp"


#define private public

using namespace std;


//FRIEND_TEST(hash_table, hash){
//    HashTable<int> ht;
//    ht.hash("tomek");
//}

TEST(hash_table, add){

    HashTable<int> ht;
    ht.add("a", 232);
    ht.add("b", 26);
    ht.add("c", 232);
    ht.add("d", 232);
    ht.add("a", 7777);
    cout << ht["a"] << endl;
}

TEST(hash_table, exists){
    HashTable<int> ht;
    ht.add("a", 232);
    ht.add("b", 26);
    ht.add("c", 232);
    ht.add("d", 232);
    ht.add("a", 7777);
    ASSERT_FALSE(ht.exists("r"));
    ASSERT_TRUE(ht.exists("a"));
    ASSERT_TRUE(ht.exists("c"));
}

TEST(hash_table, remove){
    HashTable<int> ht;
    ht.add("a", 232);
    ht.add("b", 26);
    ht.add("c", 232);
    ht.add("d", 232);
    ht.add("a", 7777);
    ASSERT_TRUE(ht.exists("c"));
    ht.remove("c"); 
    ASSERT_FALSE(ht.exists("c"));
}


TEST(hash_table, many_keys){

    HashTable<int> ht;
    ht.add("Tomek", 25);
    ht.add("Tmk", 35);
    ht.add("maciek", 5);
    ht.add("romek", 3);
    ht.add("kaja", 32);
    ht.add("anna", 315);
    ht.add("sad", 225);
    ht.add("aad", 425);
    ht.add("sa", 23423);
    ht.add("a33d", 99);
    ht.add("sdIm", 88);
    ht.add("sssd", 35);
    ht.add("s1d", 32);
    ht.add("s2d", 5);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
