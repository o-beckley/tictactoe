#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tictactoe.h"
void clear_buffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF)
        ;
}
int main(void) {
    int c;
    int turn = 1;
    while(!game_over()) {
        system("clear");
        print_board();
        printf("Player %c's turn: ", turn == 1 ? 'x' : 'o');
        c = getchar();
        clear_buffer();
        if(play_move(turn, c - '0'))
            turn = turn == 1 ? 2 : 1;
        printf("\n");
        usleep(500000);
    }
    system("clear");
    print_board();
    if(winner() == 1)
        printf("Player x wins\n");
    else if(winner() == 2)
        printf("Player o wins\n");
    else
        printf("It's a tie!\n");
    exit(0);
    return 0;
}
