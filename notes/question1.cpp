/*
 * ./a 1> cout
 * ./a 2> cerr
 *
 *
 */

#include <iostream>
#include <stdexcept>

using namespace std;

int main(){

    cout << "output\n"; //stdout
    cerr << "to był błąd error out\n";
    cout << "exception will be now .......";

    throw std::range_error("Index is out of range exception"); // stderr
    throw std::logic_error("hmmmmmmmm");
    return 0;


}
