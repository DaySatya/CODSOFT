#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

void displayBoard() {
    cout << "\n";
    cout << "Current Board:\n";
    cout << "-------------\n"; // Top border
    for (int i = 0; i < 3; i++) {
        cout << "| "; // Left border
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | "; // Cell content
        }
        cout << "\n";
        cout << "-------------\n"; // Bottom border
    }
    cout << "\n";
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true; // Check rows
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true; // Check columns
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true; // Check diagonal
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true; // Check other diagonal
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false; // Check for empty cells
        }
    }
    return true; // No empty cells, it's a draw
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void resetBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
    currentPlayer = 'X';
}

void playGame() {
    int move;
    bool gameOver = false;
    resetBoard();

    while (!gameOver) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        int row = (move - 1) / 3, col = (move - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already occupied! Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;
        
        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } else if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            gameOver = true;
        } else {
            switchPlayer();
        }
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}