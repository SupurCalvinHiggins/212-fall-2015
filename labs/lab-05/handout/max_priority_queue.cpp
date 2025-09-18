#include "max_priority_queue.h"

MaxPriorityQueue::MaxPriorityQueue() {
    // TODO: Initialize an empty max-priority queue. The underlying data structure should be a max-heap.
}

MaxPriorityQueue::MaxPriorityQueue(const std::vector<int> &data) {
    // TODO: Construct a max-priority queue containing the elements of `data` in O(n) time. The underlying data
    // structure should be a max-heap. Use `heapify_down`.
}

size_t MaxPriorityQueue::parent(size_t index) const {
    // TODO: Return the index of the parent of `index` in the max-heap.
}

size_t MaxPriorityQueue::left(size_t index) const {
    // TODO: Return the index of the left child of `index` in the max-heap.
}

size_t MaxPriorityQueue::right(size_t index) const {
    // TODO: Return the index of the right child of `index` in the max-heap.
}

void MaxPriorityQueue::heapify_down(size_t index) {
    // TODO: Heapify down in the max-heap from `index`. Use `left` and `right`.
}

void MaxPriorityQueue::heapify_up(size_t index) {
    // TODO: Heapify up in the max-heap from `index`. Use `parent`.
}

void MaxPriorityQueue::push(int value) {
    // TODO: Add `value` to the max-priority queue. Use `heapify_up`.
}

void MaxPriorityQueue::pop() {
    // TODO: Remove the maximum value from the max-priority queue. If the max-priority queue is empty, throw
    // `std::out_of_range`. Use `heapify_down`.
}

int MaxPriorityQueue::top() const {
    // TODO: Return the maximum value from the max-priority queue. If the max-priority queue is empty, throw
    // `std::out_of_range`.
}
