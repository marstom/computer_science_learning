#include <iostream>
#include <string>
#include <stdexcept>
#include <gtest/gtest.h>
#include "../binary_search_tree.hpp"

using namespace std;
using namespace container;

stringstream ss;

// // why not working???
// Tree<int> create_example_tree(){
//     Tree<int> t;
//     t.insert(12);
//     t.insert(13);
//     t.insert(14);
//     t.insert(14);
//     return t;
// }


// why not working???
void fill_example_tree(Tree<int> &t){
    t.insert(777);
    t.insert(1024);
    t.insert(1);
    t.insert(11);
    t.insert(2);
    t.insert(22);
    t.insert(3);
    t.insert(33);
    t.insert(4);
    t.insert(44);
    t.insert(5);
    t.insert(55);
}


TEST(BST, insert) { 
    Tree<int> tree;
    fill_example_tree(tree);
    string str =tree.to_string();
    ASSERT_EQ("1, 2, 3, 4, 5, 11, 22, 33, 44, 55, 777, 1024, ", str);
    cout << str << endl;
}

TEST(BST, get_node_count) { 
    Tree<int> tree;
    fill_example_tree(tree);
    ASSERT_EQ(12, tree.get_node_count());
}


TEST(BST, is_in_tree) { 
    Tree<int> tree;
    fill_example_tree(tree);
    //cout << tree.to_string() << endl;
    ASSERT_TRUE(tree.is_in_tree(1));
    ASSERT_TRUE(tree.is_in_tree(2));
    ASSERT_TRUE(tree.is_in_tree(3));
    ASSERT_TRUE(tree.is_in_tree(22));
    ASSERT_TRUE(tree.is_in_tree(11));
    ASSERT_TRUE(tree.is_in_tree(1024));
    ASSERT_FALSE(tree.is_in_tree(7));
}

TEST(BST, delete_tree) { 
    Tree<int> tree;
    fill_example_tree(tree);
    //tree.delete_tree();
    
    string str =tree.to_string();
    ASSERT_EQ("", str);
    cout << str << endl;
}

TEST(BST, get_height) { 
    Tree<int> tree;
    fill_example_tree(tree);
    ASSERT_EQ(7, tree.get_height());
}

TEST(BST, get_min) { 
    Tree<int> tree;
    fill_example_tree(tree);
    
    string str =tree.to_string();
    ASSERT_EQ(1, tree.get_min());
    cout << str << endl;
}


TEST(BST, get_max) { 
    Tree<int> tree;
    fill_example_tree(tree);
    string str =tree.to_string();
    ASSERT_EQ(1024, tree.get_max());
    cout << str << endl;
}


TEST(BST, get_successor) { 
    Tree<int> tree;
    fill_example_tree(tree);
    int s = tree.get_successor(22);
    ASSERT_EQ(33, s);
}

TEST(BST, is_binary_search_tree) { 
    Tree<int> tree;
    fill_example_tree(tree);
    ASSERT_TRUE(tree.is_binary_search_tree());
}

TEST(BST, delete_value){
    Tree<int> tree;
    fill_example_tree(tree);
    tree.delete_value(2);
    ASSERT_EQ("1, 3, 4, 5, 11, 22, 33, 44, 55, 777, 1024, ", tree.to_string());
    tree.delete_value(44);
    ASSERT_EQ("1, 3, 4, 5, 11, 22, 33, 55, 777, 1024, ", tree.to_string());
    tree.delete_value(1024);
    ASSERT_EQ("1, 3, 4, 5, 11, 22, 33, 55, 777, ", tree.to_string());
    tree.delete_value(1);
    ASSERT_EQ("3, 4, 5, 11, 22, 33, 55, 777, ", tree.to_string());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
