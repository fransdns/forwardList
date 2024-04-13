#include "list.h"

Node::Node() : data(0), next(nullptr) {}

Node::Node(int value) : data(value), next(nullptr) {}

void Node::killSelf() {
    if (next != nullptr) {
        next->killSelf();
    }
    delete this;
}

List::List() : head(nullptr) {}

List::~List() {
    clear();
}

int List::front() {
    if (head == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return -1; // or throw an exception
    }
    return head->data;
}

int List::back() {
    if (head == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return -1; // or throw an exception
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    return temp->data;
}

void List::push_front(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void List::push_back(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int List::pop_front() {
    if (head == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return -1; // or throw an exception
    }

    int poppedValue = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    return poppedValue;
}

int List::pop_back() {
    if (head == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return -1; // or throw an exception
    }

    Node* temp = head;
    if (temp->next == nullptr) {
        int value = temp->data;
        delete temp;
        head = nullptr;
        return value;
    } else {
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        int value = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        return value;
    }
}

int List::operator[](int index) {
    if (head == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return -1; // or throw an exception
    }

    if (index < 0) {
        std::cout << "Índice no válido: " << index << std::endl;
        return -1; // or throw an exception
    }

    Node* temp = head;
    int count = 0;

    while (temp != nullptr) {
        if (count == index) {
            return temp->data;
        }
        count++;
        temp = temp->next;

        if (count > index) {
            std::cout << "Index out of range: " << index << std::endl;
            return -1; // or throw an exception
        }
    }

    std::cout << "Index out of range: " << index << std::endl;
    return -1; // or throw an exception
}

bool List::empty() {
    return head == nullptr;
}

int List::size() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void List::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

void List::sort() {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    } else if (size() == 1) {
        return;
    }

    Node* current = head;
    Node* index = nullptr;
    int temp;

    while (current != nullptr) {
        index = current->next;

        while (index != nullptr) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

void List::reverse() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}