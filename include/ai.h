#ifndef AI_H
#define AI_H

#include "board.h"
#include <vector>

class AI {
public:
    // returns the best column for the AI to play
    int chooseMove(const Board& board, int depth = 4);

private:
    int minimax(Board board, int depth, bool maximizingPlayer,
                int alpha, int beta);
    int scorePosition(const Board& board);
    std::vector<int> getValidMoves(const Board& board) const;
};

#endif

