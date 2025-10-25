#include "ui/TextUI.h"
#include <iostream>

void TextUI::run(Game& game, std::shared_ptr<AIPlayer> aiPlayer) {
    std::cout << "Welcome to " << game.getName() << "!\n";
    game.reset();

    while (!game.isGameOver()) {
        auto board = game.getBoard();

        // Print board
        for (auto& row : board) {
            for (auto& cell : row)
                std::cout << cell << ' ';
            std::cout << '\n';
        }
        std::cout << "0 1 2 3 4 5 6\n";

        int move = -1;
        if (aiPlayer && game.getCurrentPlayer() == -1) {
            // AI's turn
            move = aiPlayer->chooseMove(game);
            std::cout << "AI chooses column " << move << "\n";
        } else {
            // Human turn
            std::cout << "Player " << (game.getCurrentPlayer() == 1 ? "X" : "O")
                      << ", choose a column: ";
            std::cin >> move;
        }

        if (!game.makeMove(move))
            std::cout << "Invalid move! Try again.\n";
    }

    // Game over
    int winner = game.getWinner();
    if (winner == 0)
        std::cout << "It's a draw!\n";
    else if (winner == 1)
        std::cout << "Player X wins!\n";
    else
        std::cout << "AI wins!\n";
}

