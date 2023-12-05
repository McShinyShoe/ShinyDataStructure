#pragma once
#include <cstddef>

namespace shiny {
    template <typename dataType>
    class SinglyLinkedList {
    public:
        struct Node {
            dataType data;
            Node* next = nullptr;
        };

    private:
        Node* m_root = nullptr;

    public:
        Node* root() {
            return m_root;
        }
        size_t size() {
            size_t counter = 0;
            Node* cursor = m_root;
            while(cursor != nullptr) {
                cursor = cursor->next;
                counter++;
            }
            return counter;
        }
        void pushBack(const dataType& data) {
            if(m_root == nullptr) {
                m_root = new Node {data, nullptr};
                return;
            }
            Node* cursor = m_root;
            while(cursor->next != nullptr)
                cursor = cursor->next;

            cursor->next = new Node {data, nullptr};
        }
        void popBack() {
            if(m_root->next == nullptr) {
                delete m_root;
                m_root = nullptr;
                return;
            }
            Node* cursor = m_root;
            while(cursor->next->next != nullptr)
                cursor = cursor->next;

            delete cursor->next;
            cursor->next = nullptr;
        };
    };
}