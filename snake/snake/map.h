#pragma once

#include "object.h"

class map
{
public:
	map();
	~map();
	void gotoXY(int x, int y);
	void initMap();
	void eraseMap();
	void retryMap();
	void updateSnake(Position newsnakehead, Position oldsnaketail, int mode);
	void updateFood(Position oldfoodpos, Position newfoodpos);
	void updateScore(int score);
	void updateHighScore(int score);

private:
};

