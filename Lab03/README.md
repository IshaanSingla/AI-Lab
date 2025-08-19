# A* Pathfinding Solver in C++

## Problem Statement

The A* algorithm is a graph traversal and path search algorithm widely used in pathfinding for games, robotics, and AI.  
It finds the shortest path between a **start** and **goal** node on a grid with obstacles by combining:

- **g(n):** cost from start to current node
- **h(n):** heuristic estimate (Manhattan distance) to goal
- **f(n) = g(n) + h(n):** total estimated cost

The algorithm ensures optimality (if heuristic is admissible) and efficiency.

### Example Grid

```cpp
vector<vector<int>> grid = {
    {0,0,0,0,0},
    {0,1,1,0,0},
    {0,0,0,1,0},
    {0,1,0,0,0},
    {0,0,0,1,0}
};
pair<int,int> start = {0,0};
pair<int,int> goal  = {4,4};
```

Here:
- `0` = free cell
- `1` = obstacle

---

## Description

This program implements the **A* search algorithm** for grid-based pathfinding.

The algorithm uses:
- A **priority queue (min-heap)** ordered by `f(n) = g(n) + h(n)`.
- The **Manhattan distance** heuristic:  
  h(x,y) = |x_current - x_goal| + |y_current - y_goal|
- A **visited matrix** to avoid revisiting cells.
- **Path reconstruction** using parent pointers once the goal is reached.

---

## Logic Used

1. **Initialization**
    - Push the start node into the priority queue with `g=0` and `h=Manhattan(start, goal)`.
    - Maintain a visited matrix.

2. **Search Loop**
    - Extract the node with the lowest cost `(g+h)` from the priority queue.
    - If it matches the goal, reconstruct and print the path.
    - Otherwise, expand valid neighbors (up, down, left, right).
    - For each neighbor:
        - Skip if out of bounds or blocked.
        - If unvisited, compute new `g`, `h`, and push into the queue.

3. **Termination**
    - If queue is exhausted without reaching the goal → "No path found."

---

## Example Input

### Grid:
```
0 0 0 0 0
0 1 1 0 0
0 0 0 1 0
0 1 0 0 0
0 0 0 1 0
```

### Start:
```
(0,0)
```

### Goal:
```
(4,4)
```

---

## Sample Output

```bash
Path found:
(0,0) (1,0) (2,0) (2,1) (2,2) (3,2) (3,3) (3,4) (4,4)
```

---

## Time and Space Complexity

Let:
- `V` = number of vertices (cells in grid = rows × cols)
- `E` = number of edges (each cell has up to 4 neighbors)

### Time Complexity
- Inserting/removing from priority queue: `O(log V)`
- Processing all neighbors: `O(E log V)`
- For grid: `O(rows × cols × log(rows × cols))`

### Space Complexity
- Priority queue: `O(V)`
- Visited matrix: `O(V)`
- Parent links for reconstruction: `O(V)`

---

## Limitations
- Assumes Manhattan distance (best for 4-directional grids).
- Does not account for diagonal movement.
- Memory usage can grow with grid size.  
