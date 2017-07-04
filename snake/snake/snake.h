#pragma once

#include "object.h"


class snake
{
public:
	snake();
	~snake();
	void init();
	deque<Position> getSnakePosition();
	Position getSnakeHead();
	Position getSnakeTail();
	int getSnakeLength();
	int getSnakeDirection();
	int getSnakeSpeed();
	void move();
	void expand(Position expandpos);
	void changeDirection(int dir);
	bool isHit();
	bool isMeetFood(Position foodpos);
private:
	deque<Position> snake_position;
	//…œ“ª∏ˆ…ﬂŒ≤
	Position last_tail;
	int snake_length;
	int snake_direction;
	int snake_speed;
};

