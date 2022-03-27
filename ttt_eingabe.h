void inputGrid(char grid[9], unsigned short letter) {
    printf("Please enter the field that should be filled: \n");
    unsigned short field;
    scanf("%hd", &field);
    while(grid[field - 1] != ' ') {
        printf("Cell is already occupied. Choose another one.\n");
        scanf("%hd", &field);
    }
    if(letter == O) grid[field - 1] = 'O';
    if(letter == X) grid[field - 1] = 'X';
}
