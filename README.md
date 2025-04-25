[![License](https://img.shields.io/github/license/giansimone/tic-tac-toe-cpp)](https://github.com/giansimone/tic-tac-toe-cpp/blob/main/LICENSE)

# Tic-Tac-Toe in C++

A text-based Cimplementation of the classic Tic-Tac-Toe game developed in C++.

## Features

- Playable on a 3x3 grid.
- Randomly selects the first player (_X_ or _O_).
- Detect wins, draws, and invalid moves.
- Option to play again after a game ends.
- Clean and simple text-based interface.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., `clang++` or `g++`).
- `make` build tool.

### Building the Project

1. Clone the repository:
```bash
  git clone https://github.com/giansimone/tic-tac-toe-cpp.git
```

2. Navigate the project directory:
```bash
  cd tic-tac-toe-cpp
```

3. Build the project:
```bash
  make
```

4. To build the project in debug mode:
```bash
  make debug
```

### Running the game

After building, run the game using:
```bash
  ./bin/tictactoe
```

## How to Play
1. The game starts with an empty grid.
2. The first player is randomly chosen.
3. Players take turns entering the row and column numbers where they want to place their mark.
  - The board positions are numbered as follows:
    ```
    1 | 2 | 3
    ---------
    4 | 5 | 6
    ---------
    7 | 8 | 9
    ```
4. The game continues until there is a winner or the game ends in a draw.
5. The game announces the result and asks if you want to play again.
6. Enter 'y' or 'n' to continue or exit the game.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.