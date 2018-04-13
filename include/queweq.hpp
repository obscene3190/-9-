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
    queue(queue<T> const & other) {
        for (auto it = other.gethead(); it; it = it->next) {
            push(it->value);
        }
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
    void pop() {
        node_t * ptr = head->next;
        if (head != nullptr) {
            delete head;
            head = ptr;
        }
        else throw std::out_of_range("Out of range");
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

    node_t * gethead() const
    {
        return  head;
    }
    node_t * gettrail() const
    {
        return  trail;
    }
    ~queue()
    {
        while (head) {
            node_t * temp = head;
            head = head->next;
            delete temp;
        }
    }

};
