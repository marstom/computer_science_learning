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

        if(root == nullptr){
            root = new BstNode<T>(value);
            return;
        }

        BstNode<T>* insert_iterator = root;
        BstNode<T>* parent = nullptr;

        while(insert_iterator){
            parent = insert_iterator;
            // insert_iterator = value < insert_iterator->data
            // ? insert_iterator->smaller
            // : insert_iterator->greater;

            if(value < insert_iterator->data){
                insert_iterator =  insert_iterator->smaller;
            }else{
                insert_iterator =  insert_iterator->greater;
            }
        }

        if(value < parent->data)
        parent->smaller = new BstNode<T>(value);
        else
        parent->greater = new BstNode<T>(value);

    }

    // get count of values stored
    size_t get_node_count();
    
    // prints the values in the tree, from min to max
    void print_values(){
        print_values(this->root);
    }

    void delete_tree();

    // returns true if given value exists in the tree
    bool is_in_tree(T value);

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

    void insert(Node<T> *node, T val){
        
    }

    void print_values(BstNode<T>* node){
        if(node == nullptr) return;
        print_values(node->smaller);
        cout << node->data << endl;
        print_values(node->greater);
    }

    BstNode<T>* root = nullptr;

};

}