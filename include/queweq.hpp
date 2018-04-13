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
        else {
            trail->next = node;
            trail = node;
        }
    }
    void print() {
            if(head != nullptr) {
            while(head->next != nullptr) {
                std::cout << head->value << "  ";
                head = head->next;
            }
            std::cout << trail->value << "  ";
        }
    }

};
