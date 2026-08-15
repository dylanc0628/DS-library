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
            std::unique_ptr<Node> next;
        };
        std::unique_ptr<Node> head_;
        Node* tail_ = nullptr;
        std::size_t size_ = 0;

        public:
    }
 }