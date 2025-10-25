#include "games/connect4/Connect4Game.h"
#include "games/connect4/Connect4AI.h"
#include "games/tictactoe/TicTacToeGame.h"
#include "games/tictactoe/TicTacToeAI.h"
#include "ui/TextUI.h"
#include <memory>
#include <iostream>

int main() {
    while (true) {
        std::cout << "\n=== Welcome to Game Hub ===\n";
        std::cout << "1. Connect 4\n";
        std::cout << "2. Tic Tac Toe\n";
        std::cout << "3. Quit\n";
        std::cout << "Choose a game: ";

        int choice;
        std::cin >> choice;

        if (choice == 3) break;

        std::shared_ptr<AIPlayer> ai = nullptr;
        TextUI ui;

        if (choice == 1) { // Connect 4
            Connect4Game game;

            std::cout << "Select mode:\n";
            std::cout << "1. Human vs Human\n";
            std::cout << "2. Human vs AI\n";
            std::cout << "3. AI vs AI\n";
            int mode; std::cin >> mode;

            if (mode == 2) {
                int depth;
                std::cout << "Enter AI depth (1-8 recommended): ";
                std::cin >> depth;
                ai = std::make_shared<Connect4AI>(depth);
            } else if (mode == 3) {
                int depth1, depth2;
                std::cout << "Enter AI 1 depth: "; std::cin >> depth1;
                std::cout << "Enter AI 2 depth: "; std::cin >> depth2;
                // Currently only supports one AI object
                ai = std::make_shared<Connect4AI>(std::max(depth1, depth2));
            }

            ui.run(game, ai);

        } else if (choice == 2) { // Tic Tac Toe
            TicTacToeGame game;

            std::cout << "Select mode:\n";
            std::cout << "1. Human vs Human\n";
            std::cout << "2. Human vs AI\n";
            std::cout << "3. AI vs AI\n";
            int mode; std::cin >> mode;

            if (mode == 2 || mode == 3) {
                int depth;
                std::cout << "Enter AI depth (1-9 recommended): ";
                std::cin >> depth;
                ai = std::make_shared<TicTacToeAI>(depth);
            }

            ui.run(game, ai);

        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}

