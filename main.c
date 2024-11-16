#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tictactoe.h"
#include <termio.h>

void enable_bufferless_input() {
    struct termios t;
    tcgetattr(0, &t);
    t.c_lflag &= ~(ICANON);
    tcsetattr(0, TCSANOW, &t);
}

void disable_bufferless_input() {
    struct termios t;
    tcgetattr(0, &t);
    t.c_lflag |= (ICANON);
    tcsetattr(0, TCSANOW, &t);
}

void main(void) {
    enable_bufferless_input();
    int c;
    int turn = 1;
    while(winner() == 0) {
        sleep(1);
        system("clear");
        print_board();
        printf("Player %c's turn: ", turn == 1 ? 'x' : 'o');
        c = getchar();
        fflush(stdin);
        if(play_move(turn, c - '0'))
            turn = turn == 1 ? 2 : 1;
        printf("\n");
    }
    sleep(1);
    system("clear");
    print_board();
    if(winner() == 1)
        printf("Player x wins\n");
    else
        printf("Player o wins\n");
    disable_bufferless_input();
}
