#pragma once
#include <cstddef>

class Stack {
    private:
        int* data;
        size_t capacity;
        size_t n_elem;

    public:
        Stack(size_t cap);
        ~Stack();

        void push(int val);
        void pop();
        int top() const;
        bool empty() const;
        size_t size() const;
};