#pragma once
#include <iostream>

class Engine
{
public:
	void Options();
	void Start();
	void setAir(std::string);
	void setWall(std::string);
	void setSnakeHead(std::string);
	void setSnakeTaile(std::string);
	void setFood(std::string);

	void setWidth(int);
	void setHeight(int);
	void setPX(int);
	void setPY(int);
	void Draw();
	void Input();
	void Update();
	void Logic();
	int Exit(int, int);
	
private:
	void MainMenu();
	void ShowCordinates();
	bool toggleCordinates = false;
	int TailLength = 1;
	int tailX[1000], tailY[1000];
	enum eDir{STOP = 0, UP, DOWN, LEFT, RIGHT};
	eDir dir;
	int foodX = Width % 2; int foodY = Height % 2;
	int PX;
	int PY;
	int Width;
	int Height;
	std::string wall;
	std::string air;
	std::string snakeHead;
	std::string snakeTaile;
	std::string food;
};

