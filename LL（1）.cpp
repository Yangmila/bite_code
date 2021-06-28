#include <stdio.h>
#include <stdlib.h>
 
char str[100];
int num=0;
int cur=0;
void E();
void E1();
void T();
void T1();
void F();
void T1()
{
    if(str[cur]=='*')
    {
        printf("%d T'-->*FT'\n",num++);
        cur++;
        F();
        T1();
    }
    else
    {
        printf("%d T'-->&\n",num++);
    }
}
void E1()
{
    if(str[cur]=='+')
    {
        printf("%d E'-->+TE'\n",num++);
        cur++;
        T();
        E1();
    }
    else
        printf("%d E'-->&\n",num++);
}
void F()
{
    if(str[cur]=='i')
    {
        printf("%d F-->i\n",num++);
        cur++;
    }else if(str[cur]=='(')
             {
                 printf("%d F-->(E)\n",num++);
                 cur++;
                 E();
                 if(str[cur]==')')
                 {
                     cur++;
                 }
                 else
                 {
                     printf("error\n");
                     exit(0);
                 }
             }else
             {
                 printf("error\n");
                 exit(0);
             }
}
void T()
{
    if(str[cur]=='i'||str[cur]=='(')
    {
        printf("%d T-->FT'\n",num++);
        F();
        T1();
    }
    else
    {
        printf("error\n");
        exit(0);
    }
}
void E()
{
    if(str[cur]=='i'||str[cur]=='(')
    {
        printf("%d E-->TE'\n",num++);
        T();
        E1();
    }else
    {
        printf("error\n");
        exit(0);
    }
 
}
int main()
{
   scanf("%s",str);
   E();
   if(str[cur]!='#')
   {
       printf("error\n");
   }
   else
    printf("accept\n");
    return 0;
}

