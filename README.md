### Game Boards and Pieces 
**Author**: Nicole Lucas 

**Email**: nicoleclucas003@gmail.com

## Overview :pushpin:
This lab extends the functionality of our previous C++ project by incorporating more advanced features such as file parsing, data validation, and representation of game pieces on a 2D board.

The project focuses on building a program that can interpret and display the layout of a game board (e.g., Tic-Tac-Toe, Gomoku) based on input from formatted text files. This lab emphasizes modular code, error handling, and structured data representation using `struct`s and `vector`s.

## Features :wrench:

- **Dynamic Board Configuration**: 
  - Reads board dimensions from a file.
  - Supports any rectangular board size.

- **Game Piece Representation**:
  - Uses a `struct` to store the piece color, name, and display symbol.
  - Populates the board based on piece positions defined in the input file.

- **Error Handling**:
  - Skips invalid lines in input files without terminating the program.
  - Exits with error messages for critical issues (e.g., file not found, missing board dimensions).

- **Board Display**:
  - Prints the board to the console with piece symbols shown in the correct locations.
