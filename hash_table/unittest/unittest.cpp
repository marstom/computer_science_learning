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

using namespace std;


TEST(hash_table, hash){
    HashTable<int> ht;
    ht.hash("tomek");
}

TEST(hash_table, add){

}

TEST(hash_table, exists){

}

TEST(hash_table, remove){

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
