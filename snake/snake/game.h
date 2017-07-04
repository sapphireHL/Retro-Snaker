#pragma once

#include "food.h"
#include "snake.h"
#include "map.h"

class game
{
public:
	game();
	~game();
	void gameInit();
	void gamePlay();
	void gameEnd();
	void setGameClock(int clock);
	void setGameScore();
	int getGameClock();
	int getGameScore();
	int getHighestScore();

private:
	int game_clock;
	int game_score;
	int game_highest_score;
	bool game_end;
	map map;
	snake snake;
	food food;
};

