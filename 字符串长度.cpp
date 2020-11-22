#include <stdio.h>

int nostrlen(char a[],int n)
{
	int i,count=0;
	for(i=0;i<n;++i)
	{
		while(a[i]!='\0')
		{
			count++;
		}
	}
	return count;
}
int main()
{
 	char a[]="hkdiausaod";
 	int n,count,count1;
 	n=sizeof(a)/sizeof(a[0]);
 	
 	count=nostrlen(a,n);
 	printf("非递归字符串长度为：%d",count);
 	 
 	return 0;
} 
