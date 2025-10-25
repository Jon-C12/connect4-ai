#include "ai.h"
#include <cstdlib>
#include <ctime>

std::vector<int> AI::getValidMoves(const Board& board) const {
    std::vector<int> valid;
    for (int c = 0; c < 7; ++c)
        if (board.isValidMove(c))
            valid.push_back(c);
    return valid;
}

int AI::chooseMove(const Board& board, int /*depth*/) {
    std::vector<int> moves = getValidMoves(board);
    if (moves.empty()) return -1;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int idx = std::rand() % moves.size();
    return moves[idx];
}

// --- stubs for later ---
int AI::minimax(Board, int, bool, int, int) { return 0; }
int AI::scorePosition(const Board&) { return 0; }

