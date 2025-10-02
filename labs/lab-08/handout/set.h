#pragma once
#include <cstddef>

class Set {
    struct Node {
        // TODO: Define binary search tree node member variables.
    };

    // TODO: Define binary search tree member variables.

    [[nodiscard]] static Node *insert(Node *root, int value);

    [[nodiscard]] static Node *erase(Node *root, int value);

    [[nodiscard]] static bool contains(const Node *root, int value);

public:
    Set();

    ~Set();

    Set(const Set &other) = delete;

    Set &operator=(const Set &other) = delete;

    void insert(int value);

    void erase(int value);

    [[nodiscard]] bool contains(int value) const;

    [[nodiscard]] size_t size() const;
};
