#pragma once

#include <memory>
#include <stdexcept>

/**
 * @brief A container of noncontiguous values connected by pointers
 */

 namespace ds {

    template<typename T>
    class LinkedList {
        private:
        struct Node {
            T data_;
            std::unique_ptr<Node> next_;

            Node(const T& value) : data_(value), next_(nullptr) {}
        };
        std::unique_ptr<Node> head_ = nullptr;
        Node* tail_ = nullptr;
        std::size_t size_ = 0;

        public:
        ~LinkedList() {
            while(head_) {
                head = std::move(head->next_);
            }
            tail_ = nullptr;
        }

        void insertAtBeginning(const T& value) {
            auto newNode = std::make_unique<Node>(value);

            newNode->next_ = std::move(head_);
            head_ = std::move(newNode);

            if (size_ == 0) {
                tail_ = head_.get();
            }

            size_++;
        };

        void insertAtEnd(const T& value) {
            if (empty()) {
                insertAtBeginning(value);
            } else{
                auto newNode = std::make_unique<Node>(value);

                tail_->next_ = std::move(newNode);
                tail_ = tail_->next_.get();
                size_++;
            };
        };

        void insertAtIndex(const T& value, std::size_t index) {
            if (index > size_) {
                throw std::out_of_range("Invalid index");
            }

            if (index == 0) {
                insertAtBeginning(value);
                return;
            }

            auto indexPtr = head_.get();

            for (std::size_t i{0}; i < index - 2; i++) {
                indexPtr = indexPtr->next_.get();
            }

            auto newNode = std::make_unique<Node>(value);

            newNode->next_ = std::move(indexPtr->next_);
            indexPtr->next_ = std::move(newNode);

            if (index == size_) {
                tail_ = tail_->next_.get();
            }

            size_++;
        }

        std::size_t size() {
            return size_;
        }

        bool empty() {
            if (size_ == 0) {
                return true;
            }
            return false;
        }

        void deleteFromBeginning() {
            if (empty()) {
                throw std::out_of_range("Empty list");
            }

            if (size_ == 1) {
                head_ = nullptr;
                tail_ = nullptr;
                size_--;
                return;
            }

            head_ = std::move(head_->next_);
            size_--;
        }

        void deleteFromEnd() {
            if (empty()) {
                throw std::out_of_range("Empty list");
            }

            if (size_ == 1) {
                head_ = nullptr;
                tail_ = nullptr;
                size_--;
                return;
            }

            auto* indexPtr = head_.get();

            for (std::size_t i{0}; i < size_ - 2; i++) {
                indexPtr = indexPtr->next_.get();
            }

            indexPtr->next_.reset();
            tail_ = indexPtr;

            size_--;
        }

        void deleteFromIndex(std::size_t index) {
            if (empty()) {
                throw std::out_of_range("Empty list");
            }

            if (index >= size_) {
                throw std::out_of_range("Index is out of bounds");
            }

            if (size_ == 1 && index == 0) {
                head_ = nullptr;
                tail_ = nullptr;
                size_--;
                return;
            }

            if (index == 0) {
                head_ = std::move(head_->next_);
                size_--;
                return;
            }

            auto* indexPtr = head_.get();

            for (std::size_t i{0}; i < index - 2; i++) {
                indexPtr = indexPtr->next_.get();
            }

            if (tail_ == indexPtr->next_.get()) {
                tail_ = indexPtr;
            }

            indexPtr->next_ = std::move(indexPtr->next_->next_);
            
            size_--;
        }

        void deleteByValue(const T& value) {
            if (empty()) {
                throw std::out_of_range("Empty list");
            }

            if (size_ == 1 && head_.get() == value) {
                head_ = nullptr;
                tail_ = nullptr;
                size_--;
                return;
            }

            if (head_.get() == value && size_ > 1) {
                head_ = std::move(head_->next_);
            }

            auto* indexPtr = head_.get();

            for (std::size_t i{0}; i < size_ - 1; i++) {
                if (indexPtr->next_.get() == value) {
                    indexPtr->next_ = std::move(indexPtr->next_->next_);
                    size_--;
                    return;
                }
                indexPtr = indexPtr->next_.get();
                if (indexPtr == tail_) {
                    return;
                }
            }
        }

        T& searchByValue(const T& value) {
            if (empty()) {
                throw std::out_of_range("Empty list");
            }

            if (head_.get() == value) {
                return head_.get();
            }

            auto* indexPtr = head_.get();

            for (std::size_t i{0}; i < size_ - 1; i++) {
                if (indexPtr->next_.get() == value) {
                    return indexPtr->next_.get();
                }
                indexPtr = indexPtr->next_.get();
                if (indexPtr == tail_) {
                    return;
                }
            }
        }

        T& searchByIndex(std::size_t index) {
            if (empty()) {
                throw std::out_of_range("Empty list");
            }

            if (index >= size_) {
                throw std::out_of_range("Index is out of bounds");
            }

            if (size_ == 1) {
                return head_.get();
            }

            auto* indexPtr = head_.get();

            for (std::size_t i{0}; i < index - 1; i++) {
                indexPtr = indexPtr->next.get();
            }

            return indexPtr.get();
        }
    };
 }