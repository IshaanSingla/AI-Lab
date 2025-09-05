
# Tic Tac Toe with Alpha-Beta Pruning in C++

## 1. Overview

This project implements a **Tic Tac Toe game** in **C++**, where a human player competes against an **AI opponent** that uses the **Minimax algorithm** combined with **Alpha-Beta Pruning** for optimal decision-making.  
The AI evaluates all possible moves, ensuring it never loses, while pruning unnecessary branches to improve computational efficiency.

---

## 2. Problem Statement

The program simulates a 3×3 Tic Tac Toe board with the following symbols:

| Symbol | Player |
|:--------|:------------|
| X | Computer (AI) |
| O | Human Player |
| . | Empty Cell |

The computer plays optimally using Minimax with Alpha-Beta pruning to minimize computation time.

**Goal:**  
- Computer (`X`) should either win or draw, but never lose.

---

## 3. Features

- Full **console-based Tic Tac Toe game**.  
- **Minimax algorithm** ensures optimal AI play.  
- **Alpha-Beta pruning** reduces the number of recursive evaluations.  
- Displays **leaf nodes explored** during each AI move.  
- Detects wins, losses, and draws accurately.  
- Handles invalid human inputs gracefully.

---

## 4. Algorithm Explanation

### 4.1 Alpha-Beta Pruning

Alpha-Beta pruning is an optimization technique for Minimax that **eliminates unnecessary branches** that do not affect the final decision.

**Variables:**
- `alpha` = best value achievable by the **maximizer** so far  
- `beta` = best value achievable by the **minimizer** so far  

If at any point `beta ≤ alpha`, further exploration of that branch is **stopped**.

This reduces the time complexity from **O(b^d)** to roughly **O(b^(d/2))**, where:  
- `b` = branching factor (possible moves per turn)  
- `d` = depth (maximum number of moves in the game)

**Pseudocode with Pruning:**
```
function minimax(state, depth, alpha, beta, isMaximizing):
    if terminal(state):
        return evaluate(state)

    if isMaximizing:
        best = -∞
        for each move in state:
            value = minimax(next_state, depth+1, alpha, beta, false)
            best = max(best, value)
            alpha = max(alpha, best)
            if beta <= alpha:
                break   # Beta cut-off
        return best
    else:
        best = +∞
        for each move in state:
            value = minimax(next_state, depth+1, alpha, beta, true)
            best = min(best, value)
            beta = min(beta, best)
            if beta <= alpha:
                break   # Alpha cut-off
        return best
```

---

## 5. Game Flow

### 5.1 Initialization
- A 3×3 grid is initialized with all cells empty.
- Computer (`X`) plays first.

### 5.2 Gameplay Loop
- Display board after every move.
- Alternate between Human (`O`) and Computer (`X`).
- Human enters move coordinates (row, column).
- AI selects the optimal move using Minimax with Alpha-Beta pruning.

### 5.3 Game Termination
The game ends when:
- Computer wins → “Computer wins!”  
- Human wins → “You win!”  
- No empty cells → “It’s a draw!”

---

## 6. Sample Output

### Initial Board
```
. . .
. . .
. . .
```

### Example Gameplay
```
. . .
. . .
. . .

Computer is thinking...
Total leaf nodes explored = 256104
X . .
. . .
. . .

Enter row and col (0-2): 0 1
X O .
. . .
. . .

Computer is thinking...
Total leaf nodes explored = 3668
X O .
X . .
. . .

Enter row and col (0-2): 2 0
X O .
X . .
O . .

Computer is thinking...
Total leaf nodes explored = 108
X O .
X X .
O . .

Enter row and col (0-2): 2 2
X O .
X X .
O . O

Computer is thinking...
Total leaf nodes explored = 5
X O .
X X X
O . O

Computer wins!
```

---

## 7. Complexity Analysis

| Aspect | Description |
|:--------|:-------------|
| **Time Complexity (Minimax)** | O(b^d) → ~9! ≈ 362,880 states |
| **Time Complexity (Alpha-Beta)** | ~O(b^(d/2)) in optimal pruning |
| **Space Complexity** | O(d) recursion depth (up to 9) |
| **Board Storage** | O(1), fixed 3×3 grid |

Alpha-Beta pruning significantly reduces the number of evaluated states while guaranteeing the same final decision.

---

## 8. Limitations

- Works only for 3×3 Tic Tac Toe.  
- Does not support dynamic board sizes.  
- No graphical user interface (CLI only).  
- Learning-based strategies (like reinforcement learning) not included.

---
