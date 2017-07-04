#include "game.h"


game::game()
{
}


game::~game()
{
}

void game::gameInit(){
	//改变控制台大小
	system("mode con:cols=100 lines=30");
	//隐藏光标
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	GetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
	ConsoleCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);

	game_end = false;
	game_score = 0;
	game_highest_score = max(game_score, game_highest_score);
	map.initMap();
	int level;
	while (cin >> level){
		if (level == 4){
			game_end = true;
			break;
		}
		if (level < 4){
			setGameClock((int)pow(2, level));
			//初始化
			snake.init();
			food.generateFood();
			break;
		}
	}
}

void game::gamePlay(){
	//循环
	while (1){
		if (game_end){
			gameEnd();
			return;
		}
		//清除开始界面
		map.eraseMap();
		map.updateFood(food.getFoodPosotion(), food.getFoodPosotion());
		map.updateSnake(snake.getSnakeHead(), snake.getSnakeTail(), MOVE_MODE);
		map.updateScore(game_score);
		map.updateHighScore(game_highest_score);

		while (1){
			Sleep(500 / game_clock);
			Position oldTail = snake.getSnakeTail();
			int key = 0;
			int mode = MOVE_MODE;
			if (_kbhit()){
				key = _getch();
				if (key == 224){
					key = _getch();
					switch (key){
					case 72:
						snake.changeDirection(UP);
						break;
					case 80:
						snake.changeDirection(DOWN);
						break;
					case 75:
						snake.changeDirection(LEFT);
						break;
					case 77:
						snake.changeDirection(RIGHT);
						break;
					}
				}
			}
			snake.move();
			if (snake.isHit()) break;
			if (snake.isMeetFood(food.getFoodPosotion())){
				game_score++;
				map.updateScore(game_score);
				snake.expand(food.getFoodPosotion());
				Position oldFoodPos = food.getFoodPosotion();
				food.generateFood();
				map.updateFood(oldFoodPos, food.getFoodPosotion());
				mode = EXPAND_MODE;
			}
			Position newHead = snake.getSnakeHead();
			map.updateSnake(newHead, oldTail, mode);
		}
		game_highest_score = max(game_score, game_highest_score);
		map.updateHighScore(game_highest_score);
		Sleep(500);
		map.retryMap();
		int option;
		while (cin >> option){
			if (option == 2) return;
			if (option == 1) {
				gameInit();
				break;
			}
		}
	}
	//map.gotoXY(0, WINDOW_HEIGHT + 1);
}

void game::setGameClock(int clock){
	game_clock = clock;
}

void game::gameEnd(){

}

int game::getGameScore(){
	return game_score;
}

int game::getHighestScore(){
	return game_highest_score;
}
