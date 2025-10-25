#include "TicTacToeAI.h"
#include <limits>
#include <vector>
#include <algorithm>

TicTacToeAI::TicTacToeAI(int depth) : maxDepth(depth) {}

int TicTacToeAI::chooseMove(const Game& g) {
    auto& game = const_cast<TicTacToeGame&>(dynamic_cast<const TicTacToeGame&>(g));
    int bestScore = std::numeric_limits<int>::min();
    int bestMove = 0;

    for (int move = 0; move < 9; ++move) {
        TicTacToeGame temp = game;
        if (!temp.makeMove(move)) continue;
        int score = minimax(temp, maxDepth - 1, false);
        if (score > bestScore) {
            bestScore = score;
            bestMove = move;
        }
    }
    return bestMove;
}

int TicTacToeAI::minimax(TicTacToeGame game, int depth, bool maximizingPlayer) {
    if (depth == 0 || game.isGameOver()) return evaluateBoard(game);

    if (maximizingPlayer) {
        int maxEval = std::numeric_limits<int>::min();
        for (int move = 0; move < 9; ++move) {
            TicTacToeGame temp = game;
            if (!temp.makeMove(move)) continue;
            int eval = minimax(temp, depth - 1, false);
            maxEval = std::max(maxEval, eval);
        }
        return maxEval;
    } else {
        int minEval = std::numeric_limits<int>::max();
        for (int move = 0; move < 9; ++move) {
            TicTacToeGame temp = game;
            if (!temp.makeMove(move)) continue;
            int eval = minimax(temp, depth - 1, true);
            minEval = std::min(minEval, eval);
        }
        return minEval;
    }
}

int TicTacToeAI::evaluateBoard(const TicTacToeGame& game) const {
    int winner = game.getWinner();
    if (winner == 1) return 100;
    if (winner == -1) return -100;
    return 0;
}

