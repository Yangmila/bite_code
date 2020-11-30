#include<stdio.h>
#include<string.h>
 
int Judge_string(char *str, char *p)
{
    if (strlen(str) != strlen(p))
    {
        return 0;
    }
    strncat(str, str, strlen(str));
    if (strstr(str, p) == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
 
}
int main()
{
    char str[20] = "abcd";
    char str1[] = "bcda";
    int ret = Judge_string(str, str1);
    if (0 == ret)
    {
        printf("str1不是str旋转后得到的！\n");
    }
    else
    {
        printf("str1是str旋转后得到的！\n");
    }

    return 0;
}
