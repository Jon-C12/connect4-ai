#pragma once
#include "../core/Game.h"
#include "../core/AIPlayer.h"
#include <memory>

class TextUI {
public:
    // Optional AI: pass nullptr for human-only games
    void run(Game& game, std::shared_ptr<AIPlayer> aiPlayer = nullptr);
};

