#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include "merge_sort.hpp"
using namespace std;


void sv_img(){


}
int main(){
    int arr[] = {4,3,2,1,9,12,91,43,5,0};
    Mergesort<int> sorted(arr, 10);
    sorted.print_arr();
//    print_arr(arr, 6);

    char* napis = strdup("To jest napis w c! Do posortowania. Strdup sprawia ze nie jest const i mozna go modyfikowac.");
    // char* napis = strdup("Tomek !!!");
    Mergesort<char> sor(napis, strlen(napis));
    sor.print_arr();
    return 0;
}
