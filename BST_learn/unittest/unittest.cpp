#include <iostream>
#include <string>
#include <stdexcept>
#include <gtest/gtest.h>
#include "../binary_search_tree.hpp"

using namespace std;
using namespace container;


TEST(BST, insert) { 
    Tree<int> tree;
    tree.insert(12);
    tree.insert(13);
    tree.insert(14);
    tree.insert(14);
    tree.insert(14);
    tree.insert(4);
    tree.insert(2);
    tree.print_values();
    cout << "test finisher\n";
}
 

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
