#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
public:
    Board();
    void printBoard() const;
    bool isValidMove(int col) const;
    bool dropPiece(int col, int player);
    bool checkWin(int player) const;

private:
    std::vector<std::vector<int>> grid;
};

#endif
	
	
