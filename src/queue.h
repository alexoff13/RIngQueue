#ifndef RINGQUEUE_QUEUE_H
#define RINGQUEUE_QUEUE_H

#include <iostream>


class Queue {
private:


    static const unsigned int defaultSize = 5;
    unsigned int size;
    unsigned int head{};
    unsigned int tale{};
    int *values;
    int *priorities;

    void insertValue(int i, int value, int priority);

public:
    const int SUCCESS = 0;     // функция выполнена успешно
    const int OVERFLOWED = -1; // добавление невозможно, т.к. весь вектор заполнен
    const int EMPTY = -2;      // удаление невозможно, т.к. вектор пуст

    explicit Queue(unsigned int);

    Queue(const Queue &queue);

    ~Queue();

    int push(int priority, int value);

    int pop();

    void clear();

    [[nodiscard]] unsigned int getLength() const;

    friend std::ostream &operator<<(std::ostream &, const Queue &);

    Queue &operator=(const Queue &);
};


#endif
