#pragma once
#include "../../core/AIPlayer.h"
#include "TicTacToeGame.h"
#include <memory>

class TicTacToeAI : public AIPlayer {
public:
    TicTacToeAI(int depth = 6); // depth for minimax
    int chooseMove(const Game& game) override;

private:
    int maxDepth;
    int minimax(TicTacToeGame game, int depth, bool maximizingPlayer);
    int evaluateBoard(const TicTacToeGame& game) const;
};

