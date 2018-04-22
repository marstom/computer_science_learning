#pragma once

template<typename T>
void insertion_sort(T *arr, int len){
    for(int i =2 ; i < len; i++){
        int key = arr[i];
        if(arr[i] < arr[i-1]){
            for(int j = i - 1; j>=0 && arr[j] > key; j--){
                arr[j + 1] = arr[j];
                arr[j] = key;
            }
        }
    }
}
