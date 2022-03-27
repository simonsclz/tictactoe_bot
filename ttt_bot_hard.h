void hardBot(char grid[9], int letter) {
    char l;
    if(letter == X) l = 'X';
    if(letter == O) l = 'O';
    printf("HARD BOT WINS ALL THE TIME!\n");
    grid[0] = grid[1] = grid[2] = l;
}
