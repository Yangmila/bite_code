#include <stdio.h>
swap(int  *p1, int  *p2)
{   int p;
    
    printf("\n�βε�ַ��%p,%p\n",p1,p2);
    printf("\np1��p2 ��ַ��%p,%p\n",&p1,&p2);
	printf("\n����ǰ�� %d,%d\n",*p1,*p2);
	p=*p1;
    *p1=*p2;
    *p2=p;
    printf("\n������%d,%d\n",*p1,*p2);
}
int main()
{   int a,b;
    int *pointer_1,*pointer_2;
    scanf("%d,%d",&a,&b);
    pointer_1=&a;  pointer_2=&b;
    
	printf("\nָ�������ַ��%p,%p\n",&pointer_1,&pointer_2);
	printf("\na��b�ĵ�ַ��%p,%p\n",&a,&b);
    printf("\nʵ�ε�ַ��%p,%p\n",pointer_1,pointer_2);
    
	if(a<b)swap(pointer_1,pointer_2);
    printf("\n%d,%d\n",a,b);
}

