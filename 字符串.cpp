#include <stdio.h>
int main()
{ char *a="I love China!";
  char string[]="I love China!";
  printf("%d\n",sizeof(string));
  printf("%d\n",sizeof(a));
  printf("%s\n",string);
  printf("%s\n",string+7);

  printf("%s\n",a); 
  printf("%s\n",a+7); 
  
  //string[2]='L';
 // printf("%s\n",string);  
  
  a[2]='L';
  printf("%s\n",a); 
  
  
  return 0;
}


