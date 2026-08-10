#pragma once

#include <stdexcept>
#include <cstddef>

namespace ds {
    
    template <typename T>
    class Vector {
        private:
        T* data_;
        std::size_t capacity_;
        std::size_t size_;

        public:
        Vector() { 
            //constructor
            size_ = 0;
            capacity_ = 10;
            data_ = new T[capacity_];
        }

        Vector(std::initializer_list<T> other) {
            size_ = other.size();
            capacity_ = size_ + 10;
            data_ = new T[capacity_];

        std::size_t i = 0;
            for (const auto& val : other) {
                data_[i] = val;
                i++;
            }
        }

        Vector(const Vector& other) {
            //copy constructor
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = new T[capacity_];

            for (std::size_t i = 0; i < size_; i++) {
                data_[i] = other.data_[i];
            }
        }

        Vector& operator=(const Vector& other) {
            //copy assignment operator
            if (this == &other) {
                return *this;
            }

            delete[] data_;

            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = new T[capacity_];

            for (std::size_t i = 0; i < size_; i++) {
                data_[i] = other.data_[i];
            }

            return *this;
        }

        Vector(Vector&& other) {
            //move constructor
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;

            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }

        Vector& operator=(Vector&& other) {
            //move assignment operator
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
            for (std::size_t i = 0; i < size_; i++) {
                new_data[i] = data_[i];
            }
            delete[] data_;
            data_ = new_data;
        }

        std::size_t size() const {
            return size_;
        }

        std::size_t capacity() const {
            return capacity_;
        }

        T& at(std::size_t index) {
            if(size_ <= index) {
                throw std::out_of_range("Out of bounds");
            }
            return data_[index];
        }

        const T& at(std::size_t index) const {
            if(size_ <= index) {
                throw std::out_of_range("Out of bounds");
            }
            return data_[index];
        }

        T& operator[](std::size_t index) {
            return data_[index];
        }

        const T& operator[](std::size_t index) const {
            return data_[index];
        }

        T* begin() {
            return data_;
        }

        T* end() {
            return data_ + size_;
        }

        const T* begin() const {
            return data_;
        }

        const T* end() const {
            return data_ + size_;
        }

        void clear() {
            size_ = 0;
        }

        T& front() {
            if (size_ == 0) {
                throw std::out_of_range("Empty vector");
            }

            return data_[0];
        }

        const T& front() const {
            if (size_ == 0) {
                throw std::out_of_range("Empty vector");
            }

            return data_[0];
        }

        T& back() {
            if (size_ == 0) {
                throw std::out_of_range("Empty vector");
            }

            return data_[size_ - 1];
        }

        const T& back() const {
            if (size_ == 0) {
                throw std::out_of_range("Empty vector");
            }

            return data_[size_ - 1];
        }
    };
};