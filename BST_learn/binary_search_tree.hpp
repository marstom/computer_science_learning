#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <algorithm>
#include <cassert>

using namespace std;

namespace container{


template<typename T>
struct BstNode{

    BstNode(T d): data(d), smaller(nullptr), greater(nullptr){}

    T data;
    BstNode* smaller = nullptr;
    BstNode* greater = nullptr;
};

template<typename T>
class Tree{
public:
     // insert value into tree
    void insert(T value){
        count++;
        if(root == nullptr){
            root = new BstNode<T>(value);
            return;
        }
        insert(root, value);
    }

    // get count of values stored
    size_t get_node_count(){
        return count;
    }
    
    // prints the values in the tree, from min to max
    void print_values(){
        print_values(this->root);
    }

    void delete_tree();

    // returns true if given value exists in the tree
    bool is_in_tree(T value){
        return is_in_tree(root, value); // TODO fix it
    }

    // returns the height in nodes (single node's height is 1)
    size_t get_height();

    // returns the minimum value stored in the tree
    T get_min(); 

    // returns the maximum value stored in the tree
    T get_max();

    bool is_binary_search_tree();

    void delete_value(T value);

    // returns next-highest value in tree after given value, -1 if none
    T get_successor();
    
private:

    BstNode<T>* insert(BstNode<T> *node, T value){
        if(node == nullptr){
            node = new BstNode<T>(value);
            return node;
        }
        if(value < node->data){
            node->smaller = insert(node->smaller, value);
        }else{
            node->greater = insert(node->greater, value);
        }
        return node;
    }

    void print_values(BstNode<T>* node){
        if(node == nullptr) return;
        print_values(node->smaller);
        cout << node->data << endl;
        print_values(node->greater);
    }
    
    bool is_in_tree(BstNode<T>* node, T value){
        if(node == nullptr) return false;
        if(node->data == value) return true;
        is_in_tree(node->greater, value);
        is_in_tree(node->smaller, value);
        return false;
    }

    BstNode<T>* root = nullptr;
    size_t count = 0;

};

}
