#pragma once

#include<memory>

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
            if (size_ == 0) {
                insertAtBeginning(value);
            } else{
                auto newNode = std::make_unique<Node>(value);

                tail_->next_ = std::move(newNode);
                tail_ = tail_->next_.get();
                size_++;
            };
        };
    };
 }