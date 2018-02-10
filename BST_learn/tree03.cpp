/* make tree03
 * 
 * test:
 * a.out < tests/file1.txt
 * 
 * Spellchecker
 * Usage:
 *
 * spellchecker < file.txt
 * perfc++
 * assert.h do testow
 * google.test
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <algorithm>
#include <cassert>

using namespace std;

struct BstNode{
    string data;
    BstNode* smaller = NULL;
    BstNode* greater = NULL;
};

BstNode* GetNewNode(string data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->smaller = newNode->greater = NULL;
    return newNode;
}

BstNode* Insert(BstNode* root, string data) {
	if(root == NULL) {
            root = GetNewNode(data);
	}
	else if(data <= root->data) {
		root->smaller = Insert(root->smaller,data);
	}
	else {
		root->greater = Insert(root->greater,data);
	}
	return root;
}

bool Search(BstNode* root, string data) {
    //search in tree
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->smaller,data);
	}
	else {
		return Search(root->greater,data);
	}
}

void read_whole_pl_dictionary(BstNode* bigDictionary){
    /*
     * read file with dictionary.
     * */
    ifstream inputFile;
    string line;
    //inputFile.open("slowa.txt");
    inputFile.open("./scrabblehelper_set/slowa.txt"); // >2M words!!! C++ is slower than python :(

    while(getline(inputFile, line)){
        Insert(bigDictionary, line);
    }
    printf("Wczytano plik\n");

    inputFile.close();
}

void spell_checker(BstNode *dict){
    /*
     * if not found word print typo
     * TODO in which line?
     */
    string word;
    while(cin >> word){
       // cout << word;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        bool correct = (bool)Search(dict, word);
        if(!correct) 
            cout << "Typo! in: " << word << endl;
    } 
}

void test1(){
    BstNode* root = NULL; //why it works without new?
    root = Insert(root,"Adam");	
    root = Insert(root,"Anna");	
    root = Insert(root,"Roman");
    root = Insert(root,"Staszek");
    root = Insert(root,"Ronaldo");
    root = Insert(root,"Regan");
    string name = "Staszek";
    cout<<"Searched word\n";
    // cin>>name;
    //If name is found, print "FOUND"
    if(Search(root,name) == true) cout<<"Found\n";
    else cout<<"Not Found\n";
    
    cout << Search(root, "Regan") << endl;

    cout << "*******\n";

    string st1 = "Anka";
    string st2 = "Ankb";
    assert (1==1);
    assert (0==1);

    cout << '\n' <<(bool)(st1>st2);

}

int main(){
    //test1();
    // BstNode *bigDictionary = NULL; // why not works??
    BstNode *bigDictionary = new BstNode();
    read_whole_pl_dictionary(bigDictionary);
    spell_checker(bigDictionary);
    return 0;
}
