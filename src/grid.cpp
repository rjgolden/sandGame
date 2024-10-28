#include "grid.h"

// constructor and initializes grid with 0s
Grid::Grid(int screenWidth, int screenHeight){
    this->m_rows = screenWidth/2; // has to correspond with size (*20)
    this->m_cols = screenHeight/2;
    for(int i = 0; i < this->m_rows; i++){
        for(int j = 0; j < this->m_cols; j++){
            this->gridArray[i][j] = 0;
        }
    }
}

// draws grid to screen
void Grid::drawGrid(){
    int cellWidth = 2; // Each cell is 20 pixels wide
    int cellHeight = 2; // Each cell is 20 pixels tall

    for(int i = 0; i < this->m_rows; i++){
        for(int j = 0; j < this->m_cols; j++){

            // Draw rectangles for each value in array, black if 1, white if 0
            DrawRectangle(j * cellWidth, i * cellHeight, cellWidth, cellHeight, this->gridArray[i][j] ? BLACK : WHITE);

            // Extra format to get text into DrawText function
            //std::string text = TextFormat("%d", this->gridArray[i][j]);
            //DrawText(text.c_str(), (j * cellWidth) + 7, (i * cellHeight) + 7, 20, LIGHTGRAY);
        }
    }
}


// makes 1s 'fall' to bottom of grid
void Grid::nextIteration(){
    for(int i = this->m_rows - 2; i >= 0; i--){
        for(int j = 0; j < this->m_cols; j++){
            if(this->gridArray[i][j] == 1 && this->gridArray[i + 1][j] == 0){
                this->gridArray[i + 1][j] = 1;
                this->gridArray[i][j] = 0;
            }
        }
    }
    // Redraw the grid after updating (speed)
    this->drawGrid();
}


void Grid::handleMouseInput(){
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {

        int mouseX = GetMouseX();
        int mouseY = GetMouseY();
        
        int cellWidth = 2;
        int cellHeight = 2;
        
        int j = mouseX / cellWidth;
        int i = mouseY / cellHeight;
        
        if (i >= 0 && i < this->m_rows && j >= 0 && j < this->m_cols) {
            DrawRectangle(j * cellWidth, i * cellHeight, cellWidth, cellHeight, BLACK);
            //DrawText("1", (j * cellWidth) + 7, (i * cellHeight) + 7, 20, LIGHTGRAY);
            this->gridArray[i][j] = 1;
        }
    }

    if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)){
        this->clearGrid();
    }
}

void Grid::clearGrid(){
    for(int i = 0; i < this->m_rows; i++){
        for(int j = 0; j < this->m_cols; j++){
            this->gridArray[i][j] = 0;
        }
    }
}

// prints current grid to console
/*
#include <iostream
void Grid::printGrid(){
    for(int i = 0; i < this->m_rows; i++){
        for(int j = 0; j < this->m_cols; j++){
            std::cout << this->gridArray[i][j] << " ";
        }
        std::cout << "\n";
    }
}
*/