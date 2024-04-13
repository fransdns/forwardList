#include <iostream>
#include "list.cpp"

int main() {
    List forward;

    std::cout << "Size of the list: " << forward.size() << std::endl; // 0

    forward.push_front(0);
    forward.push_front(0);


    std::cout << "Size of the list: " << forward.size() << std::endl; // 2

    std::cout << "Popped front element: " << forward.pop_front() << std::endl; // 0

    forward.push_back(0);
    forward.push_back(0);

    std::cout << "Popped back element: " << forward.pop_back() << std::endl; // 0

    forward.push_back(0);
    forward.push_back(0);

    std::cout << "Element at index 2: " << forward[2] << std::endl;  // 0

    forward.push_back(0) ;
    forward.push_front(0) ;

    std::cout << "Front element: " << forward.front() << std::endl ; // 0
    std::cout << "Back element: " << forward.back() << std::endl ; // 0

    forward.clear(); // No imprime nada, solo limpia la lista

    forward.reverse(); // No imprime nada, solo invierte la lista

    std::cout << "Is the list empty? " << forward.empty() << std::endl; // 1: vacio, 0: no vacio

    return 0;
}