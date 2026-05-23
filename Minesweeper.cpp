#include <iostream>
#include "Game.h"
#include "MinesweeperGame.h"

int main()
{
    Game* game = new MinesweeperGame();
    game->play();
    delete game;
    return 0;
}