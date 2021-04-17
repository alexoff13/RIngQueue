#include "queue.h"


Queue::Queue(unsigned int size) {
    this->size = size > 0 ? size + 1 : defaultSize;
    this->values = new int[this->size];
    this->priorities = new int[this->size];

    this->clear();
}

Queue::Queue(const Queue &queue) {
    this->size = queue.size;
    this->values = new int[this->size];
    this->priorities = new int[this->size];
    this->head = queue.head;
    this->tale = queue.tale;
    for (unsigned int i = queue.head; i % queue.size != (queue.tale + 1) % queue.size; ++i) {
        this->values[i % queue.size] = queue.values[i % queue.size];
        this->priorities[i % queue.size] = queue.priorities[i % queue.size];
    }
}

Queue::~Queue() {
    delete[] priorities;
    delete[] values;
}

//5 удалить и 10 добавить
int Queue::push(int priority, int value) {
    if (head == (tale + 2) % size) {
        return OVERFLOWED;
    }
    int tmp;
    if (priorities[head] < priority) {
        tmp = head;
        insertValue(tmp, value, priority);
        return SUCCESS;
    }
    for (unsigned int i = head + 1; i % size != (tale + 1) % size; ++i) {
        int asdas = priorities[i];
        int asdasddasd = values[i];
        if (priorities[i] < priority) {
            tmp = i;
            insertValue(tmp, value, priority);
            return SUCCESS;
        }
    }
    tale = (tale + 1) % size;
    priorities[tale] = priority;
    values[tale] = value;
    return SUCCESS;
}

void Queue::insertValue(int j, int value, int priority) {
    std::swap(value, values[j]);
    std::swap(priority, priorities[j]);
    tale = (tale + 1) % size;

    for (unsigned int i = j + 1; i % size != (tale + 1) % size; ++i) {
        std::swap(value, values[i % size]);
        std::swap(priority, priorities[i % size]);
    }
}

int Queue::pop() {
    if (getLength() == 0) {
        return EMPTY;
    } else if (getLength() == 1) {
        int res = values[head];
        clear();
        return res;
    }
    int res = values[head];
    priorities[head] = -1;
    head = (head + 1) % size;
    return res;

}

void Queue::clear() {
    this->head = 0;
    this->tale = this->size - 1;
    for (int i = 0; i < size; i++) {
        this->priorities[i] = -1;
    }
}

unsigned int Queue::getLength() const {
    return (size - head + tale + 1) % size;
}

std::ostream &operator<<(std::ostream &out, const Queue &queue) {
    if (queue.getLength() == 0) {
        out << "Empty queue";
    } else {
        out << "(value-> " << queue.values[queue.head] << " | " << queue.priorities[queue.head]
            << " <-priority)";
        for (unsigned int i = queue.head + 1; i % queue.size != (queue.tale + 1) % queue.size; ++i) {
            out << ", " << "(value-> " << queue.values[i % queue.size] << " | "
                << queue.priorities[i % queue.size]
                << " <-priority)";
        }
    }
//    for (int i=0;i<queue.size-1;i++){
//        out << ", " << "(value-> " << queue.values[i] << " | "
//                << queue.priorities[i]
//                << " <-priority)";
//    }
    return out;
}


Queue &Queue::operator=(const Queue &queue) {
    this->head = 0;
    if (queue.getLength() == 0) {
        this->tale = this->size - 1;
    } else if (this->size > queue.getLength()) {
        this->tale = queue.getLength() - 1;
        for (unsigned int i = queue.head, j = 0; i % queue.size != (queue.tale + 1) % queue.size; ++i, ++j) {
            this->values[j] = queue.values[i % queue.size];
            this->priorities[j] = queue.priorities[i % queue.size];
        }
    } else {
        this->tale = this->size - 2;
        for (unsigned int i = queue.head, j = 0; j <= this->tale; ++i, ++j) {
            this->values[j] = queue.values[i % queue.size];
            this->priorities[j] = queue.priorities[i % queue.size];
        }
    }
    return *this;
}


