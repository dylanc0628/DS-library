#pragma once

#include <stdexcept>
#include <cstddef>

/**
 * @brief A dynamically sized array container.
 * 
 * @note Vector provides contiguous storage for elements and automatically
 * grows its capacity when needed.
 * 
 * @param T The vector can hold multiple types of parameters. 
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
         * @note The vector starts with a default size of zero and a default
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
         * @param x The requested size of the container.
         */
        Vector(std::size_t x) {
            size_ = 0;
            capacity_ = x;
            data_ = new T[capacity_];
        }

        /**
         * @brief Initializes a new vector with a list of elements.
         * 
         * @note The size of the vector becomes the size of the initializer list
         * and the capacity is the size plus ten.
         * 
         * @param other The list of elements to initialize the vector.
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
         * @param other The vector to copy 
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
         * @param other The vector to copy
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
         * @note Results in two vectors, one with the newly moved data 
         * and the other with a nullptr.
         * 
         * @note Requires the use of std::move
         * 
         * @code
         * #include <utility>
         * 
         * ds::Vector<int> arr{1,2,3};
         * 
         * ds::Vector<int> v(std::move(arr));
         * @endcode
         * 
         * @param other The vector containing the data to be moved.
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
         * @param other The vector containing the data to be moved. 
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
         * @note If the vector has reached its capacity, resize() is 
         * called which then doubles the capacity before inserting
         * the new element.
         * 
         * @param x The element to add.
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
         * 
         * @return a boolean of whether or not the 
         * container is empty
         */
        bool empty() const {
            return size_ == 0;
        }
        
        /**
         * @brief Returns the element at the end of the 
         * container then removes it.
         * 
         * @throws std::out_of_range exception if the 
         * container is empty
         * 
         * @return the element at the end of the container
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
         * 
         * @return the value of size_
         */
        std::size_t size() const {
            return size_;
        }

        /**
         * @brief Returns how many elements the container can hold. 
         * 
         * @return the value of capacity_
         */
        std::size_t capacity() const {
            return capacity_;
        }

        /**
         * @brief Returns an element 
         * 
         * @throws std::out_of_range if the given index is
         * outside of the container's size 
         * 
         * @param index The element the function is searching 
         * for.
         * 
         * @return The address of the element at the given
         * index
         */
        T& at(std::size_t index) {
            if(size_ <= index) {
                throw std::out_of_range("Out of bounds");
            }
            return data_[index];
        }

        /**
         * @brief Const version of the above .at() method
         */
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
         * @note No out of bounds checks are included.
         * 
         * @param index The element the function is searching
         * for.
         * 
         * @return The address of the element at the given 
         * index
         */
        T& operator[](std::size_t index) {
            return data_[index];
        }

        /**
         * @brief The const version of the above overloaded
         * operator.
         */
        const T& operator[](std::size_t index) const {
            return data_[index];
        }

        /**
         * @brief A pointer which points to the beginning of the 
         * container.
         * 
         * @return A pointer to the first object in the container.
         */
        T* begin() {
            return data_;
        }

        /**
         * @brief A pointer which points to the end of the 
         * container.
         * 
         * @return A pointer to the last object in a container. 
         */
        T* end() {
            return data_ + size_;
        }

        /**
         * @brief A const version of the above begin() method.
         */
        const T* begin() const {
            return data_;
        }

        /**
         * @brief A const version of the above end() method.
         */
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
         * @throws std::out_of_range if container is empty
         * 
         * @return A reference to the first element in the container.
         */
        T& front() {
            if (size_ == 0) {
                throw std::out_of_range("Empty vector");
            }

            return data_[0];
        }

        /**
         * @brief A const version of the above front() method.
         */
        const T& front() const {
            if (size_ == 0) {
                throw std::out_of_range("Empty vector");
            }

            return data_[0];
        }

        /**
         * @brief Returns the last element of the container.
         * 
         * @throws std::out_of_range if container is empty
         * 
         * @return A reference to the last element in a container.
         */
        T& back() {
            if (size_ == 0) {
                throw std::out_of_range("Empty vector");
            }

            return data_[size_ - 1];
        }

        /**
         * @brief A const version of the above back() function.
         */
        const T& back() const {
            if (size_ == 0) {
                throw std::out_of_range("Empty vector");
            }

            return data_[size_ - 1];
        }
    };
};