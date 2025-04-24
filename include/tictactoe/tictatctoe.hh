#ifndef TICTACTOE_HH
#define TICTACTOE_HH
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <cctype>
#include <limits>
#include <thread>
#include <chrono>


using WinningCombinations = std::vector<std::array<int, 3>>;


class Board {
  public:
    Board();
    
    void resetBoard();
    void printBoard();
    bool updateBoard(int position, char player);
    char getItem(int position);
    const std::vector<char>& getBoard();

  private:
    std::vector<char> board;
    int round;
};


class TicTacToe {
  public:
    TicTacToe();
    
    void clearScreen();
    void printInstructions();
    bool isRunning();
    void drawBoard();
    void selectFirstPlayer();
    void resetGame();
    void getPlayerInput();
    bool checkWinner();
    const std::string& getWinner(); 
    void updateGameState();
    void playAgain();

  private:
    Board board;
    bool running;
    char currentPlayer;
    std::string winner;
};

#endif