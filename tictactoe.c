#include "ttt_types.h"
#include "ttt_ausgabe.h"
#include "ttt_eingabe.h"
#include "ttt_evaluate.h"
#include "ttt_bot_easy.h"
#include "ttt_bot_mid.h"
#include "ttt_bot_hard.h"

int main(int argc, char *args[]) {
    unsigned short currentState = NOT_DECIDED, turn;
    char decision, playerLetter, botLetter, enter;
    printf("Do you want to start? [y/n]\n");
    scanf("%c%c", &decision, &enter);
    printf("Which letter do you want to use? [X/O]\n");
    scanf("%c%c", &playerLetter, &enter);
    while(playerLetter != 'X' && playerLetter != 'O') {
        printf("Please enter a valid value!\n");
        scanf("%c%c", &playerLetter, &enter);
    }
    if(playerLetter == 'O') playerLetter = O, botLetter = X; // functions only work with enum-letters
    if(playerLetter == 'X') playerLetter = X, botLetter = O;
    if(decision == 'y') turn = PLAYER;
    if(decision == 'n') turn = BOT;
    while(currentState == NOT_DECIDED) {
        printGrid(grid);
        if(turn == PLAYER) {
            inputGrid(grid, playerLetter);
        } else {
            midBot(grid, botLetter);
        }
        printGrid(grid);
        currentState = evaluate(grid);
        if(turn == PLAYER) {
            turn = BOT;
        } else {
            turn = PLAYER;
        }
        printf("\n\n");
    }
    char currentLetter;
    if(currentState == DRAW) printf("Nobody has won. It's a draw.\n"), printGrid(grid);
    if(turn == PLAYER) {
            turn = BOT;
            if(botLetter == X) currentLetter = 'X';
            if(botLetter == O) currentLetter = 'O';
        } else {
            turn = PLAYER;
            if(playerLetter == X) currentLetter = 'X';
            if(playerLetter == O) currentLetter = 'O';
        }
    if(currentState == WON && turn == BOT) printf("%c has won!\n", currentLetter), printGrid(grid);
    if(currentState == WON && turn == PLAYER) printf("%c has won!\n", currentLetter), printGrid(grid);
}
