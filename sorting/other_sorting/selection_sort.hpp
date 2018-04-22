/*
    Selection sort O^2
*/
#pragma once

template<typename T>
class SelectionSort{
public:

    SelectionSort(T *a, int s){
        arr = a;
        size = s;
        selection_sort();
    }

    void selection_sort(){
        for(int selection= 0; selection < size; selection++){
            int smallest = smallest_index(selection, size);
            std::swap(arr[selection], arr[smallest]);
        }
    }

    int smallest_index(int start, int end){
        int smallest = arr[start];
        int smallest_index = start;
        for(int i = start; i < end; i++){
           if(arr[i] < smallest){
               smallest_index = i;
               smallest = arr[i];
           }
        }
        return smallest_index;
    }

private:
    T *arr;
    int size;
};