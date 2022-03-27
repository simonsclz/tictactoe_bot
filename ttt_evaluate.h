unsigned short evaluate(char grid[9]) {

    // check columns
    for(int col = 0; col < 3; col++) {
        if(grid[col] == grid[col + 3] && grid[col + 3] == grid[col + 6]) {
            if(grid[col] != ' ') {
                return 2;
            }
        }
    }

    // check rows
    for(int row = 0; row < 7; row = row + 3) {
        if(grid[row] == grid[row + 1] && grid[row + 1] == grid[row + 2]) {
            if(grid[row] != ' ') {
                return 2;
            }
        }
    }

    // check diagonals
    if(grid[0] == grid[4] && grid[4] == grid[8]) {
        if(grid[0] != ' ') {
            return 2;
        }
    }
    if(grid[2] == grid[4]  && grid[4] == grid[6]) {
        if(grid[2] != ' ') {
            return 2;
        }
    }

    for(unsigned short index = 0; index < 9; index++) {
        if(grid[index] == ' ') return 1; // returns NOT_DECIDED when at least one cell is empty
    }

    return 0; // returns DRAW when all cells are filled
}
