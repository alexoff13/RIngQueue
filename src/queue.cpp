#include "queue.h"


Queue::Queue(unsigned int size) {
    this->size = size > 0 ? size + 1 : defaultSize;
    this->vector = new Node *[this->size];

    this->clear();
}

Queue::Queue(const Queue &queue) {
    this->size = queue.size;
    this->vector = new Node *[this->size];
    this->head = queue.head;
    this->tale = queue.tale;
    for (unsigned int i = queue.head; i % queue.size != (queue.tale + 1) % queue.size; ++i) {
        this->vector[i % queue.size]->priority = queue.vector[i % queue.size]->priority;
        this->vector[i % queue.size]->value = queue.vector[i % queue.size]->value;
    }
}

Queue::~Queue() {
    delete[] vector;
}

int Queue::add(Priority priority, int value) {
    if (head == (tale + 2) % size) {
        return OVERFLOWED;
    }

    int i = head;
    for (i; i < size; ++i) {
        int tmp = 0;
        if (vector[i] == nullptr) {
            vector[i] = new Node(priority, value);
            tale += 1;
            tale = tale % size;
            break;
        } else if (vector[i]->priority > priority) {
            tmp = i;
            tale = (tale + 1) % size;
            Node **values2 = new Node *[size];

            for (int i = 0; i < tmp; i++)
                values2[i] = vector[i];

            values2[tmp] = new Node(priority, value);

            for (int i = tmp + 1; i < size; i++)
                values2[i] = vector[i - 1];

            std::swap(vector, values2);
            break;
        }

    }
    return SUCCESS;
}

Node *Queue::pop() {
    if (getLength() == 0) {
        throw EMPTY;
    } else if (getLength() == 1) {
        Node *res = vector[head];
        clear();
        return res;
    }
    Node *res = vector[head];
    head = (head + 1) % size;
    return res;

}

void Queue::clear() {
    this->head = 0;
    this->tale = this->size - 1;
    for (int i = 0; i < size; ++i)
        vector[i] = nullptr;
}

unsigned int Queue::getLength() const {
    return (size - head + tale + 1) % size;
}

std::ostream &operator<<(std::ostream &out, const Queue &queue) {
    if (queue.getLength() == 0) {
        out << "Empty queue";
    } else {
        out << "(value-> " << queue.vector[queue.head]->value << " | " << queue.vector[queue.head]->priority
            << " <-priority)";
        for (unsigned int i = queue.head + 1; i % queue.size != (queue.tale + 1) % queue.size; ++i) {
            out << ", " << "(value-> " << queue.vector[i % queue.size]->value << " | "
                << queue.vector[i % queue.size]->priority
                << " <-priority)";
        }
    }
    return out;
}


Queue &Queue::operator=(const Queue &queue) {
    this->head = 0;
    if (queue.getLength() == 0) {
        this->tale = this->size - 1;
    } else if (this->size > queue.getLength()) {
        this->tale = queue.getLength() - 1;
        for (unsigned int i = queue.head, j = 0; i % queue.size != (queue.tale + 1) % queue.size; ++i, ++j) {
            if (this->vector[j] == nullptr) {
                this->vector[j] = new Node(queue.vector[i % queue.size]->priority, queue.vector[i % queue.size]->value);
            } else {
                this->vector[j]->priority = queue.vector[i % queue.size]->priority;
                this->vector[j]->value = queue.vector[i % queue.size]->value;
            }
        }
    } else {
        this->tale = this->size - 2;
        for (unsigned int i = queue.head, j = 0; j <= this->tale; ++i, ++j) {
            this->vector[j] = queue.vector[i % queue.size];
        }
    }
    return *this;
}


