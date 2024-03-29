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
        Node* at(size_t index) {
            Node* cursor = m_root;
            while(cursor != nullptr && index--)
                cursor = cursor->next;
            
            return cursor;
        }
        const Node* at(size_t index) const {
            Node* cursor = m_root;
            while(cursor != nullptr && index--)
                cursor = cursor->next;
            
            return cursor;
        }
        void pushFront(const dataType& data) {
            m_root = new Node {data, m_root};
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
        void popFront() {
            Node* temp = m_root->next;
            delete m_root;
            m_root = temp;
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