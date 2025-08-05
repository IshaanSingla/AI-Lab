# 8-Puzzle Solver using Depth-First Search (DFS) in C++

## Problem Statement

The 8-puzzle is a classic sliding tile puzzle composed of a 3x3 grid with 8 numbered tiles and one blank space (represented as `0`). The objective is to move the tiles using the blank space until the puzzle reaches the goal configuration.

### Example Goal State:

```cpp
vector<vector<int>> GoalState = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};
```

Given an initial board configuration, determine whether the goal state can be reached and, if so, provide the sequence of steps.

---
## Description

This program implements a Depth-First Search (DFS) to solve the 8-puzzle problem. It systematically explores possible board configurations using valid tile movements (up, down, left, right) and backtracking.

The search maintains:
- A **main stack** of all paths being explored.
- A **visited list** to prevent revisiting previously seen board states.
- A **final path stack** to store the solution sequence once the goal state is found.

Each element in the main stack is a path represented as a stack of 2D board states (from initial to current state).

---
## Logic Used

1. **Initialization**
   - The goal state is defined statically.
   - The initial state is pushed into a stack and added to the list of visited states.

2. **Depth-First Search Loop**
   - While the stack is not empty:
     - Pop a path (stack of states) from the main stack.
     - If the top state matches the goal, the solution has been found.
     - Otherwise, generate all valid next moves from the current state.
     - For each valid move:
       - If the resulting state has not been visited:
         - Clone the current path, push the new state, and push the new path onto the main stack.
         - Add the new state to the visited list.

3. **Move Generation**
   - Locate the position of the blank tile (0).
   - Attempt to move it in four directions (up, down, left, right), checking for bounds.
   - Skip moves that produce already-visited states.

---
## Example Initial State Used
```cpp
vector<vector<int>> initialState = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 0, 8}
};
```

---
## Sample Output

```bash
mainStack Size 1
mainStack Size 3
Goal state reached!
Final Stack:
1 2 3 
4 5 6 
7 8 0
-----
1 2 3
4 5 6
7 0 8
-----
Final Stack size: 2
```
---
## Time and Space Complexity

Let:
- `b` be the branching factor (maximum 4 possible moves),
- `d` be the depth (number of moves to reach the goal),
- `n` be the number of possible states $(9! = 362,880)$.
### Time Complexity

- Worst-case time complexity: $O(b^d) ≈ O(4^d)$
    
- Since DFS can explore all valid permutations, the upper bound is $O(n) = O(362,880)$, but pruning with the `Visited` list reduces actual search.
    

### Space Complexity

- Space used for:
    - The `mainStack` of paths: $O(d)$ per path
    - The `Visited` list: $O(n)$
    - Each path stack contains $O(d)$ board states.

---
## Limitations

- DFS is not guaranteed to find the shortest solution path.
- May consume a lot of memory or time in deep branches.
---
