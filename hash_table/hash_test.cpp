
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

using namespace std;

 /**
 * Applies a supplemental hash function to a given hashCode, which
 * defends against poor quality hash functions.  This is critical
 * because HashMap uses power-of-two length hash tables, that
 * otherwise encounter collisions for hashCodes that do not differ
 * in lower bits. Note: Null keys always map to hash 0, thus index 0.
 */
static int hash1(int h) {
    // This function ensures that hashCodes that differ only by
    // constant multiples at each bit position have a bounded
    // number of collisions (approximately 8 at default load factor).
    h ^= (h >> 20) ^ (h >> 12);
    return h ^ (h >> 7) ^ (h >> 4);
}

// java using similiar algorithm
long long java_hash(string str){

    size_t n = str.size();
    long long result = 0;
    for(size_t i =0; i<n; i++){
        result = (long long)str[i] *(long long)pow(31, n - 1 - i); 
    }
    return result;
}

int hash3(string str){
    int hash = 0;
    for(size_t i =0; i<str.size(); i++){
        hash = (hash << 5) + str[i];
        hash = (hash & hash) % 100; // max value
    }
    return hash;
}

int main(){

    cout << hash1(25) << endl;
    cout << hash3("y2ssdf2to") << endl;
    return 0;
}
