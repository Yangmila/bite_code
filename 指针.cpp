#include <stdio.h>
swap(int  *p1, int  *p2)
{   int p;
    
    printf("\n形参地址：%p,%p\n",p1,p2);
    printf("\np1和p2 地址：%p,%p\n",&p1,&p2);
	printf("\n交换前： %d,%d\n",*p1,*p2);
	p=*p1;
    *p1=*p2;
    *p2=p;
    printf("\n交换后：%d,%d\n",*p1,*p2);
}
int main()
{   int a,b;
    int *pointer_1,*pointer_2;
    scanf("%d,%d",&a,&b);
    pointer_1=&a;  pointer_2=&b;
    
	printf("\n指针变量地址：%p,%p\n",&pointer_1,&pointer_2);
	printf("\na和b的地址：%p,%p\n",&a,&b);
    printf("\n实参地址：%p,%p\n",pointer_1,pointer_2);
    
	if(a<b)swap(pointer_1,pointer_2);
    printf("\n%d,%d\n",a,b);
}

