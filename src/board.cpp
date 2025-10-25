#include "board.h"
#include <iostream>
using namespace std;

Board::Board() {
    grid = std::vector<std::vector<int>>(6, std::vector<int>(7, 0));
}

void Board::printBoard() const {
    for (auto &row : grid) {
        for (int cell : row)
            cout << (cell == 0 ? ". " : (cell == 1 ? "O " : "X "));
        cout << endl;
    }
    cout << "0 1 2 3 4 5 6" << endl;
}

bool Board::isValidMove(int col) const {
    return col >= 0 && col < 7 && grid[0][col] == 0;
}

bool Board::dropPiece(int col, int player) {
    if (!isValidMove(col)) return false;
    for (int r = 5; r >= 0; --r) {
        if (grid[r][col] == 0) {
            grid[r][col] = player;
            return true;
        }
    }
    return false;
}

bool Board::checkWin(int player) const {
    // Horizontal check
    for (int r = 0; r < 6; ++r)
        for (int c = 0; c < 4; ++c)
            if (grid[r][c] == player && grid[r][c+1] == player &&
                grid[r][c+2] == player && grid[r][c+3] == player)
                return true;

    // Vertical check
    for (int c = 0; c < 7; ++c)
        for (int r = 0; r < 3; ++r)
            if (grid[r][c] == player && grid[r+1][c] == player &&
                grid[r+2][c] == player && grid[r+3][c] == player)
                return true;

    // Diagonal down-right
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 4; ++c)
            if (grid[r][c] == player && grid[r+1][c+1] == player &&
                grid[r+2][c+2] == player && grid[r+3][c+3] == player)
                return true;

    // Diagonal up-right
    for (int r = 3; r < 6; ++r)
        for (int c = 0; c < 4; ++c)
            if (grid[r][c] == player && grid[r-1][c+1] == player &&
                grid[r-2][c+2] == player && grid[r-3][c+3] == player)
                return true;

    return false;
}


