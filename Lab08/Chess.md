# Pygame Chess Game with AI (Minimax + Alpha-Beta Pruning)

## AIM
To implement a **fully functional chess game using Pygame**, including:
- Complete board rendering  
- Piece movement logic  
- Legal move validation  
- Move highlighting  
- Captured piece tracking  
- Turn-based gameplay  
- A basic **AI opponent using Minimax with Alpha-Beta pruning**

---

## Overview

This project is a graphical chess game created with **Python + Pygame**.  
It supports:
- Human vs. AI gameplay  
- Full set of rules for all chess pieces  
- Real-time move validation  
- Piece capturing  
- Check detection  
- Visual game over screen  

The AI evaluates board states using:
- **Piece values**
- **Mobility**
- **Center control**
- **Material balance**

---

## System Architecture

### 1. **Board Rendering**
The chessboard is drawn using an 8×8 grid.  
Alternating tile colors create the classic pattern.

Additional UI elements:
- Status bar  
- Captured-piece display  
- Game over overlay  

### 2. **Piece Management**
Each side maintains:
- A list of piece names  
- A list of `(x, y)` coordinates  
- Lists of captured pieces  

Example:
```python
white_pieces = ['rook', 'knight', ...]
white_locations = [(0, 0), (1, 0), ...]
```

### 3. **Image Loading**
Piece graphics are downloaded dynamically from URLs.  
Rembg is used to remove the backgrounds.

---

## Move Generation Logic

Each piece type has a dedicated function:

| Piece   | Function           |
|--------|--------------------|
| Pawn   | `check_pawn()`     |
| Rook   | `check_rook()`     |
| Bishop | `check_bishop()`   |
| Knight | `check_knight()`   |
| Queen  | `check_queen()`    |
| King   | `check_king()`     |

All functions return a list of **legal target squares**.

The utility function:
```python
check_options(pieces, locations, turn)
```
computes all legal moves for a player.

---

## AI System

### **1. Minimax Algorithm**
The AI simulates future board states recursively.

### **2. Alpha-Beta Pruning**
Search space is trimmed by ignoring subtrees that do not affect the final decision.

### **3. Board Evaluation Function**
The score is calculated using:
- Material values  
- Center control  
- Move mobility  

Example:
```python
piece_values = {'pawn':1, 'bishop':3, 'rook':5, ...}
```

### **4. Best Move Selection**
The AI tries all legal moves and chooses the one with the **lowest evaluation**
(since AI plays black).

---

## Game Flow

### 1. **Human Turn**
- Select a white piece  
- Highlight legal moves  
- Choose destination  

### 2. **AI Turn**
Triggered automatically when:
```python
turn_step == 2
```

### 3. **Move Execution**
Handles:
- Movement  
- Captures  
- Piece removal  
- Turn switching  

### 4. **Check Detection**
Highlights king’s square if under threat.

### 5. **Win Detection**
If a king is captured:
```
winner = 'white' or 'black'
```

### 6. **Restart System**
Press ENTER to reset everything.

---

## Time Complexity

| Feature | Complexity |
|--------|------------|
| Move generation | O(N) per piece |
| Minimax depth d | O(b^d) |
| With alpha-beta | Much lower effective branching |

---
