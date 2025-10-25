#pragma once
#include <vector>
#include <string>

// Base abstract class for all games (like Connect4, TicTacToe, etc.)
class Game {
public:
    virtual ~Game() = default;

    // Reset the game to an initial state
    virtual void reset() = 0;

    // Apply a move (column or position depending on the game)
    // Returns true if successful, false if invalid
    virtual bool makeMove(int move) = 0;

    // Check if the game has ended
    virtual bool isGameOver() const = 0;

    // Returns: 1 if player 1 wins, -1 if player 2 wins, 0 if draw, 99 if not finished
    virtual int getWinner() const = 0;

    // Return current game board (for display)
    virtual std::vector<std::vector<char>> getBoard() const = 0;

    // Get the game's name (e.g., "Connect 4")
    virtual std::string getName() const = 0;

    // Return which player's turn it is (1 or -1)
    virtual int getCurrentPlayer() const = 0;
};

