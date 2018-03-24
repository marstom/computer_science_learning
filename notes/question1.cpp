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

    cout << "normal output\n"; //stdout
    cerr << "stderr to był błąd error out\n";
    cout << "normal log";

    throw std::range_error("Index is out of range exception"); // stderr
    throw std::logic_error("hmmmmmmmm"); // stderr
    return 0;


}
