#include <stdio.h>

void printGrid(char grid[9]) {
    for(int index = 0; index < 9; index++) {
        if((index % 3) != 2) printf("%c|", grid[index]);
        if((index % 3) == 2) printf("%c\n", grid[index]);
        if((index % 3) == 2 && index != 8) printf("-+-+-\n");
    }
}
