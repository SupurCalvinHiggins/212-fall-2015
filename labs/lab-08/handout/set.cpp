#include "set.h"


Set::Set() {
    // TODO: Initialize an empty binary search tree.
}

Set::~Set() {
    // TODO: Deallocate dynamically allocated memory.
}

Set::Node *Set::insert(Node *root, int value) {
    // TODO: Insert `value` into the binary search tree rooted by `root`. If the binary search tree already contains
    // `value`, do nothing.
}

Set::Node *Set::erase(Node *root, int value) {
    // TODO: Erase `value` from the binary search tree rooted by `root`. If the binary search tree does not contain
    // `value`, do nothing.
}

bool Set::contains(const Node *root, int value) {
    // TODO: Return `true` iff the binary search tree rooted by `root` contains `value`.
}

void Set::insert(int value) {
    // TODO: Insert `value` into the binary search tree. If the binary search tree already contains `value`, do nothing.
    // Use `insert(Node*, int)`.
}

void Set::erase(int value) {
    // TODO: Erase `value` from the binary search tree. If the binary search tree does not contain `value`, do nothing.
    // Use `erase(Node*, int)`.
}

bool Set::contains(int value) const {
    // TODO: Return `true` iff the binary search tree contains `value`. Use `contains(Node*, int)`.
}

size_t Set::size() const {
    // TODO: Return the number of elements in the binary search tree.
}
