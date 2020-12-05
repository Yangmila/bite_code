#define N 7
#include <stdio.h>
int main()
{int a[N]={10,40,45,54,65,89,99},low,high,mid,x;
low = 0; high = N - 1;                
printf("请输入要查找的数");
scanf("%d",&x);    
while (low <= high)  
	{               
        mid = (low + high) / 2;  
		printf("low is %d mid is %d high is %d \n",low,mid,high); 
        if (x == a[mid])
            break;                    
        else if (x < a[mid])
            high = mid - 1;                  
        else       
            low = mid + 1;             
    }    
    if(low <= high)   
        printf("Index is %d \n",mid);
    else 
        printf( "Not Found\n");
    printf("low is %d mid is %d high is %d \n",low,mid,high);     
return 0;
}

