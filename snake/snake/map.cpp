#include "map.h"


map::map()
{
}


map::~map()
{
}

void map::initMap(){
	//��ʼ���߽�
	for (int i = 0; i <= WINDOW_HEIGHT; i++){
		for (int j = 0; j <= WINDOW_WIDTH; j++){
			if (i == 0 || i == WINDOW_HEIGHT) {
				cout << "-";
			}
			else {
				if (j == 0 || j == WINDOW_WIDTH) {
					cout << "|";
				}
				else {
					cout << ' ';
				}
			}
			if (j == WINDOW_WIDTH) cout << endl;
		}
	}
	gotoXY(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	cout << "snake" << endl;
	gotoXY(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 + 2);
	cout << "1.easy" << endl;
	gotoXY(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 + 3);
	cout << "2.normal" << endl;
	gotoXY(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 + 4);
	cout << "3.hard" << endl;
	gotoXY(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 + 5);
	cout << "4.exit" << endl;

	//���ȥ���һ��
	gotoXY(0, WINDOW_HEIGHT + 1);
}


void map::eraseMap(){
	for (int i = 1; i < WINDOW_HEIGHT; i++){
		for (int j = 1; j < WINDOW_WIDTH; j++){
			gotoXY(j, i);
			cout << ' ';
		}
	}
}

void map::gotoXY(int x, int y)//λ�ú���  
{
	COORD coord = { x, y };
	/*COORD��Windows API�ж����һ�ֽṹ����ʾһ���ַ��ڿ���̨��Ļ�ϵ����ꡣ�䶨��Ϊ��

	typedef struct _COORD {

	SHORT X; // horizontal coordinate

	SHORT Y; // vertical coordinate
	} COORD;*/
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void map::updateFood(Position oldfoodpos, Position newfoodpos){
	gotoXY(oldfoodpos.x, oldfoodpos.y);
	cout << ' ';
	gotoXY(newfoodpos.x, newfoodpos.y);
	cout << '*';
}

void map::updateSnake(Position newsnakehead, Position oldsnaketail, int mode){
	if (mode == MOVE_MODE){
		gotoXY(oldsnaketail.x, oldsnaketail.y);
		cout << ' ';
	}
	gotoXY(newsnakehead.x, newsnakehead.y);
	cout << 'O';
}

void map::retryMap(){
	gotoXY(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	cout << "game over!";
	gotoXY(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 + 1);
	cout << "1.retry";
	gotoXY(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 + 2);
	cout << "2.exit";
	//���ȥ���һ��
	gotoXY(0, WINDOW_HEIGHT + 1);
}

void map::updateScore(int score){
	gotoXY(SCORE_POSITION_X, SCORE_POSITION_Y);
	cout << "score:" << score;
	//���ȥ���һ��
	gotoXY(0, WINDOW_HEIGHT + 1);
}

void map::updateHighScore(int score){
	gotoXY(SCORE_POSITION_X, SCORE_POSITION_Y + 1);
	cout << "High score:" << score;
	//���ȥ���һ��
	gotoXY(0, WINDOW_HEIGHT + 1);
}