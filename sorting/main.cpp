#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;



class Mergesort{

public:
    Mergesort(int *ta, int size){
        N = size;
        t = new int[N];
        //tab = ta;
        tab = new int[N];
        //std::copy(ta[0], ta[N-1], tab);
        memcpy(tab, ta, N*sizeof(int));
        merge_sort(0, N-1);
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
    for(int i=0; i<N; i++){
        cout << tab[i] << endl;
    }
}

private:
    int N;
    int *tab;
    int *t;


};


void print_arr(int *arr){
    for(int i=0; i<4; i++){
        cout << arr[i] << endl;
    }
}


int main(){
    int arr[] = {4,3,2,1,9,12};
    Mergesort sorted(arr, 6);
    sorted.print_arr();

    return 0;
}
