# Chess Game - Qt C++ GUI

Welcome to my Chess game project written in **C++** using the **Qt framework**!  
This project features a graphical user interface with interactive piece movement, enforcing chess rules.

---

## 📝 Table of Contents

- [About](#about)  
- [Features](#features)  
- [Controls](#controls)  
- [Project Structure](#project-structure)  
---

## About

This project implements a classic chess game with an interactive GUI.  
The chessboard is rendered using Qt's painting system, and piece movement is controlled with mouse clicks.  

- Uses smart pointers (`unique_ptr`) for resource safety  
- Custom piece classes (Pawn, Rook, Knight, Bishop, Queen, King) with move validation  
- Player turn management and board reset functionality  
- Separation of GUI logic (`BoardWidget`) and window (`ChessBoard`) for clean design  

---

## Features

- Select and move pieces by clicking squares  
- Enforces legal chess moves per piece type  
- Highlights selected squares (planned)  
- Reset game option from menu bar  
- Future extensions planned: check/checkmate detection, castling, en passant  

---

## Controls

| Action       | Description                       |
|--------------|---------------------------------|
| Click Piece  | Select piece to move             |
| Click Square | Move selected piece if valid    |
| Reset        | Reset board to initial position |

---

## Project Structure

```plaintext
ChessGame/
├── boardWidget.h/.cpp           # Widget handling board rendering and interaction
├── chessboard.h/.cpp            # Main window containing the BoardWidget
├── pieces/                      # Individual piece classes
│   ├── pawn.h/.cpp
│   ├── rook.h/.cpp
│   ├── knight.h/.cpp
│   ├── bishop.h/.cpp
│   ├── queen.h/.cpp
│   └── king.h/.cpp
├── movementUtil.h/.cpp          # Movement utility functions for move validation and helpers
├── square.h/.cpp                # Square class managing piece ownership
├── player.h/.cpp                # Player and color management
├── main.cpp                     # Application entry point
└── README.md                    # This file
```

---

## To be added

1. Check and Checkmate mechanic
2. Castling
3. Pawn promotion  
4. Turn history  

---
