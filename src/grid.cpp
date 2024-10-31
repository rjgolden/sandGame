#include "grid.h"

// constructor sets rows and cols and initializes grid with 0s
Grid::Grid(int screenWidth, int screenHeight){
    this->m_rows = screenWidth/2;
    this->m_cols = screenHeight/2;
    for(int i = 0; i < this->m_rows; i++){
        for(int j = 0; j < this->m_cols; j++){
            this->gridArray[i][j] = 0;
        }
    }
}

// draws grid to screen
void Grid::drawGrid(){
    for(int i = 0; i < this->m_rows; i++){
        for(int j = 0; j < this->m_cols; j++){
            //draw rectangles for each value in array, black if 1, white if 0
            DrawRectangle(j * this->cellWidth, i * this->cellHeight, this->cellWidth, this->cellHeight, this->gridArray[i][j] ? BEIGE : WHITE);
        }
    }
}

void Grid::updateGrid() {
    for(int i = this->m_rows-2; i >= 0; i--) {
        for(int j = 0; j < this->m_cols; j++) {

            // check below first
            if(this->gridArray[i][j] == 1 && this->gridArray[i+1][j] == 0) {
                this->gridArray[i+1][j] = 1;
                this->gridArray[i][j] = 0;
            }

            // if can't fall straight down, try diagonal left or right
            else if(this->gridArray[i][j] == 1) {

                bool canFallLeft = (j > 0) && (this->gridArray[i+1][j-1] == 0);
                bool canFallRight = (j < this->m_cols-1) && (this->gridArray[i+1][j+1] == 0);
                    
                // randomly choose left or right if both are possible
                if(canFallLeft && canFallRight) {
                    if(std::rand() % 2 == 0) {
                        this->gridArray[i+1][j-1] = 1;
                        this->gridArray[i][j] = 0;
                    } 
                    else {
                        this->gridArray[i+1][j+1] = 1;
                        this->gridArray[i][j] = 0;
                    }
                }
                // otherwise fall to whichever side is available
                else if(canFallLeft) {
                    this->gridArray[i+1][j-1] = 1; //fall left
                    this->gridArray[i][j] = 0;
                }
                else if(canFallRight) {
                    this->gridArray[i+1][j+1] = 1; //fall right
                    this->gridArray[i][j] = 0;
                }

            }
        }
    }
    this->drawGrid();
    this->handleMouseInput();
}
    
// clears grid by initializing gridArray with 0s
void Grid::clearGrid(){
    for(int i = 0; i < this->m_rows; i++){
        for(int j = 0; j < this->m_cols; j++){
            this->gridArray[i][j] = 0;
        }
    }
}

// handles mouse input
void Grid::handleMouseInput(){
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        
        // fucky discrepency because of how [i][j] of an array works compared to x,y on coordinate plane
        int i = GetMouseY() / this->cellHeight;
        int j = GetMouseX() / this->cellWidth;
        
        if (i >= 0 && i < this->m_rows && j >= 0 && j < this->m_cols) {
            this->gridArray[i][j] = 1;
            DrawRectangle(j * this->cellWidth, i * this->cellHeight, this->cellWidth, this->cellHeight, BEIGE);
        }
    }

    // if right mouse button is pressed clear grid
    if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)){
        this->clearGrid();
    }
}
