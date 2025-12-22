# Chess Game (C++ Console)
This is a simple console-based chess game implemented in C++.  

## Implemented Features
Two of the following features are implemented:

- **Pawn Promotion** ✅  
  When a pawn reaches the last row, it is promoted to a queen.  
  **Implemented in:** `Board/Board.cpp` → `move_piece()`

- **En Passant** ✅  
  Allows a pawn to capture another pawn that just moved two squares forward.  
  **Implemented in:** `Board/Board.cpp` → `move_piece()`  
  **Also validated in:** `Moves/Moves.cpp` → `valid_pawn_move()`

> **Note:** Checkmate logic is partial; only king moves are considered. Capturing or blocking to escape check is not handled.

## Code Structure
- **Board/** → Board representation and movement logic (`Board.h`, `Board.cpp`)  
- **Moves/** → Validation of piece movements (`Moves.h`, `Moves.cpp`)  
- **Piece/** → Piece types and helper functions (`Piece.h`, `Piece.cpp`)  
- **Input/** → User input handling (`Input.h`, `Input.cpp`)  
- **Utils/** → Utility structs like `Vector2`  

## How to Run
1. Open the project in Visual Studio.  
2. Build the solution.  
3. Run the executable to play the game in the console.
