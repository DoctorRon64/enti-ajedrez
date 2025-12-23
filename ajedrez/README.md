# Chess Game in C++

## Project Overview
This is a console-based Chess game implemented in C++. The game allows two players to play chess with full move validation, check, checkmate, stalemate detection, and pawn promotion. The board is displayed in the console, and players enter their moves via standard input.

---

## Implemented Features

### 1. **Move Validation**
All chess pieces move according to standard rules. Moves are validated before they are executed.
- **Implemented in:** `Moves/Moves.cpp` and `Moves/Moves.h`
- **Functions:**  
  - `is_valid_move()` – General move validation dispatcher.  
  - `valid_pawn_move()`, `valid_rook_move()`, `valid_knight_move()`, `valid_bishop_move()`, `valid_queen_move()`, `valid_king_move()` – Specific piece validation functions.

---

### 2. **Check and Checkmate Detection**
The game detects if a king is in check or if the game has reached checkmate or stalemate.
- **Implemented in:** `Board/Board.cpp` and `Board/Board.h`
- **Functions:**  
  - `is_in_check()` – Detects if the current player's king is under attack.  
  - `is_checkmate()` – Determines if the game is in checkmate.  
  - `can_any_move_rescue()` – Determines if a king can escape check.  

---

## Additional Features

- **Board Initialization and Printing**  
  - Initializes the board with standard chess starting positions.  
  - Prints the board in a human-readable format in the console.  
  - **Files:** `Board/Board.cpp`, `Board/Board.h`

- **Pawn Promotion**  
  - Automatically promotes pawns to queens when they reach the opposite end of the board.  
  - **Files:** `Board/Board.cpp` in `move_piece()` function.

- **En Passant Capture**  
  - Supports en passant moves for pawns.  
  - **Files:** `Board/Board.cpp` in `move_piece()` and `valid_pawn_move()`.  

---

## How to Run
1. Compile all `.cpp` files with a C++ compiler (e.g., g++).  
2. Run the generated executable.  
3. Enter moves using row and column numbers for `from` and `to` positions.  

---

## Notes
- Console clears and input prompts are platform-specific (Windows uses `cls`, Linux/macOS use `clear`).  
- The game continues until a checkmate or stalemate occurs.  

