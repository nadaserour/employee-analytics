#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP
#include <iostream>
#include <stdexcept>

using namespace std;

class PriorityQueue {
private:
    int* heap;
    int capacity;
    int size;

    void heapify(int index);
    void insert(int value);
    int extractMax();
    void resize(int newCapacity);

public:
    PriorityQueue(int initialCapacity = 10);
    ~PriorityQueue();
    void push(int value);
    int top();
    void pop();
    bool isEmpty();
    int getsize();
};

#endif
