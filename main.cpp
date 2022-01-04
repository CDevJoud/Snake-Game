#include "Engine.h"

int main()
{
	Engine game;
	game.setWidth(50);
	game.setHeight(25);
	game.setWall("#");
	game.setAir(" ");
	game.setSnakeHead("O");
	game.setSnakeTaile("o");
	game.setFood("h");
	game.setPX(10);
	game.setPY(2);
	game.Start();
	return 0;
}