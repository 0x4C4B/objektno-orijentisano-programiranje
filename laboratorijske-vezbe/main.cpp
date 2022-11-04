#include "include/minesweeper.h"
#include <iostream>

int main() {
    int x, y;
    Minesweeper static_minesweeper(3, "Static Minefield");
    Minesweeper *dynamic_minesweeper = new Minesweeper("Dynamic Minefield");

    /* Static */
    static_minesweeper.Load();
    static_minesweeper.Print();
    std::cout << "Size: " << static_minesweeper.Size() << std::endl;
    std::cout << "Input target location: ";
    std::cin >> x >> y;
    if (static_minesweeper.Mines(x, y) == -1) {
        static_minesweeper.Print();
    } else {
        std::cout << static_minesweeper.Mines(x, y) << std::endl;
    }

    /* Dynamic */
    dynamic_minesweeper->Load();
    dynamic_minesweeper->Print();
    std::cout << "Size: " << dynamic_minesweeper->Size() << std::endl;
    std::cout << "Input target location: ";
    std::cin >> x >> y;
    if (dynamic_minesweeper->Mines(x, y) == -1) {
        dynamic_minesweeper->Print();
    } else {
        std::cout << dynamic_minesweeper->Mines(x, y) << std::endl;
    }

    /* Clean up */
    delete dynamic_minesweeper;

    return 0;
}
