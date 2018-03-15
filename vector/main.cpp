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

void test2(){

    Vector<int> vector;
    vector.push(2);
    vector.push(5);
    vector.push(2);
    vector.push(7);
    vector.push(9);
    vector.push(2);
    vector.remove(2);
    Vector<int> vec2 = vector;
    Vector<int> vec3 = vec2;
    for(int i=0; i<vec3.size(); i++){
        cout << vector[i] << endl;
    }

    cout << "Equal" <<  (vector == vec2) << endl;


}

int main(){
    test0();
    test1();
    test2();
    return 0;
}
