#include <stdio.h>
int main()
{ float average(float array[10]); 
   float score[10],aver;  int i;
   printf("%d\n",score);
   printf("%d\n",sizeof(score));
   printf("input 10 scores:\n");
   for(i=0;i<10;i++)
      printf("%d ",&score[i]);
     for(i=0;i<10;i++)
      scanf("%f",&score[i]);  
   printf("\n");
   aver=average(score); 
   printf("aver %5.2f\n",aver);
   return 0;} 
float average(float array[10])
{  int i;
    float aver,sum=0;
     
	printf("%d\n",array);
	printf("%d\n",sizeof(array));
    for(i=0;i<10;i++)
      printf("%d ",&array[i]); 
	for(i=0;i<10;i++)
       sum=sum+array[i]; 
    aver=sum/10;
    return(aver);
}

