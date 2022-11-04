#pragma once

#include <iostream>
#include <cmath>
#include <ctime>

class Minesweeper {
private:
    bool** grid;
    int size;
    char* title;

    bool static input(int target);
    char static output(bool target);
public:
    /* Constructors */
    Minesweeper(int size, char* title);
    Minesweeper(char* title);

    /* Destructors */
    ~Minesweeper();

    /* Methods */
    void Load();
    void Print();
    int Mines(int row, int column);
    int Size() const;
};