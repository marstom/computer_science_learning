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

    Vector(const Vector<T>& vec2){
        array = new T[vec2.m_size];
        array = vec2.array;
        m_index = vec2.m_index;
        m_size = vec2.m_size;
    }

    virtual ~Vector(){
        //delete[] array; //  double free or corruption (fasttop): 0x00000000007a4060
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


    T operator[](int index){
        return at(index);
    }
    
    bool operator==(const Vector<T>& v){
        for(int i=0; i< m_index; i++){
            if(v.array[i] != array[i])
                return false;
            return true;
        }
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
        if(m_index == m_size){
            expand();
        }
        for(int i = m_index-1; i >= index; i--){
            *(array+i+1) = *(array+i);
        }
        *(array+index) = item;
        m_index++;
    }
    // can use insert above at index 0
    void prepend(T item){
        if(m_index == m_size){
            expand();
        }
        for(int i = m_index-1; i >= 0; i--){
            *(array+i+1) = *(array+i);
        }
        *(array) = item;
        m_index++;
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
        for(int i = index; i< m_index -1; i++){
            *(array+i) = *(array+i+1);
        }
        m_index--;
        if(m_index < m_size/4){
            shrink();
        }
    }

    // looks for value and removes index holding it (even if in multiple places)
    void remove(T item){
        for(int found=find(item);found != -1; found=find(item)){
            del(found);
        }
    }
    
    //  looks for value and returns first index with that value, -1 if not found, find first occurence
    int find(T item){
        for(int i=0; i< m_index; i++){
            if(array[i] == item){
                return i;
            }
        }
        return -1;
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

