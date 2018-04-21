#pragma once

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;


template<typename T>
class Mergesort{
public:
    Mergesort(T *ta, int s){
        size = s;
        t = new T[size];
        tab = ta;
        // tab = new int[size];
        // memcpy(tab, ta, size*sizeof(int));
        merge_sort(0, size-1);
    }

    ~Mergesort(){
        delete[] t;
    }

    void merge(int begin, int middle, int end){
        int i, j, q;
        for(i = begin; i<=end; i++){
            t[i] = tab[i];
        }
        i = begin;
        j = middle+1;
        q = begin;

        while(i <= middle && j <=end){
            if(t[i]<t[j]){
                tab[q++] = t[i++];
            }else{
                tab[q++] = t[j++];
            }
        }

        while(i <= middle){
            tab[q++] = t[i++];
        }
    }

    void merge_sort(int begin, int end){
        int middle;
        if(begin < end){
            middle = (begin + end)/2;
            merge_sort(begin, middle);
            merge_sort(middle + 1, end);
            merge(begin, middle, end);
        }
    }

    void print_arr(){
        for(int i=0; i<size; i++){
            cout << tab[i] << ' ';
        }
        cout << endl;
    }

private:
    int size;
    T *tab;
    T *t;
};

// helper function
void print_arr(int *arr, int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << endl;
    }
}

