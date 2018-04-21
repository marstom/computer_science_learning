#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class Quicksort{
public:

    void quick_sort(int *arr, int lo, int hi){
        if(lo < hi){
            p = partition(arr, lo, hi);
            quick_sort(arr, lo, p - 1);
            quick_sort(arr, p + 1, hi);
        }
    }

    int partition(int *arr, int lo, int hi){
        pivot = arr[hi];
        int i = lo - 1;
        for(int j = lo; j <= hi - 1; j++){
            if(arr[j] < pivot){
                i += 1;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i+1], arr[hi]);
        return i + 1;
    }

    void print(int *arr, int s){
        for(int i=0; i<s; i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
private:
    int pivot;
    int p;
};
