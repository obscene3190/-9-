#include <iostream>
#include <sstream>
#include <string>

template <typename T>
class queue {
private:
    struct node_t {
        node_t * next;
        T value;
    };
    node_t * head;
    node_t * trail;
public:
    queue() {
        head = nullptr; //начало
        trail = nullptr; //конец
    }
    void push(T value) {
        node_t * node = new node_t;
        node->value = value;
        node->next = nullptr;
        if( head == nullptr) {
            head = node;
            trail = node;
        }
        node_t * ptr = trail;
        ptr->next = node;
        trail = trail->next;

    }
    void pop() {
        node_t * ptr = head->next;

        if (head != nullptr) {
            delete head;
            head = ptr;
        }
    }
    void print() {
            node_t * ptr = head;
            if(ptr != nullptr) {
            while(ptr->next != nullptr) {
                std::cout << ptr->value << "  ";
                ptr = ptr->next;
            }
            if(trail != nullptr) {
                std::cout << trail->value << "  ";
            }
        }
    }

};
