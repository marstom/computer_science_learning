/*
 *
 * BST Implement
 * asd
 *
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <algorithm>
#include <cassert>

using namespace std;

class BstNode{
public:
    BstNode(string data){
        this->data = data;
    }

    BstNode(){

    }

    string data;
    BstNode* smaller = NULL;
    BstNode* greater = NULL;
};

BstNode* getNewNode(string data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->smaller = NULL; 
    newNode->greater = NULL;

    return newNode;
}

BstNode* insert(BstNode* root, string data) {
	if(root == NULL) {
            root = getNewNode(data);
	}
	else if(data <= root->data) {
		root->smaller = insert(root->smaller,data);
	}
	else {
		root->greater = insert(root->greater,data);
	}
	return root;
}

/*
void insert(BstNode* root, string data) {
	if(root == NULL) {
            root = getNewNode(data);
	}
	if(data <= root->data) {
		root->smaller = getNewNode(data);
	}else{
		root->greater =getNewNode(data);
	}
}
*/

void print_values(BstNode* root)
{
	//print all tree values in order
    if (root != NULL)
    {
        print_values(root->smaller);
        cout << root->data << endl;
        print_values(root->greater);
    }
}

size_t get_node_count(BstNode *root){
    size_t size = 1;
    if(root != NULL){
        cout << 'G';
        size +=get_node_count(root->greater);
        cout << 's';
        size +=get_node_count(root->smaller);
        return size;
        
    }else{
        return 0;
    }
}


string findMinimum(BstNode* root){
    BstNode* current = root;
    while(current->smaller != NULL){
        current = current->smaller;
    }
    return current->data;
}

string findMaximum(BstNode* root){
    BstNode* current = root;
    while(current->greater != NULL){
        current = current->greater;
    }
    return current->data;
}

int get_height(BstNode* root){
    if(root == NULL){
        return -1;
    }
    int smaller = get_height(root->smaller);
    int greater = get_height(root->greater);
    if(smaller > greater)
        return smaller + 1;
    else
        return greater + 1;
}

void delete_tree(){

}

void is_binary_search_tree(){}

void delete_value();

bool is_in_tree(BstNode* root, string data) {
    // check if string is in tree
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return is_in_tree(root->smaller,data);
	}
	else {
		return is_in_tree(root->greater,data);
	}
}
