#include <iostream>
#include <string>
#include "vector.hpp"

using namespace std;

void test0(){
    Vector<int> vector;
    for(int i=0; i<499; i++){
        vector.push(1+i*2);
    }

    vector.prepend(23);
    vector.prepend(24);
    vector.prepend(29);
    vector.insert(10, 9999);
    //vector.del(3);
    cout << vector.at(0) << endl;
    cout << vector.at(3) << endl;
    cout << vector.at(9) << endl;
    cout << vector.find(244) << endl;
}

void test1(){
    Vector<string> vec;
    vec.push("Tomek");
    vec.push("Maciek");
    vec.push("Tomek3");
    vec.push("Tomek4");
    vec.prepend("Hoanna");
    cout << vec.find("Tomek") << endl;

}
int main(){
    // test0();
    test1();
    return 0;
}
