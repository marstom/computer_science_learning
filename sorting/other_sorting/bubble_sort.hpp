#pragma once
#include <iostream>

template<typename T>
class BubbleSort{
public:
    BubbleSort(T *a, int s){
        arr = a;
        size = s;
        bubble_sort();
    }
private:
    void bubble_sort(){
        for(int last = size; last >= 0; last--){
            bubble_element(last);
        }

    }

    void bubble_element(int last){
        for(int i = 1; i < last; i++){
            if(arr[i-1] > arr[i]){
                std::swap(arr[i-1], arr[i]);
            }
        }
    }
    T *arr;
    int size;
};