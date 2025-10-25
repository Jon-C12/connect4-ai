#pragma once
#include "core/Game.h"

class Connect4Game : public Game {
public:
    Connect4Game();

    void reset() override;
    bool makeMove(int col) override;
    bool isGameOver() const override;
    int getWinner() const override;
    std::vector<std::vector<char>> getBoard() const override;
    std::string getName() const override { return "Connect 4"; }
    int getCurrentPlayer() const override { return currentPlayer; }

    bool isValidMove(int col) const;

private:
    std::vector<std::vector<char>> board; // 6x7 grid
    int currentPlayer;  // 1 = Player, -1 = AI
    bool gameOver;
    int winner;

    bool checkWin(int row, int col, char piece) const;
};

	
	
