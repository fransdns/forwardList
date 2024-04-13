#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

class Node {
public:
    int data;
    Node* next;

    Node();
    Node(int value);
    void killSelf();
};

class List {
private:
    Node* head;

public:
    List(); // Constructor
    ~List(); // Destructor

    int front(); // Retorna el elemento al comienzo
    int back(); // Retorna el elemento al final
    void push_front(int value); // Agrega un elemento al comienzo
    void push_back(int value); // Agrega un elemento al final
    int pop_front(); // Remueve el elemento al comienzo
    int pop_back(); // Remueve el elemento al final
    int operator[](int index); // Retorna el elemento en la posición indicada
    bool empty(); // Retorna si la lista está vacía o no
    int size(); // Retorna el tamaño de la lista
    void clear(); // Elimina todos los elementos de la lista
    void sort(); // Implemente un algoritmo de ordenacion con listas enlazadas
    void reverse(); // Revierte la lista
};

#endif // LIST_H
