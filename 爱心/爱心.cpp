

#include <graphics.h>
#include <conio.h>
#include <math.h>

//绘心形函数
//x0,y0,位置
//size:大小  
//COLORREF C：颜色
void heart(int x0, int y0, int size, COLORREF C)
{
	double  m, n, x, y; double i;
	for (i = 0; i <= 2*size; i = i + 0.01)		
	{
		//产生极坐标点
		m = i;
		n = -size * (((sin(i)*sqrt(fabs(cos(i)))) / (sin(i) + 1.4142)) - 2 * sin(i) + 2);
		//转换为笛卡尔坐标
		x = n*cos(m) + x0;
		y = n*sin(m) + y0;
		putpixel(x, y, C);
	}
}
void main()
{
	initgraph(640, 480);
	heart(300,150,80 ,RED);
	_getch();
	closegraph();
}
