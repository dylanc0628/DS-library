#pragma once
#include<cassert>
#include "vector.h"

void constructor_test() {}

template <typename T>
void push_back_test(T val) {
    Vector<T> arr{};
    arr.push_back(val);
    int x = arr[0];
    assert(x == val);
}

template <typename T>
void empty_test() {
    Vector<T> arr;
    assert(arr.size() == 0);
}

template <typename T>
void pop_back_test(T val) {
    Vector<T> arr{val};
    int* x = std::end(arr) - 1;
    int y = arr.pop_back();
    assert(*x == y);
}

void resize_test() {
    Vector<int> arr;
    int x = arr.capacity();
    for (int i = 0; i < 11; i++) {
        arr.push_back(i);
    }
    int y = arr.capacity();
    assert(y == (x * 2));
}

void size_test() {
    Vector<int> arr;
    assert(arr.size() == 0);
}

void capacity_test() {
    Vector<int> arr;
    assert(arr.capacity() == 10);
}

void at_test() {}

void begin_func_test() {}

void end_func_test() {}