# Qt Chess Game

This is a basic chess game built using **C++** and **Qt** (with QWidget). It features a functional graphical user interface (GUI) and implements chess rules such as piece movement and turn handling.

## Features

- Graphical chessboard using Qt
- All standard chess pieces implemented:
  - Pawn, Rook, Knight, Bishop, Queen, King
- Valid movement logic for each piece
- Piece movement via mouse interaction
- Internal game state tracking using OOP (Piece, Square, ChessBoard classes)

## Technologies

- **Language:** C++
- **Framework:** Qt 6 (using Widgets, not QML)
- **Build System:** CMake or qmake (your choice)
- **IDE Recommended:** Qt Creator or VSCode with Qt plugin

## Project Structure
```
.
├── src/
│   ├── chessboard.h/.cpp        # Main board logic and UI
│   ├── piece.h/.cpp             # Base class and derived pieces
│   ├── square.h/.cpp            # Represents each board cell
│   ├── movementutils.h/.cpp     # Shared logic for straight/diagonal moves
│   └── main.cpp
├── resources/
│   └── icons/                   # Optional: Piece images
├── QtChess.pro                  # qmake build config (if using qmake)
├── CMakeLists.txt               # CMake build config (if using CMake)
└── README.md
``` 




## Build & Run Instructions

### Using Qt Creator

1. Open the `.pro` or `CMakeLists.txt` file in Qt Creator.
2. Configure your kit (e.g. Desktop Qt 6.6.1).
3. Click the green ▶️ "Run" button.

### Using CMake (CLI)

```bash
mkdir build
cd build
cmake ..
make
./QtChess
```

To Do

    Implement castling, en-passant, pawn promotion

    Add move history and undo

    Improve UI styling (piece images, highlights)






