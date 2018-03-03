#include <iostream>
#include <string>
#include <stdexcept>
#include <gtest/gtest.h>
#include "../array_queue.hpp"
#include "../list_queue.hpp"

using namespace std;
using namespace container;
stringstream ss;



TEST(Array_queue, dequeue) { 
    ArrayQueue<int> array_queue(6);
    array_queue.enqueue(1);
    array_queue.enqueue(2);
    array_queue.enqueue(3);
    array_queue.enqueue(4);
    ASSERT_EQ(array_queue.dequeue(), 1);
    ASSERT_EQ(array_queue.dequeue(), 2);
    ASSERT_EQ(array_queue.dequeue(), 3);
}

TEST(Array_queue, dequeue_out_of_range) { 
    ArrayQueue<int> array_queue(6);
    array_queue.enqueue(1);
    array_queue.enqueue(2);
    ASSERT_EQ(array_queue.dequeue(), 1);
    ASSERT_EQ(array_queue.dequeue(), 2);
    ASSERT_THROW(array_queue.dequeue(),  std::length_error);

}

TEST(Array_queue, enqueue_full) { 
    ArrayQueue<int> array_queue(4);
    array_queue.enqueue(1);
    array_queue.enqueue(2);
    array_queue.enqueue(2);
    array_queue.enqueue(2);
    ASSERT_THROW(array_queue.enqueue(23),  std::length_error);
}

TEST(Array_queue, many_queues_dequeues) { 
    ArrayQueue<int> array_queue(6);
    array_queue.enqueue(1);
    array_queue.enqueue(2);
    array_queue.enqueue(5);
    array_queue.enqueue(5);
    array_queue.enqueue(5);
    ASSERT_TRUE(array_queue.length() == 5);
    array_queue.dequeue();
    array_queue.dequeue();
    array_queue.dequeue();
    array_queue.dequeue();

    ASSERT_TRUE(array_queue.length() == 1);
    array_queue.dequeue();
    ASSERT_TRUE(array_queue.length() == 0);

    array_queue.enqueue(5);
    array_queue.dequeue();
    array_queue.enqueue(5);
    array_queue.dequeue();
    array_queue.enqueue(5);
    array_queue.enqueue(5);
}

TEST(ListQueue, enqueue){
    ListQueue<string> qu;
    qu.enqueue("Tomek");
    qu.enqueue("Maciek");
    ASSERT_EQ(qu.dequeue(), "Tomek");

}

TEST(ListQueue, enqueueLong){
    ListQueue<int> qu;
    for(int i = 0; i<10000; i++){
        qu.enqueue(i*2);
    }

    for(int i = 0; i<5000; i++){
        qu.dequeue();
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
