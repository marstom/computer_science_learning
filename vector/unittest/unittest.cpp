/*
 * expand 2*size
 * shrink size/4
 *
 * */
#include <iostream>
#include <string>
#include <stdexcept>
#include <gtest/gtest.h>
#include "../vector.hpp"

using namespace std;

TEST(Vector, is_empty) { 

    Vector<int> vec;
    ASSERT_TRUE(vec.is_empty());
    vec.push(21);
    ASSERT_FALSE(vec.is_empty());
}
 
TEST(Vector, capacity) { 
    Vector<int> vec;
    ASSERT_TRUE(vec.capacity() == 16);

    for(int i =0; i< 17; i++){
        vec.push(23*i);
    }
    cout << vec.capacity() << endl;
    ASSERT_TRUE(vec.capacity() == 32);
}

TEST(Vector, push) { 
    Vector<int> vec;

    for(int i =0; i< 12127; i++){
        vec.push(23*i);
    }

    for(int i =0; i< 12127; i++){
        vec.pop();
    }
}

TEST(Vector, insert) { 
}

TEST(Vector, prepend) { 
// this operation is rly show
    Vector<int> vec;

    for(int i =0; i< 12127; i++){
        vec.prepend(23*i);
    }

    for(int i =0; i< 12127; i++){
        vec.pop();
    }
}

TEST(Vector, pop) { 
    Vector<int> vec;
    vec.push(12);
    vec.pop();
    EXPECT_THROW(vec.pop(), std::out_of_range);
}


TEST(Vector, delete_) { 
    Vector<int> vec;

    for(int i =0; i< 127; i++){
        vec.prepend(23*i);
    }

    vec.del(126);
}

TEST(Vector, remove) { 
    Vector<int> vec;
    for(int i =0; i< 100; i++){
        if(i%2)
            vec.prepend(i);
        else
            vec.push(155);
    }
    vec.remove(155);
    cout << vec.size() << endl;
    ASSERT_TRUE(vec.size() == 50);
}


TEST(Vector, find) { 

}


TEST(Vector, resize) { 
    Vector<int> vec;
    ASSERT_TRUE(vec.capacity() == 16);
    for(int i =0; i< 12127; i++){
        vec.push(23*i);
    }

    cerr << vec.capacity() << endl;
    ASSERT_TRUE(vec.capacity() == 16384);
    for(int i =0; i< 12126; i++){
        vec.pop();
    }
    cerr << vec.capacity() << endl;
    ASSERT_TRUE(vec.capacity() == 16);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
