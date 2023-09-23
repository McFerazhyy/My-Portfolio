#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>> &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>> &board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<char>> &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Function for the AI to make a move
void makeAIMove(vector<vector<char>> &board, char aiPlayer, char humanPlayer) {
    // Simple AI: Randomly select an empty spot
    while (true) {
        int row = rand() % 3;
        int col = rand() % 3;
        if (board[row][col] == ' ') {
            board[row][col] = aiPlayer;
            break;
        }
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    char aiPlayer = 'O';
    char humanPlayer = 'X';
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (!gameOver) {
        displayBoard(board);

        if (currentPlayer == humanPlayer) {
            int row, col;
            cout << "Enter your move (row and column, e.g., 1 2): ";
            cin >> row >> col;

            // Check if the input is valid and the cell is empty
            if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
                board[row - 1][col - 1] = humanPlayer;
            } else {
                cout << "Invalid move. Try again." << endl;
                continue;
            }
        } else {
            cout << "AI is making a move..." << endl;
            makeAIMove(board, aiPlayer, humanPlayer);
        }

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << currentPlayer << " wins! Game over." << endl;
            gameOver = true;
        } else if (isBoardFull(board)) {
            displayBoard(board);
            cout << "It's a draw! Game over." << endl;
            gameOver = true;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
