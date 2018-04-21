#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
using namespace std;


class Quicksort{
public:
    Quicksort(){
    }

    void quick_sort(int *arr, int lo, int hi){
        if(lo < hi){
            p = partition(arr, lo, hi);
            quick_sort(arr, lo, p - 1);
            quick_sort(arr, p + 1, hi);
        }
    }

    void quick_sort2(int *arr, int lo, int hi){
        if(lo < hi){
            p = partition(arr, lo, hi);
            quick_sort(arr, lo, p);
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

    int partition2(int *arr, int lo, int hi){
        int pivot = arr[lo];
        int i = lo - 1;
        int j = hi + 1;
        while(1){
            do{
                i++;
            }while(arr[i] < pivot);

            do{
                j--;
            }while(arr[j] > pivot);

            if(i >= j){
                return j;
            }
            std::swap(arr[i], arr[j]);
        }
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

int main(){
    Quicksort qs;
    cout << "QS\n";
    int a[] = {1,2,3};
    int b[] = {5,7,9};
    std::swap(a[1],b[1]);

    int len = 10;
    int arr[] = {112,332,434,1,5,4,2,6,9,7}; // 6
    qs.quick_sort2(arr, 0, len-1);
    qs.print(arr, len);
     
    return 0;
}
