#include <iostream>
#include "board.h"
#include "ai.h"
using namespace std;

int main() {
    cout << "Welcome to Connect 4 AI!" << endl;
    Board board;
    AI ai;

    board.printBoard();
    bool gameOver = false;
    int turn = 1; // 1 = human, 2 = AI

    while (!gameOver) {
        int col;

        if (turn == 1) {
            cout << "Your move (0–6): ";
            cin >> col;
            if (!board.isValidMove(col)) {
                cout << "Invalid move. Try again.\n";
                continue;
            }
        } else {
            cout << "AI is thinking...\n";
            col = ai.chooseMove(board);
            cout << "AI plays column " << col << "\n";
        }

        board.dropPiece(col, turn);
        board.printBoard();

        if (board.checkWin(turn)) {
            if (turn == 1) cout << " You win!\n";
            else cout << " Robot wins!\n";
            gameOver = true;
        }

        turn = (turn == 1 ? 2 : 1);
    }

    return 0;
}

