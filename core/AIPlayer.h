#pragma once
#include "Game.h"

// Generic AI interface (used by all AI implementations)
class AIPlayer {
public:
    virtual ~AIPlayer() = default;

    // Decide a move given the current game state
    virtual int chooseMove(const Game& game) = 0;
};

