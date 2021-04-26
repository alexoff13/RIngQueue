#include "queue.h"

int main() {
    // auto queue = Queue(9);
    Queue queue(10);
    Queue queue1(12);
//    queue.push(3,2);
    std::cout<<queue<<std::endl;
    for (int i = 1; i < 12; i++) {
        queue1.push(i % 5 + 2, i * 10);

    }
    queue = queue1;
    std::cout<<queue<<std::endl;
    std::cout<<queue1<<std::endl;
//
//    std::cout << queue << std::endl;
//    std::cout << queue.getLength() << std::endl;
//
//    std::cout << queue1 << std::endl;
//    std::cout << queue1.getLength() << std::endl;
//
//
//    for (int i = 1; i < 10; i++) {
//        queue.pop();
//        queue1.pop();
//
//    }
//    std::cout << queue << std::endl;
//    std::cout << queue.getLength() << std::endl;
//    std::cout << queue1 << std::endl;
//    std::cout << queue1.getLength() << std::endl;
//
//    std::cout << std::endl << "--------------------------------------------" << std::endl;
//
//    for (int i = 1; i < 5; i++) {
//        queue.push(0, i);
//        queue1.push(0, i * 10);
//
//    }
//
//    std::cout << queue << std::endl;
//    std::cout << queue.getLength() << std::endl;
//
//    std::cout << queue1 << std::endl;
//    std::cout << queue1.getLength() << std::endl;
//
//
//    std::cout << std::endl << "--------------------------------------------" << std::endl;
//    queue = queue;
//    std::cout << queue << std::endl;
//    std::cout << queue.getLength() << std::endl;
//
//

    /* std::cout << queue << std::endl;

     std::cout << queue.getLength() << std::endl;
     auto queue2 = queue;
     std::cout << queue2 << std::endl;
     std::cout << queue2.getLength() << std::endl;
     std::cout << queue2.pop() << std::endl;
     std::cout << queue2.pop() << std::endl;
     std::cout << queue << std::endl;
     std::cout << queue2 << std::endl;*/



    return 0;
}