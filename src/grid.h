#pragma once
#include <raylib.h>
#include <string>
#define WIDTH 800
#define HEIGHT 800


class Grid {

    private:
        int m_rows;
        int m_cols;
        int gridArray[WIDTH/2][HEIGHT/2];

    public:
        Grid(int screenWidth, int screenHeight);
        void printGrid();
        void drawGrid();
        void nextIteration();
        void handleMouseInput();
        void clearGrid();

};