#pragma once

#include "../include/minesweeper.h"


bool Minesweeper::input(int target) {
    if (target == 0) return false;
    else return true;
}

char Minesweeper::output(bool target) {
    if (target) return 'X';
    else return ' ';
}

Minesweeper::Minesweeper(int size, char* title) {
    this->grid = new bool*[size];
    for (int i = 0; i < size; i++) {
        this->grid[i] = new bool[size];
    }
    this->title = title;
    this->size = size;
}

Minesweeper::Minesweeper(char* title) {
    this->grid = new bool*[10];
    for (int i = 0; i < 10; i++) {
        this->grid[i] = new bool[10];
    }
    this->size = 10;
    this->title = title;
}

/* Destructors */
Minesweeper::~Minesweeper() {
    for (int i = 0; i < size; i++)
        delete [] grid[i];
    delete[] grid;
    delete[] title;
}

/* Methods */
void Minesweeper::Load() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int target;
            std::cin >> target;
            grid[i][j] = input(target);
        }
    }
}

void Minesweeper::Print() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << "| " << output(grid[i][j]) << " ";
        }
        std::cout << "|" << std::endl;
    }
}

int Minesweeper::Mines(int row, int column) {
    int result = 0;

    if (grid[row][column]) return - 1;
    if (row > 0) result += grid[row - 1][column];
    if (row < size - 1) result += grid[row + 1][column];
    if (column > 0) result += grid[row][column - 1];
    if (column < size - 1) result += grid[row][column + 1];
    if ((column > 0) && (row > 0)) result += grid[row - 1][column - 1];
    if ((column > 0) && (row < size - 1)) result += grid[row + 1][column - 1];
    if ((column < size - 1) && (row > 0)) result += grid[row - 1][column + 1];
    if ((column < size - 1) && (row < size - 1)) result += grid[row + 1][column + 1];

    return result;
}

int Minesweeper::Size() const {
    return size;
}