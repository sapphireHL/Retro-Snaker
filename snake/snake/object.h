#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

const int LEFT = 0;
const int RIGHT = 1;
const int UP = 2;
const int DOWN = 3;
const int WINDOW_HEIGHT = 26;
const int WINDOW_WIDTH = 60;
const int EXPAND_MODE = 0; 
const int MOVE_MODE = 1;
const int SCORE_POSITION_X = 70;
const int SCORE_POSITION_Y = 13;

struct Position
{
	int x, y;
	Position(){};
	Position(int px, int py) :x(px), y(py){}

};

bool operator == (const Position A, const Position B);
