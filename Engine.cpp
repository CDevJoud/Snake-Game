#include "Engine.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
void Engine::setWidth(int w)
{
	Width = w;
}

void Engine::setHeight(int h)
{
	Height = h;
}

void Engine::MainMenu()
{

	system("cls");
	std::cout << "1) Start The Game.\n"
			  << "2) How To Play.\n"
			  << "3) Options\n";
	switch (_getch())
	{
	case '1':
		break;
	case '2':
	{
		system("cls");
		std::cout << "WASD is The movement.\n" << "C toggles on/off the Cordinates\n" << "E Exit From The Game" << std::endl;
		system("pause");
		MainMenu();
	}
	break;
	case '3':
		Options();
		MainMenu();
	break;
	default:
		MainMenu();
		break;
	}
}

void Engine::Options()
{
	system("cls");
	std::cout << "Its Will be Available In future!";
	system("pause >nul");
}

void Engine::Start()
{
	system("title Snake Game Made By Joud Version 1.0");
	MainMenu();
	while (true)
	{
		Draw();
		Input();
		Update();
		Logic();
		Sleep(50);
	}
}

void Engine::ShowCordinates()
{
	std::cout << "X:" << PX << " Y:" << PY << std::endl;
}

void Engine::Draw()
{
	system("cls");

	for (int w = 0; w < Width + 2; w++)
		std::cout << wall;
	std::cout << std::endl;

	for (int h = 0; h < Height; h++)
	{
		for (int w = 0; w < Width; w++)
		{
			if (w == 0)
				std::cout << wall;
			if (PX == w && PY == h)
				std::cout << snakeHead;
			else if (foodX == w && foodY == h)
				std::cout << food;
			else
			{
				bool print = false;
				for (int t = 0; t < TailLength; t++)
				{
					if (tailX[t] == w && tailY[t] == h)
					{
						std::cout << snakeTaile;
						print = true;
					}
				}
				if (!print)
					std::cout << air;
			}
			if (w == Width - 1)
				std::cout << wall;
		}
		std::cout << std::endl;
	}
	for (int w = 0; w < Width + 2; w++)
		std::cout << wall;
	std::cout << std::endl;
}

void Engine::Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'p':
			system("pause >nul");
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'c':
			toggleCordinates = true;
			break;
		case 'e':
			Exit(0x03, NULL);
		default:
			break;
		}
	}
}

void Engine::Update()
{
	switch (dir)
	{
	case UP:
		PY--;
		break;
	case DOWN:
		PY++;
		break;
	case LEFT:
		PX--;
		break;
	case RIGHT:
		PX++;
		break;
	default:
		break;
	}
	if (toggleCordinates)
		ShowCordinates();
}

void Engine::Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = PX;
	tailY[0] = PY;
	for (int i = 1; i < TailLength; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	if (PX >= Width) PX = 0; else if (PX < 0) PX = Width - 1;
	if (PY >= Height) PY = 0; else if (PY < 0) PY = Height - 1;

	for (int i = 2; i < TailLength; i++)
	{
		if (tailX[i] == PX && tailY[i] == PY)
			Exit(0x04, NULL);
	}

	if (PX == foodX && PY == foodY) 
	{
		foodX = rand() % Width;
		foodY = rand() % Height;
		TailLength++;
	}
}

void Engine::setPX(int x)
{
	if (x <= Width)
		PX = x;
	else
		Exit(0x01, x);
}

void Engine::setPY(int y)
{
	if (y <= Height)
		PY = y;
	else
		Exit(0x02, y);
}

int Engine::Exit(int EXITCODE, int PASSINGOTHERINFORMATION)
{
	if (EXITCODE == 0x01)
	{
		std::cout << "Joud I Think You Have Missed Up Something." << std::endl << "You Have Entered A Value Bigger Than You Have Specified!" << std::endl << "More Details And Location Is In: \n" << "Location:" << std::endl << "Engine::setPX(int x) \n" << "Width Is :" << Width << std::endl << "Cordinates Is :" << PASSINGOTHERINFORMATION << std::endl << "Please Fix It!!" << std::endl;
		exit(0x01);
	}
	if (EXITCODE == 0x02)
	{
		std::cout << "Joud I Think You Have Missed Up Something." << std::endl << "You Have Entered A Value Bigger Than You Have Specified!" << std::endl << "More Details And Location Is In: \n" << "Location:" << std::endl << "Engine::setPY(int y) \n" << "Height Is :" << Height << std::endl << "Cordinates Is :" << PASSINGOTHERINFORMATION << std::endl << "Please Fix It!!" << std::endl;
		exit(0x02);
	}
	if (EXITCODE == 0x03)
	{
		system("cls");
		std::cout << "You Have Exit From The Game I Hope You Enjoied!!!\n";
		system("pause");
		exit(0x03);
	}
	if (EXITCODE == 0x04)
	{
		system("CLS");
		std::cout << "You Lost The Game!";
		Sleep(5000);
		exit(0x04);
	}
}

void Engine::setFood(std::string FOOD)
{
	food = FOOD;
}

void Engine::setWall(std::string WALL)
{
	wall = WALL;
}

void Engine::setAir(std::string AIR)
{
	air = AIR;
}

void Engine::setSnakeHead(std::string SNAKEHEAD)
{
	snakeHead = SNAKEHEAD;
}

void Engine::setSnakeTaile(std::string SNAKETAILE)
{
	snakeTaile = SNAKETAILE;
}