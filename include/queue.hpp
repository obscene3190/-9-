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
        head = nullptr; 
        trail = nullptr;
        for (node_t * ptr = other.gethead(); ptr; ptr = ptr->next) {
            push(ptr->value);
        }
    }
    void operator =(queue<T> const & other) {
        if(head != nullptr) {
            while (head) {
                node_t * temp = head;
                head = head->next;
                delete temp;
            }
        }
        for (node_t * ptr = other.gethead(); ptr; ptr = ptr->next) {
            push(ptr->value);
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
        if (head != nullptr) {
            node_t * ptr = head->next;
            delete head;
            head = ptr;
        }
        else throw std::out_of_range("Out of range");
    }



    void print(std::ostream & stream) {
        if(head != nullptr) {
            node_t *ptr = head;
            if (ptr != nullptr) {
                while (ptr->next != nullptr) {
                    stream << ptr->value << "  ";
                    ptr = ptr->next;
                }
                if (trail != nullptr) {
                    stream << trail->value << "  ";
                }
            }
        }
        else stream << "nothing";
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
