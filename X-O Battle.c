#include <stdio.h>

char board[3][3]; // 3x3 Tic-Tac-Toe board

void initializeBoard() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkWin() {
    int i;
    for (i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '))
            return 1;
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
        return 1;

    return 0;
}

int isDraw() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

void playGame() {
    int row, col, turn = 1;
    char mark;
    
    initializeBoard();
    
    while (1) {
        displayBoard();
        mark = (turn % 2 == 1) ? 'X' : 'O';
        
        // Input validation loop
        while (1) {
            printf("Player %d (%c), enter row and column (0-2): ", (turn % 2 == 1) ? 1 : 2, mark);
            if (scanf("%d %d", &row, &col) == 2 && row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                break; // Valid input
            } else {
                printf("Invalid move! Try again.\n");
                while (getchar() != '\n'); // Clear input buffer
            }
        }
        
        board[row][col] = mark;
        
        if (checkWin()) {
            displayBoard();
            printf("Player %d wins!\n", (turn % 2 == 1) ? 1 : 2);
            break;
        }
        
        if (isDraw()) {
            displayBoard();
            printf("It's a draw!\n");
            break;
        }
        
        turn++;
    }
}

int main() {
    printf("Welcome to X-O Battle Arena!\n");
    playGame();
    return 0;
}

