#include <iostream>
#include <string>
#include "hash_table.hpp"

using namespace std;

int main(){
    HashTable<int> ht;

    cout << "hashin function tester :P" << endl;
    cout << ht.hash("a") << endl;
    cout << ht.hash("b") << endl;
    cout << ht.hash("c") << endl;
    cout << ht.hash("d") << endl;
    cout << ht.hash("kja") << endl;
    cout << ht.hash("sra") << endl;

    //Bucket<int> bb;
    //bb.push_back(12);



    return 0;
}

