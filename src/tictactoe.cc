#include <tictactoe/tictatctoe.hh>


Board::Board() {
  resetBoard();
}


void Board::resetBoard() {
  board = std::vector<char>(9, ' ');
  round = 1;
}


void Board::printBoard() {
  std::cout << '\n';
  std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << '\n';
  std::cout << "-----------\n";
  std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << '\n';
  std::cout << "-----------\n";
  std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << '\n';
  std::cout << '\n';
}


bool Board::updateBoard(int position, char player) {
  if (board[position - 1] == ' ') {
    board[position - 1] = player;
    round++;
    return true;
  }
  return false;
}


char Board::getItem(int position) {
  return board[position];
}


const std::vector<char>& Board::getBoard() {
  return board;
}


TicTacToe::TicTacToe() {
  running = true;
  currentPlayer = ' ';
  winner = "";
  selectFirstPlayer();
}


void TicTacToe::clearScreen() {
  std::cout << "\033[2J\033[1;1H";
}


void TicTacToe::printInstructions() {
  std::cout << "Welcome to Tic-Tac-Toe!\n";
  std::cout << "\n-------------------------------------\n\n";
  std::cout << "Instructions:\n";
  std::cout << "  1. The game is played on a 3x3 grid.\n";
  std::cout << "  2. Players take turns placing their mark (X or O) in an empty cell.\n";
  std::cout << "  3. The first player to get 3 marks in a row wins.\n";
  std::cout << "  4. If all cells are filled, the game is a draw.\n";
  std::cout << "  5. Enter 'quit' or 'q' at any time to quit the game.\n";
  std::cout << "\n-------------------------------------\n\n";
  std::cout << "The board positions are numbered as follows:\n\n";
  std::cout << " 1 | 2 | 3 \n";
  std::cout << "-----------\n";
  std::cout << " 4 | 5 | 6 \n";
  std::cout << "-----------\n";
  std::cout << " 7 | 8 | 9 \n\n";
  std::cout << "Press Enter to start the game...";

  std::cin.get();
  
  return;  
}


bool TicTacToe::isRunning() {
  return running;
}


void TicTacToe::drawBoard() {
  clearScreen();

  std::cout << "Tic-Tac-Toe\n";
  board.printBoard();
  std::cout << "\n";
}


void TicTacToe::selectFirstPlayer() {
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> dist(0, 1);

  int randomChoice = dist(generator);

  if (randomChoice == 0) {
    currentPlayer = 'X';
  } else {
    currentPlayer = 'O';
  }
}


void TicTacToe::resetGame() {
  board.resetBoard();
  winner = "";
  selectFirstPlayer();
}


void TicTacToe::getPlayerInput() {
  std::string move;
  int intMove;

  while (true) {
    std::cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    std::cin >> move;

    std::transform(move.begin(), move.end(), move.begin(), ::tolower);
    
    if (std::all_of(move.begin(), move.end(), ::isdigit)) {
      intMove = std::stoi(move);
      
      if (1 <= intMove && intMove <= 9 && board.getItem(intMove - 1) == ' ') {
        board.updateBoard(intMove, currentPlayer);
        return;
      }
    } else if (move == "q" || move == "quit") {
      std::cout << "Thanks for playing!\n";
      std::cout << "Exiting the game";
      for (auto _ : {1, 2, 3}) {
        std::cout << "." << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
      }
      running = false;
      return;
    }
    
    std::cout << "Invalid input.";
  }
}


bool TicTacToe::checkWinner() {
  const WinningCombinations winningCombinations = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6},
  };

  for (auto combo : winningCombinations) {
    if (std::all_of(
      combo.begin(), combo.end(), [&](int index){ return board.getItem(index) == currentPlayer; }
    )) {
      return true;
    }
  }

  return false;
}


const std::string& TicTacToe::getWinner() {
  return winner;
}


void TicTacToe::updateGameState() {
  const std::vector<char>& b {board.getBoard()};
  if (checkWinner()) {
    winner = currentPlayer;
    running = false;
  } else if (std::none_of(b.begin(), b.end(), [](char c){ return c == ' '; })) {
    winner = "Draw";
    running = false;
  } else {
    if (currentPlayer == 'O') {
      currentPlayer = 'X';
    } else {
      currentPlayer = 'O';
    }
  }
}


void TicTacToe::playAgain() {
  std::string play_again;

  while (true) {
    std::cout << "Do you want to play again? [Y/n] ";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, play_again);

    std::transform(play_again.begin(), play_again.end(), play_again.begin(), ::tolower);
    
    if (play_again == "y" || play_again.empty()) {
      resetGame();
      drawBoard();
      running = true;
      return;
    }
    
    if (play_again == "n") {
      return;
    }

    std::cout << "Invalid input. Please enter [Y/n].";
  }
}