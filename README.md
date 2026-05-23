# Minesweeper

## Description
A standalone console-based Minesweeper game written in C++.
The player uncovers cells on a 5x5 grid while avoiding 5 hidden mines.

## How to Play
1. Build the project with the included source files.
2. Run the compiled executable.
3. Enter a row and column to reveal a cell.
4. If you reveal a mine (`M`), the game ends.
5. Win by revealing all safe cells without triggering a mine.

## Rules
- The board is fixed at 5x5.
- There are 5 randomly placed mines.
- Revealed safe cells display adjacent mine counts.
- Revealing a `0` cell expands nearby safe cells automatically.

## Required Files
- `MinesweeperGame.h`
- `Game.h`
- `Minesweeper.cpp`

## Build Instructions
```bash
g++ main.cpp -o Minesweeper.exe
```

## Run
```bash
./Minesweeper.exe
```

## Notes
- The game uses console input only.
- Enter coordinates as integer row and column values.
