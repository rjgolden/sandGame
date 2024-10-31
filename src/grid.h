#pragma once
#include <raylib.h>
#include <cstdlib>
#define WIDTH 800
#define HEIGHT 800

// default material is sand
class Grid {

    private:
        int m_rows;
        int m_cols;
        int cellWidth = 2; // each cell is 2 pixels wide
        int cellHeight = 2; // each cell is 2 pixels tall
        int gridArray[WIDTH/2][HEIGHT/2];

    public:
        Grid(int screenWidth, int screenHeight);
        void printGrid();
        void drawGrid();
        void updateGrid();
        void handleMouseInput();
        void clearGrid();
        void sandSpread();

};