#include "queue.h"

int main() {
    auto queue = Queue(9);

    std::cout << queue << std::endl;
    for (int i = 1; i < 10; i++){
        std::cout << (i % 3) << ", " << i << ", " << queue.push((i % 3), i) << std::endl;}
//    std::cout << queue << std::endl;}

//    std::cout << queue << std::endl;
//    std::cout << queue.getLength() << std::endl;

    for (int i = 1; i <= 5; i++)
        queue.pop();
//    std::cout << queue << std::endl;
//    std::cout << queue.getLength() << std::endl;


    std::cout << queue << std::endl;
    for (int i = 1; i < 5; i++) {
        std::cout << i%3 << " " << i * 10 << " -> " << queue.push(i%3, i * 10) << std::endl;
//        std::cout << queue << std::endl;
//        std::cout << queue.getLength() << std::endl;
    }

    std::cout << queue << std::endl;
    std::cout << queue.getLength() << std::endl;
    /*  std::cout << queue.push(Priority::third, 5) << std::endl;
      std::cout << queue.push(Priority::second, 8) << std::endl;
      std::cout << queue.push(Priority::third, 3) << std::endl;
      std::cout << queue.push(Priority::second, 3) << std::endl;
      std::cout << queue.push(Priority::first, 3) << std::endl;
      std::cout << queue.push(Priority::first, 3) << std::endl;
      std::cout << queue.push(Priority::first, 100000) << std::endl;
      std::cout << queue.push(Priority::first, 234) << std::endl;
      std::cout << queue << std::endl;
      std::cout << queue.pop() << std::endl;
      std::cout << queue.pop() << std::endl;
      std::cout << queue.pop() << std::endl;
      std::cout << queue.pop() << std::endl;
      std::cout << queue.pop() << std::endl;
      std::cout << queue.pop() << std::endl;
      std::cout << queue << std::endl;
      queue.push(Priority::third, 5);
      queue.push(Priority::second, 8);
      queue.push(Priority::third, 3);
      queue.push(Priority::second, 3);
      queue.push(Priority::first, 3);
      std::cout << queue << std::endl;
      Queue queueCopy = Queue(3);
      Queue queueCopy2 = Queue(2);
      queueCopy = queueCopy2 = queue;
  */
    return 0;
}