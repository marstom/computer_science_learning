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
#include <iostream>

using namespace std;

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
    Bucket(): head(nullptr){
    }

    void push_back(std::string key, T el){
        if(head == nullptr){
            head = new Node<T>();
        }
        if(head->key == key){
            head->data = el;
        }
        else{
            head->next = new Node<T>(key, el);
        }
    }

    T find(std::string key){
        Node<T>* element = head;
        while(element != nullptr){
            if(element->key == key){
                return element->data;
            }
            element = element->next;
        }
        throw std::length_error("No such element");
    }

    void remove(std::string key){
        Node<T> *el = head;
        Node<T> *prev = el;
        while(el != nullptr){
            if(el->key == key){
                Node<T> *current = el;
                Node<T> *next = el->next;
                prev->next = next;
                delete current;
            }
            prev = el;
            el = el->next;
        }
    }

    bool exists(std::string key){
        Node<T>* element = head;
        while(element != nullptr){
            if(element->key == key){
                return true;
            }
            element = element->next;
        }
        return false;
    }
private:
    Node<T> *head;
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
        int k = hash(key);
        if(buckets[k].exists(key))
            return true;
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

private:

    int hash(std::string key){
        /*
            universal hashing - from MIT lecture
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

    int hash_crc16(){}

    size_t num_buckets; // array size
    Bucket<T> *buckets;
    std::vector<std::string> keys;
};

