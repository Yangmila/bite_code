#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>
#include <windows.h>
void init(char arry[][3], int x, int y)
{
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			arry[i][j] = ' ';
		}
	}
	return;
}
void face(char arry[][3], int x, int y)
{
	system("cls");
	printf("   | 1 | 2 | 3 \n");
	for (int i = 0; i < x; i++) {
		printf("---------------\n");
		printf(" %d | %c | %c | %c\n", i+1, arry[i][0], arry[i][1], arry[i][2]);
	}
	return ;
}
int pos_is_legal(char arry[][3], int x, int y) {
	if (x > 3 || x < 1 || y > 3 || y < 1) {
		printf("您输入的位置不合法!\n");
		return 0;
	}
	if (arry[x-1][y-1] != ' ') {
		printf("您输入的位置已经被占用:%d-%d-%c!\n", x, y, arry[x-1][y-1]);
		return 0;
	}
	return 1;
}
char is_win(char arry[][3], int x, int y) {
	for (int i = 0; i < x; i++) {
		if (arry[i][0] == arry[i][1] && arry[i][0] == arry[i][2]) {
			printf("%c-%c-%c\n", arry[i][0], arry[i][1], arry[i][2]);
			return arry[i][0];
		}
	}
	for (int i = 0; i < y; i++) {
		if (arry[0][i] == arry[1][i] && arry[0][i] == arry[2][i]) {
			printf("%c-%c-%c\n", arry[0][i], arry[1][i], arry[2][i]);
			return arry[0][i];
		}
	}
	if (arry[0][0] == arry[1][1] && arry[0][0] == arry[2][2]) {
		printf("%c-%c-%c\n", arry[0][0], arry[1][1], arry[2][2]);
		return arry[1][1];
	}
	if (arry[0][y - 1] == arry[1][1] && arry[1][1] == arry[x - 1][0]) {
		printf("%c-%c-%c\n", arry[0][y-1], arry[1][1], arry[x-1][0]);
		return arry[1][1];
	}
	return 'N';
}
void computer(char arry[][3], int x, int y)
{
	while (1) {
		int i = rand() % 3;
		int j = rand() % 3;
		if (arry[i][j] == ' ') {
			arry[i][j] = 'O';
			break;
		}
	}
	return ;
}
int result(char arry[][3], int x, int y, int *count)
{
	(*count)--;
	char ch = is_win(arry, x, y);
	switch (ch){
	case 'X':
		printf("你赢了，真棒~~\n");
		break;
	case 'O':
		printf("你输了，真菜~~\n");
		break;
	case 'N':
		if (*count == 0) {
			printf("棋逢对手~你的智商和电脑是一样的~\n");
			break;
		}
		return 1;
	default:
		return 1;
	}
	return 0;
}
int main()
{
	srand(time(NULL));
	char arry[3][3];
	int count = 9;
	init(arry, 3, 3);
	while (1) {
		face(arry, 3, 3);
		printf("请输入你要指定的位置坐标: ");
		int x, y;
		scanf("%d %d", &x, &y);
		if (!pos_is_legal(arry, x, y)) {
			continue;
		}
		arry[x-1][y-1] = 'X';
		if (result(arry, 3, 3, &count) == 0) {
			break;
		}
		face(arry, 3, 3);
		Sleep(1000);
		computer(arry, 3, 3);
		face(arry, 3, 3);
		if (result(arry, 3, 3, &count) == 0) {
			break;
		}
	}

	return 0;
}
