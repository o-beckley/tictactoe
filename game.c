#include <stdio.h>
int board[9];

char get_char(const int i, const int n) {
    if(n == 1)
        return 'x';
    if(n == 2)
        return  'o';
    return i + '0';
}

void print_board() {
    for(int i = 0; i < 3; i++) {
        printf(
            "| %c | %c | %c |\n",
            get_char(3 * i, board[3 * i]),
            get_char(3 * i + 1, board[3 * i + 1]),
            get_char(3 * i + 2, board[3 * i + 2])
        );
    }
}

int player_i_has_won(int i) {
    for(int j = 0; j < 3; j++) {
        // check all rows
        if(board[3 * j] == i && board[3 * j + 1] == i && board[3 * j + 2] == i)
            return 1;
        // check all columns
        if(board[j] == i && board[j + 3] == i && board[j + 3 * 2] == i)
            return 1;
    }
    // check leading diagonal
    if(board[0] == i && board[4] == i && board[8] == i)
        return 1;
    // check trailing diagonal
    if(board[2] == i && board[4] == i && board[6] == i)
        return 1;
    return 0;
}

int winner() {
    if(player_i_has_won(1))
        return 1;
    if(player_i_has_won(2))
        return 2;
    return 0;
}

int play_move(int player, int position) {
    if(position < 0 || position > 8) {
        fputc('\n', stderr);
        fputs("This is not a valid position\n", stderr);
        return 0;
    }
    if(board[position] != 0) {
        fputc('\n', stderr);
        fputs("This position is already taken by another player\n", stderr);
        return 0;
    }
    board[position] = player;
    return 1;
}

int game_over() {
    for(int i = 0; i < 9; i++)
        if(board[i] == 0) // found an empty slot
            return 0;
    return 1;
}