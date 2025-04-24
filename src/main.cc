#include <iostream>
#include <tictactoe/tictatctoe.hh>


int main() {
	TicTacToe game;

	game.clearScreen();
	game.printInstructions();

	game.drawBoard();

	while (game.isRunning()) {
		game.getPlayerInput();

		game.updateGameState();

		game.drawBoard();

		if (!game.isRunning() && game.getWinner() != "") {
			if (game.getWinner() == "Draw") {
				std::cout << "The game is a draw!\n";
			} else {
				std::cout << "Player " << game.getWinner() << " wins!\n";
			}
			game.playAgain();
		}
	}

	game.clearScreen();

	return 0;
}
