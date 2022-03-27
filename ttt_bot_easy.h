#include <stdlib.h>

void easyBot(char grid[9], unsigned short letter) {
    printf("Bot enters the field that should be filled: \n");
    unsigned short field;
    field = rand() % 8;
    while(grid[field] != ' ') {
        field = rand() % 8;
    }
    if(letter == O) grid[field] = 'O';
    if(letter == X) grid[field] = 'X';
}
