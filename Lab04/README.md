# Tic Tac Toe with Minimax in C++

## Problem Statement

This program implements **Tic Tac Toe** in C++ with the **Minimax
algorithm**, allowing the computer to play optimally against a human
player.

The game board is a 3x3 grid: - `X` = Computer (AI) - `O` = Human - `.`
= Empty cell

The **Minimax algorithm** ensures the computer never loses by exploring
all possible game states.

------------------------------------------------------------------------

## Description

The program: - Represents the game board as a 3×3 matrix. - Implements
the **Minimax algorithm** with recursion: - **Maximizing player:**
Computer (`X`) - **Minimizing player:** Human (`O`) - Evaluates terminal
states: - `+1` → Computer wins - `-1` → Human wins - `0` → Draw -
Selects the best move for the computer. - Prints the number of **leaf
nodes explored** during each AI move.

------------------------------------------------------------------------

## Logic Used

1.  **Game Initialization**
    -   Start with an empty 3×3 board.
2.  **Gameplay Loop**
    -   Display board after each move.
    -   Alternate between Human and Computer.
    -   Human inputs move via console (row and column).
    -   Computer uses **Minimax** to find the best move.
3.  **Game Termination**
    -   The game ends if:
        -   Computer wins → "Computer wins!"
        -   Human wins → "You win!"
        -   Board full → "It's a draw!"

------------------------------------------------------------------------

## Sample Run

### Initial Board

    . . .
    . . .
    . . .

### Example Gameplay

    . . .
    . . .
    . . .
    
    Computer is thinking...
    Total leaf nodes explored = 256104
    X . .
    . . .
    . . .
    
    Enter row and col (0-2):0 1
    X O .
    . . .
    . . .
    
    Computer is thinking...
    Total leaf nodes explored = 3668
    X O .
    X . .
    . . .
    
    Enter row and col (0-2):2 0
    X O .
    X . .
    O . .
    
    Computer is thinking...
    Total leaf nodes explored = 108
    X O .
    X X .
    O . .
    
    Enter row and col (0-2):2 2
    X O .
    X X .
    O . O
    
    Computer is thinking...
    Total leaf nodes explored = 5
    X O .
    X X X
    O . O
    
    Computer wins!

Board updates after each move until a winner or draw is determined.

------------------------------------------------------------------------

## Time and Space Complexity

### Time Complexity

-   Worst-case: `O(b^d)`\
    where `b = branching factor (~9 moves)` and `d = depth (~9)`.
-   In Tic Tac Toe: \~ **9! game states** (\~362,880).

### Space Complexity

-   Board storage: `O(1)` (fixed 3x3 grid).
-   Recursion stack: `O(d)` = up to 9.

------------------------------------------------------------------------

## Limitations

-   Works only for Tic Tac Toe (3×3).
-   Not optimized with **Alpha-Beta Pruning** (can be added).

------------------------------------------------------------------------
