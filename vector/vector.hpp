#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

template<typename T>
class Vector{
public:
    Vector(): m_size(16), m_index(0){
        array = new T[m_size]; 
    }

    ~Vector(){
        delete[] array;
    }

    // number of items
    size_t size(){
        return m_index;
    }

    //number of items it can hold
    size_t capacity(){
        return m_size;
    }

    bool is_empty(){
        return m_index == 0; 
    }

    // returns item at given index, blows up if index out of bounds
    T at(size_t index){
        if(index >= m_index){
            throw std::out_of_range("Item is out of range");
        }
        return *(array+index);
    }
    
    void push(T item){
        if(m_index == m_size){
            expand();
        }
        *(array + m_index) = item; 
        m_index++;
    }

    //  inserts item at index, shifts that index's value and trailing elements to the right
    void insert(size_t index, T item){

    }
    // can use insert above at index 0
    void prepend(T item){
        for(size_t i = m_index-1; i >= 0; i--){
            *(array+i+1) = *(array+i);
        }
        //*(array) = item;
        //TODO resize if full
    }

    // remove from end, return value
    void pop(){
        m_index--;
        if(m_index < m_size/4){
            shrink();
        }
    }

    // delete item at index, shifting all trailing elements left
    void del(size_t index){

    }

    // looks for value and removes index holding it (even if in multiple places)
    void remove(T item){
    
    }
    
    //  looks for value and returns first index with that value, -1 if not found
    int find(T item){

    }

    void resize(size_t new_capacity){

    }

private:

    void shrink(){
        T* temp = new T[m_size / 4];
        memcpy(temp, array, (m_size/4) * sizeof(T));
        delete[] array;
        array = temp;
        m_size /= 4;
    }


    void expand(){
        T* temp = new T[m_size * 2];
        memcpy(temp, array, m_size * sizeof(T));
        delete[] array;
        array = temp;
        m_size *= 2;
    }

    T* array;
    size_t m_size;
    size_t m_index;
};

