
# 8-Puzzle Solver using A* Search (Manhattan Distance)

## Problem Statement
The 8-puzzle is a sliding puzzle with a 3x3 board containing 8 numbered tiles and one blank (0).
The objective is to reach the goal configuration.

### Goal State
```
1 2 3
4 5 6
7 8 0
```

## Description
This program solves the 8-puzzle using A* search with the Manhattan distance heuristic.
A priority queue guides the search by expanding the state with the lowest heuristic cost.
Visited states are tracked to avoid loops.

## Logic Used
1. Compute Manhattan distance for initial state.
2. Push into priority queue.
3. While queue not empty:
  - Pop best node.
  - If goal, stop and print path.
  - Else generate moves (up, down, left, right).
  - For each valid move, compute heuristic and push into queue if not visited.

## Time and Space Complexity
- Worst-case: O(n) where n = 9! = 362,880 states.
- Heuristic improves search efficiency.
- Space: O(n) for visited states.

## Limitations
- A* guarantees optimal path only if heuristic is admissible.
- Memory intensive for deep searches.

---

# Water Jug Problem using BFS

## Problem Statement
Two jugs with capacities m and n are given. The goal is to measure exactly d liters using the jugs.

## Description
This program uses BFS to find the sequence of steps to measure d liters.
Each state is represented as (jug1, jug2).

## Logic Used
1. Start from (0,0).
2. At each step, generate possible actions:
   - Fill Jug1, Fill Jug2, Empty Jug1, Empty Jug2, Pour Jug1 -> Jug2, Pour Jug2 -> Jug1.
3. Use BFS to explore states until one jug contains d liters.

## Time and Space Complexity
- At most m*n unique states.
- Time: O(m*n)
- Space: O(m*n)

## Limitations
- Works only if d is divisible by gcd(m, n).

---

# Magic Square Generator

## Problem Statement
Generate an odd-sized magic square where the sum of numbers in each row, column, and diagonal is the same.

## Description
This program uses the Siamese method for odd n.

## Logic Used
1. Place 1 in the middle of the top row.
2. Next number goes to the upper right cell (wrap around).
3. If occupied, move down one cell instead.

## Time and Space Complexity
- Time: O(n^2)
- Space: O(n^2)

## Limitations
- Works only for odd n.

---

# Tic-Tac-Toe with Simple AI

## Problem Statement
Tic-Tac-Toe game where a player competes against the computer.

## Description
Board is 3x3. The computer plays using simple rules:
1. Win if possible.
2. Block opponent's win.
3. Pick a corner if available.
4. Pick a side or remaining cell.

## Logic Used
- CheckWin checks rows, columns, diagonals.
- GetBestMove determines the best move for the computer.
- Turns alternate until a win is detected.

## Time and Space Complexity
- Max 9 moves → O(1) complexity.

## Limitations
- Not a full minimax AI.
- Computer may not always play optimally.
********