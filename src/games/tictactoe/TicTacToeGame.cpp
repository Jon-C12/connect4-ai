#include "TicTacToeGame.h"

TicTacToeGame::TicTacToeGame() {
    reset();
}

void TicTacToeGame::reset() {
    board = std::vector<std::vector<char>>(3, std::vector<char>(3, '.'));
    currentPlayer = 1;
}

bool TicTacToeGame::makeMove(int move) {
    int row = move / 3;
    int col = move % 3;
    if (row < 0 || row > 2 || col < 0 || col > 2) return false;
    if (board[row][col] != '.') return false;

    board[row][col] = currentPlayer == 1 ? 'X' : 'O';
    currentPlayer = -currentPlayer;
    return true;
}

bool TicTacToeGame::isGameOver() const {
    // Check rows, columns, diagonals
    for (int i = 0; i < 3; ++i)
        if (board[i][0] != '.' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
    for (int i = 0; i < 3; ++i)
        if (board[0][i] != '.' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    // Check for empty cells
    for (auto& row : board)
        for (auto& cell : row)
            if (cell == '.') return false;

    return true; // Draw
}

int TicTacToeGame::getWinner() const {
    for (int i = 0; i < 3; ++i)
        if (board[i][0] != '.' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return board[i][0] == 'X' ? 1 : -1;
    for (int i = 0; i < 3; ++i)
        if (board[0][i] != '.' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return board[0][i] == 'X' ? 1 : -1;
    if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0] == 'X' ? 1 : -1;
    if (board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2] == 'X' ? 1 : -1;

    return 0; // draw or ongoing
}

std::vector<std::vector<char>> TicTacToeGame::getBoard() const {
    return board;
}

