#include <iostream>
#include "insertion_sort.hpp"
#include "selection_sort.hpp"
#include "bubble_sort.hpp"
using namespace std;

template<typename T>
void print_arr(T *arr, int len){
    // print array x len
    for(int i =0 ;i < len; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void test_in_sort(){
    int arr[] = {4,6,3,7,1,8,6,3,2,1}; // 10
    int len = 10;
    print_arr<int>(arr, len);

    cout << " sorted \n";
    insertion_sort<int>(arr, len);
    print_arr<int>(arr, len);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void test_selection_sort(){
    int arr[] = {4,6,3,7,1,8,6,3,2,1}; // 10
    int len = 10;
    print_arr<int>(arr, len);
    cout << " sorted \n";
    SelectionSort<int>(arr, len);
    print_arr<int>(arr, len);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void test_bubble_sort(){
    int arr[] = {4,6,3,7,1,8,6,3,2,1}; // 10
    int len = 10;
    print_arr<int>(arr, len);

    cout << " sorted \n";
    BubbleSort<int>(arr, len);
    print_arr<int>(arr, len);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~\n";
}

int main(){
    test_in_sort();    
    test_selection_sort();
    test_bubble_sort();
    return 0;
}