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


template<typename V>
struct Bucket{
    std::string key;
    V data;
    Bucket* next;

};

template<typename V>
class HashTable{
public:

    HashTable(): num_buckets(ARRAY_SIZE){
        buckets = new Bucket<V>*[ARRAY_SIZE];
        for(int i = 0; i<ARRAY_SIZE; i++){
            buckets[i] = new Bucket<V>();
        }
    }

    ~HashTable(){
        // delete[] buckets;
    }

    int hash(std::string key){
        int hash = 0;
        for(size_t i =0; i<key.size(); i++){
            hash = (hash << 5) + key[i];
            hash = (hash & hash) % num_buckets; // max value
        }
        return hash;
    }

    void add(std::string key, V value){
        keys.push_back(key);
        int index = hash(key);
        Bucket<V> *b = buckets[index];
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

    V operator[](std::string key){
        int k = hash(key);
        return buckets[k];
    }
    void remove(std::string key){

    }

    void print_hash_table(){

    }

    void add_bucket(); // helper functions
    V get_bucket();
    
private:

    size_t num_buckets; // array size
    Bucket<V> **buckets;
    std::vector<std::string> keys;
};

