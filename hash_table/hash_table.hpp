/*
 * Hash use linear probing,
 * key is string type
 *
 *
 */
#pragma once
#define ARRAY_SIZE 10
#define LARGE_PRIME 443555
#define _A 3214
#define _B 4357
#include <string>
#include <vector>
#include <stdexcept>
#include <cstring>


template<typename T>
struct Node{
    Node(){
    }
    Node(std::string k, T d){
        key = k;
        data = d;
    }
    std::string key;
    T data;
    Node* next = nullptr;

};

template<typename T>
class Bucket{
public:
    Bucket(): root(nullptr){
    }

    void push_back(std::string key, T el){
        if(root == nullptr){
            root = new Node<T>();
        }
        if(root->key == key){
            root->data = el;
        }
        else{
            root->next = new Node<T>(key, el);
        }
    }

    T find(std::string key){
        Node<T>* element = root;
        while(element != nullptr){
            if(element->key == key){
                return element->data;
            }
            element = element->next;
        }
        throw std::length_error("No such element");
    }

    void remove(std::string key){
        Node<T>* element = root;
        while(element != nullptr){
            if(element != nullptr && element->next->key == key){
                if(element->next != nullptr){
                    // this is not last element
                    element = element->next->next;
                }
                delete element->next;
            }
            element = element->next;
        }
        throw std::length_error("No such element");
    }

    bool exists(std::string key){
        Node<T>* element = root;
        while(element != nullptr){
            if(element->key == key){
                return true;
            }
            element = element->next;
        }
        return false;
    }
private:
    Node<T> *root;
};

template<typename T>
class HashTable{
public:

    HashTable(): num_buckets(ARRAY_SIZE){
        buckets = new Bucket<T>[ARRAY_SIZE];
    }

    ~HashTable(){
         delete[] buckets;
    }

    void add(std::string key, T value){
        keys.push_back(key);
        int index = hash(key);
        buckets[index].push_back(key, value);
    }

    bool exists(std::string key){
        // do it by hash TODO
        for(size_t i=0; i<ARRAY_SIZE-1; i++){
            if(buckets[i].exists(key))
                return true;
        }
        return false;
    }

    T operator[](std::string key){
        int k = hash(key);
        Bucket<T> b = buckets[k];
        T el = b.find(key);
        return el;
    }
    void remove(std::string key){
        int k = hash(key);
        Bucket<T> b = buckets[k];
        b.remove(key);
    }

    void print_hash_table(){

    }

    void add_bucket(){} // helper functions
    T get_bucket(){}
    
private:

    int hash(std::string key){
        /*
            [(a*k+b) mod p] mod m
            a b -randof 0..p-1
            p big prime number, must be bigger than ARRAY_SIZE
            m table_size
        */
        int h = 0;
        for(auto k: key){
            h += ((_A*k+_B) % LARGE_PRIME) % ARRAY_SIZE;
        }
        return h % ARRAY_SIZE;
    }

    size_t num_buckets; // array size
    Bucket<T> *buckets;
    std::vector<std::string> keys;
};

