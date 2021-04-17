#include "gtest/gtest.h"
#include "../src/queue.h"

using namespace std;

TEST(test, SimpleTestAdd) {
    auto queue = Queue(4);
    queue.push(2, 5);
    queue.push(2, 5);
    queue.push(2, 5);
    queue.push(2, 5);
    int code = queue.push(2, 5);
    ASSERT_EQ(code, -1);
}

TEST(test, SimpleTestPop) {
    auto queue = Queue(4);
    queue.push(2, 5);
    queue.push(2, 5);
    queue.push(2, 5);
    queue.push(2, 5);
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();
    ASSERT_EQ(queue.getLength(), 0);
}

TEST(test, SimpleTestCopy) {
    auto queue = Queue(4);
    queue.push(2, 5);
    queue.push(2, 5);
    queue.push(2, 5);
    queue.push(2, 5);
    Queue queueCopy = Queue(3);

    Queue queueCopy2 = Queue(2);

    queueCopy = queueCopy2 = queue;

    ASSERT_EQ(queueCopy.getLength(), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}