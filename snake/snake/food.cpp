#include "food.h"


food::food()
{
}


food::~food()
{
}

void food::generateFood(){
	srand(unsigned int(time(NULL)));
	int newx = rand() % (WINDOW_WIDTH - 1) + 1;
	int newy = rand() % (WINDOW_HEIGHT - 1) + 1;
	food_position.x = newx;
	food_position.y = newy;
}

Position food::getFoodPosotion(){
	return food_position;
}