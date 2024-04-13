#include <iostream>
#include "list.cpp"

int main() {
    List forward;

    std::cout << "Size of the list: " << forward.size() << std::endl; // 0

    forward.push_front(6);
    forward.push_front(2);


    std::cout << "Size of the list: " << forward.size() << std::endl; // 2

    std::cout << "Popped front element: " << forward.pop_front() << std::endl; // 2

    forward.push_back(20);
    forward.push_back(15);

    std::cout << "Popped back element: " << forward.pop_back() << std::endl; // 15

    forward.push_back(30);
    forward.push_back(8);

    std::cout << "Element at index 2: " << forward[2] << std::endl;  // 30

    forward.push_back(10) ;
    forward.push_front(3) ;

    std::cout << "Front element: " << forward.front() << std::endl ; // 3
    std::cout << "Back element: " << forward.back() << std::endl ; // 10

    //std::cout << forward.clear() << std::endl; // Solo limpia la lista
    //std::cout << forward.empty() << std::endl; // 1: vacio, 0: no vacio
    //std::cout << forward.reverse() << std::endl; // Invierte la lista

    return 0;
}