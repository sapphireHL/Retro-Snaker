#include "snake.h"
#include "food.h"


snake::snake()
{
}


snake::~snake()
{
}

void snake::init(){
	srand(unsigned int(time(NULL)));
	int direction = rand() % 4;
	Position init_pos(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	snake_direction = direction;
	snake_length = 1;
	snake_speed = 1;
	snake_position.resize(1);
	snake_position[0] = (init_pos);
	last_tail = Position(init_pos);
}

int snake::getSnakeDirection(){
	return snake_direction;
}

int snake::getSnakeLength(){
	return snake_length;
}

int snake::getSnakeSpeed(){
	return snake_speed;
}

Position snake::getSnakeHead(){
	return snake_position.front();
}

Position snake::getSnakeTail(){
	return snake_position.back();
}

deque<Position> snake::getSnakePosition(){
	return snake_position;
}

void snake::move(){
	Position currentpos = snake_position.front();
	last_tail = snake_position.back();
	snake_position.pop_back();
	switch (snake_direction){
	case LEFT:
		snake_position.push_front(Position(currentpos.x - 1, currentpos.y));
		break;
	case RIGHT:
		snake_position.push_front(Position(currentpos.x + 1, currentpos.y));
		break;
	case UP:
		snake_position.push_front(Position(currentpos.x, currentpos.y - 1));
		break;
	case DOWN:
		snake_position.push_front(Position(currentpos.x, currentpos.y + 1));
		break;
	}
}

void snake::expand(Position expandpos){
	snake_length++;
	snake_position.push_back(last_tail);
}

void snake::changeDirection(int dir){
	if (snake_direction == LEFT && dir == RIGHT)return;
	if (snake_direction == RIGHT && dir == LEFT)return;
	if (snake_direction == UP && dir == DOWN)return;
	if (snake_direction == DOWN && dir == UP)return;
	snake_direction = dir;
}

bool snake::isHit(){
	Position head = snake_position.front();
	//Ç½
	if (head.x == 0 || head.x == WINDOW_WIDTH)
		return true;
	if (head.y == 0 || head.y == WINDOW_HEIGHT)
		return true;
	//×ÔÉí
	for (int i = 1; i < (int)snake_position.size(); i++){
		if (head == snake_position[i]) 
			return true;
	}
	return false;
}

bool snake::isMeetFood(Position foodpos){
	return snake_position.front() == foodpos;
}