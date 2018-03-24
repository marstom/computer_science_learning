#include <iostream>
#include <string>
#include "hash_table.hpp"

using namespace std;

int main(){
    HashTable<int> ht;

    cout << ht.hash("Maciek") << endl;
    cout << ht.hash("Tomek") << endl;
    cout << ht.hash("Anna") << endl;
    cout << ht.hash("to jest jakistam napis") << endl;


    return 0;
}

