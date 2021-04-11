#include "queue.h"

int main() {
    auto queue = Queue(5);
    std::cout << queue.add(Priority::third, 5) << std::endl;
    std::cout << queue.add(Priority::second, 8) << std::endl;
    std::cout << queue.add(Priority::third, 3) << std::endl;
    std::cout << queue.add(Priority::second, 3) << std::endl;
    std::cout << queue.add(Priority::first, 3) << std::endl;
    std::cout << queue.add(Priority::first, 3) << std::endl;
    std::cout << queue.add(Priority::first, 100000) << std::endl;
    std::cout << queue.add(Priority::first, 234) << std::endl;


    std::cout << queue << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue << std::endl;
    queue.add(Priority::third, 5);
    queue.add(Priority::second, 8);
    queue.add(Priority::third, 3);
    queue.add(Priority::second, 3);
    queue.add(Priority::first, 3);
    std::cout << queue << std::endl;


    Queue queueCopy = Queue(3);

    Queue queueCopy2 = Queue(2);

    queueCopy = queueCopy2 = queue;


    return 0;
}
