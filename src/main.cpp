#include "games/connect4/Connect4Game.h"
#include "games/connect4/Connect4AI.h"
#include "ui/TextUI.h"
#include <memory>
#include <iostream>

int main() {
    while (true) {
        std::cout << "=== Welcome to Game Hub ===\n";
        std::cout << "1. Connect 4\n";
        std::cout << "2. Quit\n";
        std::cout << "Choose a game: ";

        int choice;
        std::cin >> choice;

        if (choice == 2) break;

        std::shared_ptr<AIPlayer> ai = nullptr;
        bool human1 = true, human2 = true;

        if (choice == 1) {
            Connect4Game game;

            std::cout << "Select mode:\n";
            std::cout << "1. Human vs Human\n";
            std::cout << "2. Human vs AI\n";
            std::cout << "3. AI vs AI\n";
            int mode;
            std::cin >> mode;

            if (mode == 2) {
                human2 = false;
                int depth;
                std::cout << "Enter AI depth (1-8 recommended): ";
                std::cin >> depth;
                ai = std::make_shared<Connect4AI>(depth);
            } else if (mode == 3) {
                human1 = human2 = false;
                int depth1, depth2;
                std::cout << "Enter AI 1 depth: ";
                std::cin >> depth1;
                std::cout << "Enter AI 2 depth: ";
                std::cin >> depth2;
                // For simplicity, only one AI implemented; can extend later
                ai = std::make_shared<Connect4AI>(std::max(depth1, depth2));
            }

            TextUI ui;
            ui.run(game, ai);  // Modified UI supports AI
        }
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}

