#include <iostream>
#include <conio.h>

using namespace std;

bool GameOver;
const int width = 50;
const int height = 30;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int ntail;
int cubX, cubY;
enum eDirection {stop = 0 , Left , Right, up , down};
eDirection dir;
enum Pregrada {LeftC , RightC};
Pregrada cub;

void setup() {
	GameOver = false;
	dir = stop;
	x = width / 2 -1;
	y = height / 2 -1 ;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
	//cubX = width / 3;
	//cubY = height / 3; я пробую усовершенствовать змейку

}

void Draw() {
	system("cls");
	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1)
				cout << "#";
			if (i == y && j == x)
				cout << "0";
			 //if (i == cubX && j == cubY)
				//cout << "=";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else {
				bool print = false;
				for (int k = 0; k < ntail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						print = true;
						cout << "o";
					}
				}
				if (!print)
				cout << " ";
			}	
			
		}
		cout << endl;
}
		
	for (int i = 0; i < width +1; i++)
		cout << "#";
	cout << endl;
	cout << "score =" << score << endl;

}

void imput() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a': 
			dir = Left;
			break;
		case 'd':
			dir = Right;
			break;
		case 'w':
			dir = up;
			break;
		case 's':
			dir = down;
			break;
		case 'x':
			GameOver = true;
			break;

		}
	}

}

void Logic() {
	int prevX = tailX[0] ;
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < ntail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;

	}

	switch (dir)
	{

	case Left:
		x--;
		break;
	case Right:
		x++;
		break;
	case up:
		y--;
		break;
	case down:
		y++;
		break;

	}
	//if (x > width || x<0 || y>height || y < 0) 
	//	GameOver = true;
	if (x >= width -1)
		x = 0;
	else if (x < 0)
		x = width - 2;

	if (y >= height)
		y = 0;
	else if (y < 0)
		y = height ;
	for (int i = 0; i < ntail; i++) {
		if (tailX[i] == x && tailY[i] == y)
			GameOver = true;
}
	
	if (x == fruitX && y == fruitY) {
	score += 10;
	fruitX = rand() % width -1;
	fruitY = rand() % height -1;
	ntail ++;
}
	if (score ==150) {
		GameOver = true;
		cout << "YOU ARE WINER"<< endl;
	}
}

int main() {
	setup();
	while (!GameOver) {
		Draw();
		imput();
		Logic();
	}
	return 0;
}