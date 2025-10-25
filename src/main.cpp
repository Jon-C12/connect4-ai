#include "games/connect4/Connect4Game.h"
#include "games/connect4/Connect4AI.h"
#include "ui/TextUI.h"
#include <memory>

int main() {
    Connect4Game game;
    std::shared_ptr<AIPlayer> ai = std::make_shared<Connect4AI>(5); // depth = 5
    TextUI ui;
    ui.run(game, ai);  // Player vs AI
    return 0;
}



