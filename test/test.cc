#include <gtest/gtest.h>
#include "../include/Priority_queue.hpp"


template<typename T>
using MinPQ = Priority_queue<T, std::vector<T>, std::less<T>>;

template<typename T>
using MaxPQ = Priority_queue<T, std::vector<T>, std::greater<T>>;


TEST(PriorityQueueTest, DefaultConstructor) {
    MaxPQ<int> pq;
    EXPECT_TRUE(pq.empty());
    EXPECT_EQ(pq.size(), 0);
}

TEST(PriorityQueueTest, PushElementsAndTopMaxHeap) {
    MaxPQ<int> pq;
    pq.push(3);
    pq.push(5);
    pq.push(1);
    EXPECT_EQ(pq.top(), 5);
}

TEST(PriorityQueueTest, PushElementsAndTopMinHeap) {
    MinPQ<int> pq;
    pq.push(3);
    pq.push(5);
    pq.push(1);
    EXPECT_EQ(pq.top(), 1);
}

TEST(PriorityQueueTest, PopReducesSize) {
    MaxPQ<int> pq{4, 7, 2};
    size_t old_size = pq.size();
    pq.pop();
    EXPECT_EQ(pq.size(), old_size - 1);
}

TEST(PriorityQueueTest, TopAfterMultiplePushAndPop) {
    MaxPQ<int> pq;
    pq.push(2);
    pq.push(10);
    pq.push(7);
    pq.pop(); 
    EXPECT_EQ(pq.top(), 7);
}

TEST(PriorityQueueTest, InitializerListConstructorWorks) {
    MaxPQ<int> pq = {1, 6, 3};
    EXPECT_EQ(pq.top(), 6);
    EXPECT_EQ(pq.size(), 3);
}

TEST(PriorityQueueTest, CopyConstructorCreatesSameQueue) {
    MaxPQ<int> pq1 = {5, 1, 8};
    MaxPQ<int> pq2 = pq1;
    EXPECT_EQ(pq2.top(), pq1.top());
    EXPECT_EQ(pq2.size(), pq1.size());
}

TEST(PriorityQueueTest, MoveConstructorTransfersOwnership) {
    MaxPQ<int> pq1 = {2, 9, 4};
    MaxPQ<int> pq2 = std::move(pq1);
    EXPECT_EQ(pq2.top(), 9);
    EXPECT_EQ(pq1.size(), 0);
}

TEST(PriorityQueueTest, CopyAssignmentWorks) {
    MaxPQ<int> pq1 = {2, 5};
    MaxPQ<int> pq2;
    pq2 = pq1;
    EXPECT_EQ(pq2.top(), 5);
}

TEST(PriorityQueueTest, MoveAssignmentWorks) {
    MaxPQ<int> pq1 = {7, 3};
    MaxPQ<int> pq2;
    pq2 = std::move(pq1);
    EXPECT_EQ(pq2.top(), 7);
    EXPECT_TRUE(pq1.empty());
}

TEST(PriorityQueueTest, ThrowOnTopWhenEmpty) {
    MaxPQ<int> pq;
    EXPECT_THROW(pq.top(), std::out_of_range);
}

TEST(PriorityQueueTest, ThrowOnPopWhenEmpty) {
    MaxPQ<int> pq;
    EXPECT_THROW(pq.pop(), std::out_of_range);
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();	
}
