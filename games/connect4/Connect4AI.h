#pragma once
#include "Connect4Game.h"
#include "core/AIPlayer.h"
#include <vector>
#include <limits>

class Connect4AI : public AIPlayer {
public:
    Connect4AI(int depth = 5);  // search depth
    int chooseMove(const Game& game) override;

private:
    int maxDepth;

    int minimax(Connect4Game& game, int depth, bool maximizingPlayer, int alpha, int beta);
    int evaluateBoard(const Connect4Game& game) const;
    std::vector<int> getValidMoves(const Connect4Game& game) const;
};

