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

    BstNode(T d): data(d){}

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

    std::string to_string(){
        ss.str("");
        return to_string(root);
    }

    void delete_tree(){
        delete_tree(root);
    }

    // returns true if given value exists in the tree
    bool is_in_tree(T value){
        return is_in_tree(root, value); // TODO fix it
    }

    // returns the height in nodes (single node's height is 1)
    size_t get_height(){
        return get_height(root);
    }

    // returns the minimum value stored in the tree
    T get_min(){
        return get_min(root);
    }

    // returns the maximum value stored in the tree
    T get_max(){
        return get_max(root);
    }

    bool is_binary_search_tree(){
        return is_binary_search_tree(root);
    }

    void delete_value(T value){
        if(is_in_tree(root, value)){
           count--;
            delete_value(root, value);
        }
    }

    // returns next-highest value in tree after given value, -1 if none
    T get_successor(T value){
        return get_successor(root, value);
    }
    
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
    
    std::string to_string(BstNode<T>* node){
        if(node == nullptr) 
            return "";
        to_string(node->smaller);
        ss << node->data << ", ";
        to_string(node->greater);
        string str = ss.str();
        return str;
    }

    void delete_tree(BstNode<T>* node){
        if(node == nullptr) return;
        delete_tree(node->greater);
        delete node;  //segmentation fault
        delete_tree(node->smaller);
        
        return;
    }

    bool is_in_tree(BstNode<T>* node, T value){
        if(node == nullptr){
            return false;
        }
        if(node->data == value){ 
            return true;
        }
        return is_in_tree(node->smaller, value) | is_in_tree(node->greater, value);
    }

    T get_min(BstNode<T>* node){
        while(node->smaller != nullptr){
            node = node->smaller;
        }
        return node->data;
    }

    BstNode<T>* get_min_ptr(BstNode<T>* node){
        while(node->smaller != nullptr){
            node = node->smaller;
        }
        return node;
    }

    // returns the maximum value stored in the tree
    T get_max(BstNode<T>* node){
        while(node->greater != nullptr){
            node = node->greater;
        }
        return node->data;       
    }
    size_t get_height(BstNode<T>* node){
        if(node == nullptr) return 0;    
        size_t c_smaller = get_height(node->smaller);
        size_t c_greater = get_height(node->greater);

        if(c_smaller > c_greater){
            return c_smaller + 1;
        }else{
            return c_greater + 1;
        }
    }

    BstNode<T>* delete_value(BstNode<T>* node, T value){
        if(node == nullptr) return node;
        if(value < node->data){
            node->smaller = delete_value(node->smaller, value);
        }
        else if(value > node->data){
            node->greater = delete_value(node->greater, value);
        }
        else{
            if(node->smaller == nullptr){
                BstNode<T>* temp = node->greater;
                delete node;
                return temp;
            }
            else if(node->greater == nullptr){
                BstNode<T>* temp = node->smaller;
                delete node;
                return temp;
            }

            BstNode<T>* temp = get_min_ptr(node->greater);
            node->data = temp->data;
            node->greater = delete_value(node->greater, temp->data);
        }
        return node;
    }

    // T get_successor(BstNode<T>* node, T value){
    //     return -1;
        
    // }

    bool is_binary_search_tree(BstNode<T>* node){
        if(node == nullptr) return true;
        if(node->smaller != nullptr && get_max(node->smaller) > node->data)
           return false;
        if(node->greater != nullptr && get_min(node->greater) < node->data)
           return false;
        if(!is_binary_search_tree(node->smaller) || !is_binary_search_tree(node->greater))
           return false;
        
        return true;
    }

    BstNode<T>* root = nullptr;
    size_t count = 0;
    std::stringstream ss;

};

}
