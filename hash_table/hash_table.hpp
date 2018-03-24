/*
 * Hash use linear probing,
 * key is string type
 *
 *
 */
#pragma once
#include <string>
#include <stdexcept>

template<typename T>
struct Stack{
    std::string key;
    T data;
    Stack* next;

    T pop();
    void push(T el);
};

template<typename T>
class HashTable{
public:

    HashTable(): num_buckets(10){
    }

    ~HashTable(){
    }

    int hash(std::string k, size_t m){
    }

    void add(std::string key, T value){
    }

    bool exists(std::string key){

    }

    T operator[](size_t index){
        
    }
    void remove(std::string key){

    }
    

    // hash function
    unsigned long
    hash(std::string str)
    {
	unsigned int hash = 0;
	int c;
        int i = 0;
	while ((c = str[i])){
	    hash += c;
            i++;
        }

        hash %= num_buckets;

	return hash;
    }
/*    
    // hash 2, better
    unsigned long
    hash(unsigned char *str)
    {
        unsigned long hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; // hash * 33 + c 

        return hash;
    }
*/

private:

    size_t num_buckets; // array size
};

