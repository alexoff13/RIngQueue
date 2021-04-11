#ifndef RINGQUEUE_QUEUE_H
#define RINGQUEUE_QUEUE_H

#include <iostream>

enum Priority {
    first,
    second,
    third

};

struct Node {
    Priority priority;
    int value;

    explicit Node(Priority priority_, int value_) : value(value_), priority(priority_) {}
};

class Queue {
private:


    static const unsigned int defaultSize = 5;
    unsigned int size;
    unsigned int head{};
    unsigned int tale{};
    Node **vector;
public:
    const int SUCCESS = 0;     // функция выполнена успешно
    const int OVERFLOWED = -1; // добавление невозможно, т.к. весь вектор заполнен
    const int EMPTY = -2;      // удаление невозможно, т.к. вектор пуст

    explicit Queue(unsigned int);

    Queue(const Queue &queue);

    ~Queue();

    int add(Priority priority, int value);

    Node *pop();

    void clear();

    [[nodiscard]] unsigned int getLength() const;

    friend std::ostream &operator<<(std::ostream &, const Queue &);

    Queue &operator=(const Queue &);
};


#endif
