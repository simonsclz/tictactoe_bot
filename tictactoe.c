#include "ttt_types.h"
#include "ttt_ausgabe.h"
#include "ttt_eingabe.h"
#include "ttt_evaluate.h"
#include "ttt_bot_easy.h"
#include "ttt_bot_mid.h"
#include "ttt_bot_hard.h"

int main(int argc, char *args[]) {
    unsigned short currentState = NOT_DECIDED;
    char decision;
    printf("Do you want to start? [y/n]\n");
    scanf("%c", &decision);
    unsigned short currentLetter;
    if(decision == 'y') currentLetter = O;
    if(decision == 'n') currentLetter = X;
    while(currentState == NOT_DECIDED) {
        printGrid(grid);
        if(currentLetter == O) {
            inputGrid(grid, currentLetter);
        } else {
            midBot(grid, currentLetter);
        }
        printGrid(grid);
        currentState = evaluate(grid);
        if(currentLetter == X) {
            currentLetter = O;
        } else {
            currentLetter = X;
        }
        printf("\n\n");
    }
    if(currentState == DRAW) printf("Nobody has won. It's a draw.\n"), printGrid(grid);
    if(currentLetter == X) {
            currentLetter = O;
        } else {
            currentLetter = X;
        }
    if(currentState == WON && currentLetter == X) printf("X has won!\n"), printGrid(grid);
    if(currentState == WON && currentLetter == O) printf("O has won!\n"), printGrid(grid);
}
