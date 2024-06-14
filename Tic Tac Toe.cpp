#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void displayBoard(const vector<vector<char>> &board);
bool checkWin(const vector<vector<char>> &board, char player);
bool checkDraw(const vector<vector<char>> &board);
void switchPlayer(char &currentPlayer);

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize the game board
    char currentPlayer = 'X'; // Player X starts the game
    bool gameEnd = false;

    cout << "Welcome to Tic-Tac-Toe!\n";

    // Main game loop
    while (!gameEnd) {
        // Display the current state of the board
        displayBoard(board);

        // Prompt the current player to enter their move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the entered position is valid and update the board
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            // Check if the current player wins
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                gameEnd = true;
            } else if (checkDraw(board)) { // Check if the game is a draw
                displayBoard(board);
                cout << "It's a draw!\n";
                gameEnd = true;
            } else {
                switchPlayer(currentPlayer); // Switch to the next player
            }
        } else {
            cout << "Invalid move! Please try again.\n";
        }
    }

    cout << "Thanks for playing!\n";

    return 0;
}

// Function to display the current state of the board
void displayBoard(const vector<vector<char>> &board) {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// Function to check if the current player wins
bool checkWin(const vector<vector<char>> &board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>> &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to switch players
void switchPlayer(char &currentPlayer) {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}
