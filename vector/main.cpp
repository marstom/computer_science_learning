#include <iostream>
#include <string>
#include "vector.hpp"

using namespace std;


int main(){
    Vector<int> vector;
    for(int i=0; i<480; i++){

        vector.push(1+i*2);
    }

    vector.prepend(23);

    cout << vector.at(470) << endl;
    cout << vector.at(0) << endl;


    return 0;
}
