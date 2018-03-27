/*
 * Hash use linear probing,
 * key is string type
 *
 *
 */
#pragma once
#define ARRAY_SIZE 10

#include <string>
#include <vector>
#include <stdexcept>
#include <cstring>


template<typename T>
struct Bucket{
    std::string key;
    T data;
    Bucket* next;

};

template<typename T>
class HashTable{
public:

    HashTable(): num_buckets(ARRAY_SIZE){
        buckets = new Bucket<T>*[ARRAY_SIZE];
        for(int i = 0; i<ARRAY_SIZE; i++){
            buckets[i] = new Bucket<T>();
        }
    }

    ~HashTable(){
        // delete[] buckets;
    }

    int hash(std::string key){
        // [(a*k+b) mod p] mod m
        // a b -randof 0..p-1
        // p big prime number, must be bigger than ARRAY_SIZE
        // m table_size
        int h = 0;
        for(auto k: key){
            h += ((3214*k+4357) % 443555) % ARRAY_SIZE;
        }
        return h % ARRAY_SIZE;
    }

    void add(std::string key, T value){
        keys.push_back(key);
        int index = hash(key);
        Bucket<T> *b = buckets[index];
        while(b != nullptr){ // add value to bucket
            if(b->key == key){
                b->value = value;
                return;
            }
            b= b->next;
        }

    }

    bool exists(std::string key){
        return true;
    }

    T operator[](std::string key){
        int k = hash(key);
        return buckets[k];
    }
    void remove(std::string key){

    }

    void print_hash_table(){

    }

    void add_bucket(); // helper functions
    T get_bucket();
    
private:

    size_t num_buckets; // array size
    Bucket<T> **buckets;
    std::vector<std::string> keys;
};

