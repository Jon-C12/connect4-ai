#include "Connect4AI.h"
#include <algorithm>

Connect4AI::Connect4AI(int depth) : maxDepth(depth) {}

int Connect4AI::chooseMove(const Game& g) {
    // Cast generic Game to Connect4Game
    auto& game = const_cast<Connect4Game&>(dynamic_cast<const Connect4Game&>(g));
    std::vector<int> validMoves = getValidMoves(game);

    int bestScore = std::numeric_limits<int>::min();
    int bestMove = validMoves[0];

    for (int move : validMoves) {
        Connect4Game temp = game;  // copy
        temp.makeMove(move);
        int score = minimax(temp, maxDepth - 1, false, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
        if (score > bestScore) {
            bestScore = score;
            bestMove = move;
        }
    }
    return bestMove;
}

// Minimax implementation
int Connect4AI::minimax(Connect4Game& game, int depth, bool maximizingPlayer, int alpha, int beta) {
    if (depth == 0 || game.isGameOver())
        return evaluateBoard(game);

    std::vector<int> validMoves = getValidMoves(game);

    if (maximizingPlayer) {
        int maxEval = std::numeric_limits<int>::min();
        for (int move : validMoves) {
            Connect4Game temp = game;
            temp.makeMove(move);
            int eval = minimax(temp, depth - 1, false, alpha, beta);
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha) break;  // alpha-beta pruning
        }
        return maxEval;
    } else {
        int minEval = std::numeric_limits<int>::max();
        for (int move : validMoves) {
            Connect4Game temp = game;
            temp.makeMove(move);
            int eval = minimax(temp, depth - 1, true, alpha, beta);
            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha) break;
        }
        return minEval;
    }
}

// Simple evaluation function
int Connect4AI::evaluateBoard(const Connect4Game& game) const {
    // Example heuristic:
    // +1000 for AI win, -1000 for player win, 0 otherwise
    if (game.isGameOver()) {
        int winner = game.getWinner();
        if (winner == -1) return 1000;  // AI
        if (winner == 1) return -1000;  // Player
        return 0;                       // Draw
    }
    return 0;
}

std::vector<int> Connect4AI::getValidMoves(const Connect4Game& game) const {
    std::vector<int> moves;
    for (int c = 0; c < 7; ++c)
        if (game.getBoard()[0][c] == '.') moves.push_back(c);
    return moves;
}

