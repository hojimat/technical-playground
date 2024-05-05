#include <iostream>

#define uint unsigned int

template<typename T>
class Node {
public:
    T value;
    Node* next;
public:
    Node(T x) : value(x), next(nullptr) {}
};

template<typename T>
class List {
public:
    Node<T>* head;

public:
    List() : head(nullptr) {};

    void append(T x) {
        Node<T>* newNode = new Node<T>(x);
        if (!head) {
            head = newNode;
            return;
        }

        Node<T>* current = head;
        while(current->next) {
            current = current->next;
        }

        current->next = newNode;
    }

    void print() {
        Node<T>* current = head;

        while(current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        
        std::cout << std::endl;

    }

    ~List() {
        Node<T>* current = head;
        while (current) {
            Node<T>* tmp = current;
            current = current->next;
            delete tmp;
        }
    }

};

int main() {
    uint a = 123456, b = 234567, c = 345678;

    List<uint>* myList = new List<uint>();

    myList->append(a);
    myList->append(b);
    myList->append(c);

    //std::cout << myList << std::endl;
    myList->print();

    delete myList;

    return 0;
}