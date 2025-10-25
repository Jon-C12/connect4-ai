#include "Connect4Game.h"
#include <iostream>

constexpr int ROWS = 6;
constexpr int COLS = 7;

Connect4Game::Connect4Game() {
    reset();
}

void Connect4Game::reset() {
    board = std::vector<std::vector<char>>(ROWS, std::vector<char>(COLS, '.'));
    currentPlayer = 1;
    gameOver = false;
    winner = 99; // 99 = ongoing
}

bool Connect4Game::isValidMove(int col) const {
    return col >= 0 && col < COLS && board[0][col] == '.';
}

bool Connect4Game::makeMove(int col) {
    if (!isValidMove(col) || gameOver) return false;

    // Drop piece to lowest available row
    for (int row = ROWS - 1; row >= 0; --row) {
        if (board[row][col] == '.') {
            board[row][col] = (currentPlayer == 1 ? 'X' : 'O');
            if (checkWin(row, col, board[row][col])) {
                gameOver = true;
                winner = currentPlayer;
            } else {
                // Check draw
                bool full = true;
                for (int c = 0; c < COLS; ++c)
                    if (board[0][c] == '.') full = false;
                if (full) {
                    gameOver = true;
                    winner = 0;
                }
            }
            currentPlayer *= -1; // Switch turns
            return true;
        }
    }
    return false;
}

bool Connect4Game::isGameOver() const { return gameOver; }
int Connect4Game::getWinner() const { return winner; }

std::vector<std::vector<char>> Connect4Game::getBoard() const { return board; }

bool Connect4Game::checkWin(int row, int col, char piece) const {
    const int directions[4][2] = {{0,1},{1,0},{1,1},{1,-1}};
    for (auto& [dr, dc] : directions) {
        int count = 1;
        for (int i = 1; i < 4; ++i) {
            int r = row + i*dr, c = col + i*dc;
            if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] != piece) break;
            count++;
        }
        for (int i = 1; i < 4; ++i) {
            int r = row - i*dr, c = col - i*dc;
            if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] != piece) break;
            count++;
        }
        if (count >= 4) return true;
    }
    return false;
}

