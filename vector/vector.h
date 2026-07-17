#pragma once

#include <stdexcept>
#include <cstddef>

template <typename T>
class Vector {
    private:
    T* data_;
    size_t capacity_;
    size_t size_;

    public:
    Vector() {
        size_ = 0;
        capacity_ = 10;
        data_ = new T[capacity_];
    }

    Vector(const Vector& other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new T[capacity_];

        for (size_t i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }

    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }

        delete[] data_;

        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new T[capacity_];

        for(size_t = i; i < size_; i++) {
            data_[i] = other.data_[i]
        }

        return *this;
    }

    Vector(Vector&& other) {
        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;

        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    Vector& operator=(Vector&& other) {
        if (this == &other) {
            return *this;
        }

        delete[] data_;

        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;

        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;

        return *this;
    }

    ~Vector() {
        delete[] data_;
    }

    void push_back(const T &x) {
        if (size_ == capacity_) {
            resize();
        } 
        data_[size_] = x;
        size_++;
    }

    bool empty() const {
        return size_ == 0;
    }
    
    T pop_back() {
        if (empty()) {
            throw std::out_of_range("Empty vector");
        }
        size_--;
        return data_[size_];
    }

    void resize() {
        capacity_ *= 2;
        T *new_data = new T[capacity_];
        for (size_t i = 0; i < size_; i++) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
    }

    size_t size() {
        return size_;
    }

    size_t capacity() {
        return capacity_;
    }

    T& at(size_t index) {
        if(size_ <= index) {
            throw std::out_of_range("Out of bounds");
        }
        return data_[index];
    }

    T& operator[](size_t index) {
        return data_[index];
    }

    T* begin() {
        return data_;
    }

    T* end() {
        return data_ + size_
    }

    const T* begin() {
        return data_;
    }

    const T* end() {
        return data_ + size_
    }
};