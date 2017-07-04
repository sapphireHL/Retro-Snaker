#pragma once

#include "object.h"

class food
{
public:
	food();
	~food();
	void generateFood();
	Position getFoodPosotion();
private:
	Position food_position;
};

