#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>
#include <windows.h>

//写一个函数打印arr数组的内容，不使用数组下标，使用指针



/*
#include <stdio.h>
int main()
{
	int i = 1;
	int ret = (++i) + (++i) + (++i);
	printf("ret = %d\n", ret);
	system("pause");
	return 0;
}
*/
/*
#include <stdio.h>
int i;//全局变量若不进行初始化赋值，则默认为0
int main()
{
	i--; // -1
	if (i > sizeof(i))//sizeof返回的数据是一个无符号数据
	{
		printf(">\n");
	}
	else
	{
		printf("<\n");
	}
	system("pause");
	return 0;
}
*/
/*
//交换两个变量（不创建临时变量）
int main()
{
	int a = 20;
	int b = 30;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("%d-%d\n", a, b);
	system("pause");
	return 0;
}
*/
/*
//打印整数二进制的奇数位和偶数位
int main()
{
	int a = 45676;
	for (int i = 31; i > 0; i -= 2) {
		printf("%d ", (a >> i) & 1);
	}
	printf("\n");
	for (int i = 30; i >= 0; i -= 2) {
		printf("%d ", (a >> i) & 1);
	}
	system("pause");
	return 0;
}
*/
/*
//统计二进制中1的个数
int binary_count(int num)
{
	int count = 0;
	while (num) {
		num = num & (num - 1);
		count++;
	}
	return count;
}
//求两个数二进制中不同位的个数

int main()
{
	int a = 20;
	int b = 100;
	int tmp = a ^ b;//异或：二进制位相同则为0，不同则为1
	printf("%d\n", binary_count(tmp));
	system("pause");
	return 0;
}
*/
/*
//三子棋
//规则：3x3的棋盘， 一个用户下X， 一个用户下O
//你一下，我一下，直到有三个字符连续且相同，则表示有一方剩了； 
//最后如果没有位置了，则平局

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
	return 0;
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

	system("pause");
	return 0;
}
*/
/*
//将数组A中的内容和数组B中的内容进行交换
int main()
{
	int arry1[] = { 1, 3, 5, 7, 9 };
	int arry2[] = { 2, 4, 6, 8, 10 };
	int size = sizeof(arry1) / sizeof(arry1[0]);
	for (int i = 0; i < size; i++) {
		printf("%d ", arry1[i]);
	}
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arry2[i]);
	}
	printf("\n");
	for (int i = 0; i < size; i++) {
		int tmp = arry1[i];
		arry1[i] = arry2[i];
		arry2[i] = tmp;
	}
	for (int i = 0; i < size; i++) {
		printf("%d ", arry1[i]);
	}
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arry2[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
*/
/*
//创建一个整形数组，完成对数组的操作
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。

void init(int arry[], int count) {
	for (int i = 0; i < count; i++) {
		arry[i] = 0;
	}
	return;
}
void print(int arry[], int count) {
	for (int i = 0; i < count; i++) {
		printf("%d ", arry[i]);
	}
	printf("\n");
	return;
}
void reverse(int arry[], int count) {
	for (int i = 0; i < count / 2; i++) {
		int tmp = arry[i];
		arry[i] = arry[count - 1 - i];
		arry[count - 1 - i] = tmp;
	}
	return;
}
int main()
{
	int arry[10];
	int size = sizeof(arry) / sizeof(arry[0]);
	init(arry, size);
	for (int i = 0; i < size; i++) {
		arry[i] = i;
	}
	print(arry, size);
	reverse(arry, size);
	print(arry, size);
	system("pause");
	return 0;
}
*/
/*
//递归和非递归分别实现求第n个斐波那契数
// 1 1 2 3 5 8 13 ....    fib(n) = fib(n-1)+ fib(n-2)
//fib(5) = 2 + 1 + 2
//fib(4) = 
//fib(3) = fib(2) + fib(1)
int fibonacci(int n)
{
	if (n <= 2) {
		return 1;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}
//int fibonacci(int n)
//{
//	int fac[1024] = { 1, 1, 1 };
//	for (int i = 3; i <= n; i++) {
//		fac[i] = fac[i - 1] + fac[i - 2];
//	}
//	return fac[n];
//}
int main()
{
	printf("%d\n", fibonacci(7));
	system("pause");
	return 0;
}
*/
/*
//编写一个函数实现n的k次方，使用递归实现。
//5^4 = 5 * 5^3 =  5*5^2
int mypow(int n, int k)
{
	if (k == 0) {
		return 1;
	}
	if (k == 1) {
		return n;
	}
	return n * mypow(n, k - 1);
}
int main()
{
	printf("%d\n", mypow(2, 6));
	system("pause");
	return 0;
}
*/

/*
//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
//6789    6+7+8+9 = 
int DigitSum(int n)
{
	if (n < 10) {
		return n;
	}
	int num = n % 10;
	return num + DigitSum(n / 10);
}
int main()
{
	printf("%d\n", DigitSum(6789));
	system("pause");
	return 0; 
}
*/
/*
//编写一个函数 reverse_string(char * string)（递归实现）
// nihao   iha
char *reverse_string(char *string)
{
	if (strlen(string) < 2) {
		return string;
	}
	int len = strlen(string) - 1;
	char ch = *string;//保存首字符  nihao
	*string = *(string + len); //将末尾字符复制给首字节空间

	*(string + strlen(string) - 1) = '\0'; 
	
	reverse_string(string + 1);

	*(string + len) = ch;

	return string;
}
int main()
{
	char buf[] = "nihao";
	printf("%s\n", reverse_string(buf));
	system("pause");
	return 0;
}
*/

/*
//递归和非递归分别实现strlen--求字符串的长度（起始位置到\0处）
//int mystrlen(char *str)
//{
//	int count = 0;
//	while (*str != '\0') {
//		str++;
//		count++;
//	}
//	return count;
//}
int mystrlen(char *str)
{
	if (*str == '\0') {
		return 0;
	}
	return 1 + mystrlen(str+1);
}
int main()
{
	printf("%d\n", mystrlen("nihao"));
	system("pause");
	return 0;
}
*/
/*
//递归和非递归分别实现求n的阶乘（不考虑溢出的问题）
//阶乘：3-3*2*1； 4 4*3*2*1  5-5*fac(4),  4 4*fac(3), 3*fac(2), 2*fac(1), 1
//int factorial(int n)
//{
//	int fac = 1;
//	for (int i = 1; i <= n; i++) {
//		fac *= i;
//	}
//	return fac;
//}
int factorial(int n)
{
	if (n == 1) {
		return 1;
	}
	return n*factorial(n-1);
}
int main()
{
	printf("%d", factorial(5));
	system("pause");
	return 0;
}
*/
/*
void print(int num)
{
	if (num < 10) {
		printf("%d ", num % 10);
		return;
	}
	print(num / 10);//先每次递归深入-- 6789->678->67->6
	printf("%d ", num % 10);
}
int main()
{
	print(6789);
	system("pause");
	return 0;
}
*/
/*
//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
void multiplication_tables(int n)
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d*%d=%d\t", i, j, i*j);
		}
		printf("\n");
	}
	return;
}
int main()
{
	multiplication_tables(20);
	system("pause");
	return 0;
}
*/
/*
//实现一个函数来交换两个整数的内容
void myswap(int *num1, int *num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}
int main()
{
	int a = 30, b = 50;
	printf("a=%d, b=%d\n", a, b);
	myswap(&a, &b);
	printf("a=%d, b=%d\n", a, b);
	system("pause");
	return 0;
}
*/
/*
//实现函数判断year是不是润年
int is_leap_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
		return 1;
	}
	return 0;
}
int main()
{
	for (int i = 1000; i <= 2000; i++) {
		if (is_leap_year(i) == 1) {
			printf("%d ", i);
		}
	}
	system("pause");
	return 0;
}
*/
/*
//实现一个函数，判断一个数是不是素数
//素数:只能被1和自身整除的数字
int is_prime(int num)
{
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}
int main()
{
	for (int i = 100; i <= 200; i++) {
		if (is_prime(i) == 1) {
			printf("%d ", i);
		}
	}
	system("pause");
	return 0;
}
*/
/*
//根据下面递归函数：调用函数Fun(2)，返回值是多少（ ）

int Fun(int n)
{
	if (n == 5)
		return 2;
	else
		return 2 * Fun(n + 1);
}
*/
/*
//编写代码在一个整形有序数组中查找具体的某个数
int binary_search(int arry[10], int size, int num)
{
	int idx_start = 0;
	int idx_end = size - 1;
	int idx_mid;
	while (idx_start <= idx_end){
		idx_mid = (idx_start + idx_end) / 2;
		if (num == arry[idx_mid]) {
			return idx_mid;
		}else if (num > arry[idx_mid]) {
			idx_start = idx_mid + 1;
		}
		else if (num < arry[idx_mid]) {
			idx_end = idx_mid - 1;
		}
	}
	printf("没有找到数据!\n");
	return -1;
}
int main()
{
	int arry[] = { 1, 2, 5, 6, 8, 10, 25, 27, 40, 56 };
	printf("25的下标:%d\n", binary_search(arry, 10, 25));
	system("pause");
	return 0;
}
*/
/*
int main()
{
	int a = 0, b = 0;
	for (a = 1, b = 1; a <= 100; a++)
	{
		if (b >= 20) break;//跳出循环
		if (b % 3 == 1)  1 4 7 10 13 16 19 22
		{
			b = b + 3;
			continue;
		}
		b = b - 5;
	}
	printf("%d\n", a);
	return 0;
}

int main()
{
	srand(time(NULL));
	int num = rand() % 100;
	while (1) {
		int input;
		printf("请输入你猜的数字: ");
		scanf("%d", &input);
		if (input > num) {
			printf("猜的太大了~\n");
			continue;
		}
		if (input < num) {
			printf("猜的太小了~\n");
			continue;
		}
		printf("你好厉害~\n");
		break;
	}
	system("pause");
	return 0;
}
*/
/*
int main()
{
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d * %d = %d\t", i, j, i*j);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
*/
/*
int main()
{
	int arry[] = { 1, 3, 2, 4, 6, 2, 4, 5, 8, 2 };
	int num = arry[0];
	int size = sizeof(arry) / sizeof(arry[0]);
	for (int i = 1; i < size; i++) { //i是数组的每个元素的下标
		if (num < arry[i]) { //使用num与i下标的元素进行比较
			num = arry[i];
		}
	}
	printf("%d\n", num);
	system("pause");
	return 0;
}
*/
/*
int main()
{
	int flag = 1;
	double sum = 0.0;
	for (int i = 1; i <= 100; i++) {
		sum += flag * 1.0 / i;
		flag = -flag;
	}
	printf("%f\n", sum);
	system("pause");
	return 0;
}
*/
/*
int main()
{
	int count = 0;
	for (int num = 1; num <= 100; num++) {
		if (num % 10 == 9)
			count++;
		if (num / 10 == 9)
			count++;
	}
	printf("9的个数：%d\n", count);
	system("pause");
	return 0;
}
*/
/*
int main()
{
	for (int num = 100; num <= 200; num++){
		int i;
		int res = (int)sqrt(num);
		for (i = 2; i <= res; i++){
			if (num % i == 0){
				break;//表示不是素数
			}
		}
		if (i == (res + 1)){
			printf("%d ", num);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
*/
/*
int main()
{
	for (int year = 1000; year <= 2000; year++){
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
			printf("%d ", year);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
*/
/*
int main()
{
	int a = 319, b = 377, c;
	printf("%d和%d的最大公约数：", a, b);
	while ((c = a % b) != 0){
		a = b;
		b = c;
	}
	printf("%d", b);
	system("pause");
	return 0;
}
*/
/*
int main()
{
	int num1 = 25, num2 = 20;
	int min = num1 > num2 ? num2 : num1;
	for (int i = min; i > 0; i--) {
		if (num1 % i == 0 && num2 % i == 0){
			printf("%d %d 的最大公约数：%d", num1, num2, i);
			break;//跳出循环
		}
	}
	system("pause");
}
*/
/*
//写一个代码打印1-100之间所有3的倍数的数字
int main()
{
	for (int i = 3; i <= 100; i += 3) {
		if (i % 3 == 0) {
			printf("%d ", i);
		}
	}
	system("pause");
	return 0;
}
*/


/*
//写代码将三个数按从大到小输出
int main()
{
	int a = 10, b = 20, c = 30, tmp = 0;
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	if (a < c) {
		tmp = a;
		a = c;
		c = tmp;
	}
	if (b < c) {
		tmp = b;
		b = c;
		c = tmp;
	}
	printf("%d %d %d\n", a, b, c);
	system("pause");
	return 0;
}
*/


/*
static int a = 20;
static void child()
{
	printf("this is child\n");
}
int main()
{
	const int n = 10;
	static int a = 10;
	char *a;
	printf("%d\n", sizeof(char*));
	child();
	system("pause");
	return 0;
}
*/
/*
#include <stdio.h>
int mymax(int num1, int num2){
	if (num1 > num2)
		return num1;
	return num2;
}
int main()
{
	printf("请输入两个数字，以空格间隔: ");
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	printf("较大值：%d\n", mymax(num1, num2));
	system("pause");
	return 0;
}
*/