short fork(char grid[9], char letter);
short possibleForkField(char grid[9], char letter);
short freeCornerField(char grid[9], char letter);
short int createFinish(char grid[9], char letter);
short int finish(char grid[9], char letter);
short returnMissingCol(char grid[9], unsigned short col, char letter);
short lettersInCols(char grid[9], unsigned short col, char letter);
short returnMissingRow(char grid[9], unsigned short row, char letter);
short lettersInRows(char grid[9], unsigned short row, char letter);
unsigned short returnMissingDiag(char grid[9], unsigned short diag, char letter);
short lettersInDiag(char grid[9], unsigned short diag, char letter);

void midBot(char grid[9], char letter) {
    printf("Bot enters the field that should be filled: \n");
    char botLetter, oppLetter;
    if(letter == X) botLetter = 'X', oppLetter = 'O';
    if(letter == O) botLetter = 'O', oppLetter = 'X';
    short botFinish = finish(grid, botLetter);
    unsigned short field = 4;
    if(botFinish != -1) {
        field = botFinish;
    } else {
        short oppFinish = finish(grid, oppLetter);
        if(oppFinish != -1) {
            field = oppFinish;
        } else {
            short botFork = fork(grid, botLetter);
            if(botFork >= 0) {
                field = botFork;
            } else {
                short int finishField = createFinish(grid, botLetter);
                if(finishField >= 0) { // creating a finish as higher priority (because opponent must defend)
                    field = finishField;
                } else {
                    short oppFork = fork(grid, oppLetter); // less important because fork must be blocked if
                    if(oppFork >= 0) {                     // no own finish is creatable
                        field = oppFork;
                    } else {
                        if(grid[4] == ' ') {
                            field = 4;
                        } else {
                            short cornerField = freeCornerField(grid, botLetter);
                            if(cornerField >= 0) {
                                field = cornerField;
                            } else {
                                field = 4;
                                while(grid[field] != ' ') {
                                    field = rand() % 8;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(letter == O) grid[field] = 'O';
    if(letter == X) grid[field] = 'X';
}

short freeCornerField(char grid[9], char letter) {
    if(grid[0] == ' ') return 0;
    if(grid[2] == ' ') return 2;
    if(grid[6] == ' ') return 6;
    if(grid[8] == ' ') return 8;
    return -1;
}

short fork(char grid[9], char letter) {
    short field = possibleForkField(grid, letter);
    if(field >= 0) {
        return field;
    }
    return -1;
}

short possibleForkField(char grid[9], char letter) {
    unsigned short counter = 0;
    for(unsigned short index = 0; index < 9; index = index + 2) {
        if(grid[index] == letter) counter++;
        if(index == 2) index = index + 2;
    }
    if(counter == 2) {
        if(grid[0] == letter && grid[8] == letter) {
            if(grid[1] == ' ' && grid[5] == ' ') {
                return 2;
            } else if(grid[3] == ' ' && grid[7] == ' ') {
                return 6;
            }
        } else if(grid[2] == letter && grid[6] == letter) {
            if(grid[7] == ' ' && grid[5] == ' ') {
                return 8;
            } else if(grid[1] == ' ' && grid[3] == ' ') {
                return 0;
            }
        } else if(grid[0] == letter && grid[2] == letter) {
            if(grid[1] == ' ' && grid[5] == ' ') {
                return 8;
            } else if(grid[1] == ' ' && grid[3] == ' ') {
                return 6;
            }
        } else if(grid[2] == letter && grid[8] == letter) {
            if(grid[7] == ' ' && grid[5] == ' ') {
                return 6;
            } else if(grid[1] == ' ' && grid[5] == ' ') {
                return 0;
            }
        } else if(grid[8] == letter && grid[6] == letter) {
            if(grid[3] == ' ' && grid[7] == ' ') {
                return 0;
            } else if(grid[5] == ' ' && grid[7] == ' ') {
                return 2;
            }
        } else if(grid[6] == letter && grid[0] == ' ') {
            if(grid[1] == ' ' && grid[3] == ' ') {
                return 2;
            } else if(grid[3] == ' ' && grid[7] == ' ') {
                return 8;
            }
        }
    }
    if(grid[4] == letter) {
        if(grid[0] == letter) {
            if(grid[2] == ' ' && grid[3] == ' ' && grid[6] == ' ') {
                return 2;
            }
        }
        if(grid[2] == letter) {
            if(grid[0] == ' ' && grid[1] == ' ' && grid[8] == ' ') {
                return 0;
            }
        }
        if(grid[6] == letter) {
            if(grid[0] == ' ' && grid[2] == ' ' && grid[3] == ' ') {
                return 0;
            }
        }
        if(grid[8] == letter) {
            if(grid[0] == ' ' && grid[2] == ' ' && grid[5] == ' ') {
                return 2;
            }
        }
    }
    return -1;
}

short int createFinish(char grid[9], char letter) {
    for(unsigned short col = 0; col < 3; col++) {
        if(lettersInCols(grid, col, letter) >= 1) {
            short coordinate = returnMissingCol(grid, col, letter);
            if(coordinate >= 0) return coordinate;
        }
    }
    for(unsigned short row = 0; row < 9; row = row + 3) {
        if(lettersInRows(grid, row, letter) >= 1) {
            short coordinate = returnMissingRow(grid, row, letter);
            if(coordinate >= 0) return coordinate;
        }
    }
    for(unsigned short diag = 0; diag < 2; diag++) {
        if(lettersInDiag(grid, diag, letter) >= 1) {
            short coordinate = returnMissingDiag(grid, diag, letter);
            if(coordinate >= 0) return coordinate;
        }
    }
    return -1;
}

// checks, if there's a way to end the game
short int finish(char grid[9], char letter) {
    for(unsigned short col = 0; col < 3; col++) {
        if(lettersInCols(grid, col, letter) >= 2) {
            short coordinate = returnMissingCol(grid, col, letter);
            if(coordinate >= 0) return coordinate;
        }
    }
    for(unsigned short row = 0; row < 9; row = row + 3) {
        if(lettersInRows(grid, row, letter) >= 2) {
            short coordinate = returnMissingRow(grid, row, letter);
            if(coordinate >= 0) return coordinate;
        }
    }
    for(unsigned short diag = 0; diag < 2; diag++) {
        if(lettersInDiag(grid, diag, letter) >= 2) {
            short coordinate = returnMissingDiag(grid, diag, letter);
            if(coordinate >= 0) return coordinate;
        }
    }
    return -1; // code that field should be changed to 4 (bot) and to block the opponents' move
}   

short returnMissingCol(char grid[9], unsigned short col, char letter) {
    for(unsigned short row = 0; row < 9; row = row + 3) {
        if(grid[col + row] == ' ') return row + col;
    }
    return -1;
}

short returnMissingRow(char grid[9], unsigned short row, char letter) {
    for(unsigned short col = 0; col < 3; col++) {
        if(grid[col + row] == ' ') return row + col;
    }
    return -1;
}

short lettersInCols(char grid[9], unsigned short col, char letter) {
    char oppLetter;
    if(letter == 'X') oppLetter = 'O';
    if(letter == 'O') oppLetter = 'X';
    unsigned short counter = 0;
    for(unsigned short row = 0; row < 9; row = row + 3) {
        if(grid[col + row] == oppLetter) return -1;
        if(grid[col + row] == letter) counter++;
    }
    return counter;
}

short lettersInRows(char grid[9], unsigned short row, char letter) {
    char oppLetter;
    if(letter == 'X') oppLetter = 'O';
    if(letter == 'O') oppLetter = 'X';
    unsigned short counter = 0;
    for(unsigned short col = 0; col < 3; col++) {
        if(grid[col + row] == oppLetter) return -1;
        if(grid[col + row] == letter) counter++;
    }
    return counter;
}

unsigned short returnMissingDiag(char grid[9], unsigned short diag, char letter) {
    if(diag == 0) {
        for(unsigned short index = 0; index < 9; index = index + 4) {
            if(grid[index] == ' ') return index;
        }
    } else {
        for(unsigned short index = 2; index < 7; index = index + 2) {
            if(grid[index] == ' ') return index;
        }
    }
    return 4;
}

short lettersInDiag(char grid[9], unsigned short diag, char letter) {
    char oppLetter;
    if(letter == 'X') oppLetter = 'O';
    if(letter == 'O') oppLetter = 'X';
    unsigned short counter = 0;
    if(diag == 0) {
        for(unsigned short index = 0; index < 9; index = index + 4) {
            if(grid[index] == oppLetter) return -1;
            if(grid[index] == letter) counter++;
        }
    } else {
        for(unsigned short index = 2; index < 7; index = index + 2) {
            if(grid[index] == oppLetter) return -1;
            if(grid[index] == letter) counter++;
        }
    }
    return counter;
}
