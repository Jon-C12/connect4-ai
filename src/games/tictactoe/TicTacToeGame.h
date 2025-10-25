#pragma once
#include "../../core/Game.h"
#include <vector>

class TicTacToeGame : public Game {
public:
    TicTacToeGame();
    std::string getName() const override { return "Tic Tac Toe"; }
    void reset() override;
    bool makeMove(int move) override;
    bool isGameOver() const override;
    int getWinner() const override; // 0 = draw, 1 = X, -1 = O
    int getCurrentPlayer() const override { return currentPlayer; }
    std::vector<std::vector<char>> getBoard() const override;

private:
    std::vector<std::vector<char>> board;
    int currentPlayer; // 1 = X, -1 = O
};

