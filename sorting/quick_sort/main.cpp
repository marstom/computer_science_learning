#include <iostream>
#include <cstdio>
#include "quick_sort.hpp"
using namespace std;


int main(){
    Quicksort qs;
    int len = 10;
    int arr[] = {112,332,434,1,5,4,2,6,9,7}; // 6
    qs.quick_sort(arr, 0, len-1);
    qs.print(arr, len);
     
    return 0;
}
