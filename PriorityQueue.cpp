#include <iostream>
#include <stdexcept>
#include "PriorityQueue.hpp"

using namespace std;

void PriorityQueue::heapify(int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }

    if (rightChild < size && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapify(largest);
    }
}

void PriorityQueue::insert(int value) {
    if (size == capacity) {
        resize(capacity * 2);
    }

    heap[size] = value;
    int index = size;
    size++;

    while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

int PriorityQueue::extractMax() {
    if (size == 0) {
        throw runtime_error("Priority Queue is empty!");
    }

    int maxElement = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapify(0);

    return maxElement;
}

void PriorityQueue::resize(int newCapacity) {
    int* newHeap = new int[newCapacity];
    for (int i = 0; i < size; i++) {
        newHeap[i] = heap[i];
    }
    delete[] heap;
    heap = newHeap;
    capacity = newCapacity;
}

PriorityQueue::PriorityQueue(int initialCapacity) {
    capacity = initialCapacity;
    heap = new int[capacity];
    size = 0;
}

PriorityQueue::~PriorityQueue() {
    delete[] heap;
}

void PriorityQueue::push(int value) {
    insert(value);
}

int PriorityQueue::top() {
    if (size == 0) {
        throw runtime_error("Priority Queue is empty!");
    }
    return heap[0];
}

void PriorityQueue::pop() {
    extractMax();
}

bool PriorityQueue::isEmpty() {
    return size == 0;
}

int PriorityQueue::getsize() {
    return size;
}