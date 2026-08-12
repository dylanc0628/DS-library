#pragma once

#include <stdexcept>
#include <cstddef>

/**
 * @brief A dynamically sized array container.
 * 
 * Vector provides contiguous storage for elements and automatically
 * grows its capacity when needed.
 * 
 * @tparam T The vector can hold multiple types of parameters. 
 */

namespace ds {
    
    template <typename T>
    class Vector {
        private:
        T* data_;
        std::size_t capacity_;
        std::size_t size_;

        public:
        /**
         * @brief Constructs an empty vector.
         * 
         * The vector starts with a default size of zero and a default
         * capacity of ten.
         */
        Vector() { 
            size_ = 0;
            capacity_ = 10;
            data_ = new T[capacity_];
        }

        /**
         * @brief Constructs an empty vector with a custom capacity.
         * 
         * @tparam x The requested size of the container.
         */
        Vector(std::size_t x) {
            size_ = 0;
            capacity_ = x;
            data_ = new T[capacity_];
        }

        /**
         * @brief Initializes a new vector with a list of elements.
         * 
         * The size of the vector becomes the size of the initializer list
         * and the capacity is the size plus ten.
         * 
         * @tparam other The list of elements to initialize the vector.
         */
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

        /**
         * @brief Creates a new vector which is initialized using a copy
         * of an existing vector, resulting in two identical vectors.
         * 
         * @tparam other The vector to copy 
         */
        Vector(const Vector& other) {
            //copy constructor
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = new T[capacity_];

            for (std::size_t i = 0; i < size_; i++) {
                data_[i] = other.data_[i];
            }
        }

        /**
         * @brief Allows the = symbol to be overloaded to be used
         * with the copy constructor
         * 
         * @tparam other The vector to copy
         */
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

        /**
         * @brief Creates a new vector which then moves data from a 
         * previously initialized vector to itself and then deletes 
         * said data from the initial vector. 
         * 
         * Results in two vectors, one with the newly moved data 
         * and the other with a nullptr.
         * 
         * Requires the use of std::move.
         * 
         * @tparam other The vector containing the data to be moved.
         */
        Vector(Vector&& other) {
            //move constructor
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;

            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }

        /**
         * @brief Overloads the = operator which allows the move 
         * operation to be performed. 
         * 
         * @tparam other The vector containing the data to be moved. 
         */
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

        /**
         * @brief Destructor for the vector class.
         */
        ~Vector() {
            delete[] data_;
        }

        /** 
         * @brief Adds an element at the end of the container.
         * 
         * If the vector has reached its capacity, resize() is 
         * called which then doubles the capacity before inserting
         * the new element.
         * 
         * @tparam x The element to add.
         */
        void push_back(const T &x) {
            if (size_ == capacity_) {
                resize();
            } 
            data_[size_] = x;
            size_++;
        }

        /**
         * @brief Checks if size is equal to zero
         */
        bool empty() const {
            return size_ == 0;
        }
        
        /**
         * @brief Returns the element at the end of the 
         * container then removes it.
         */
        T pop_back() {
            if (empty()) {
                throw std::out_of_range("Empty vector");
            }
            size_--;
            return data_[size_];
        }

        /**
         * @brief Creates a new array with double the capacity
         * of the original and assigns the elements and pointer 
         * to it. 
         */
        void resize() {
            capacity_ *= 2;
            T *new_data = new T[capacity_];
            for (std::size_t i = 0; i < size_; i++) {
                new_data[i] = data_[i];
            }
            delete[] data_;
            data_ = new_data;
        }

        /**
         * @brief Returns the number of elements in the container.
         */
        std::size_t size() const {
            return size_;
        }

        /**
         * @brief Returns how many elements the container can hold. 
         */
        std::size_t capacity() const {
            return capacity_;
        }

        /**
         * @brief Returns the element at the given index.
         * 
         * If the given index is outside of the container's size
         * it throws an exception
         * 
         * @tparam index The element the function is searching 
         * for.
         */
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

        /**
         * @brief Subscript operator which returns the element
         * at the given index. 
         * 
         * No out of bounds checks are included.
         * 
         * @tparam index The element the function is searching
         * for.
         */
        T& operator[](std::size_t index) {
            return data_[index];
        }

        const T& operator[](std::size_t index) const {
            return data_[index];
        }

        /**
         * @brief A pointer which points to the beginning of the 
         * container.
         */
        T* begin() {
            return data_;
        }

        /**
         * @brief A pointer which points to the end of the 
         * container.
         */
        T* end() {
            return data_ + size_;
        }

        const T* begin() const {
            return data_;
        }

        const T* end() const {
            return data_ + size_;
        }

        /**
         * @brief Moves the data pointer to the beginning of the
         * container, effectively clearing the container of 
         * elements without affecting the capacity.
         */
        void clear() {
            size_ = 0;
        }

        /**
         * @brief Returns the first element of the container.
         * 
         * Contains bounds checking.
         */
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

        /**
         * @brief Returns the last element of the container.
         * 
         * Contains bounds checking.
         */
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