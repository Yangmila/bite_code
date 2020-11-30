#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int cmp1(const void *a, const void *b)
{
    assert(a);
    assert(b);
    return (*(unsigned char *)a - *(unsigned char *)b);
}

int cmp2(const void *a, const void *b)
{
    assert(a);
    assert(b);
    return strcmp((char *)*(int *)a, (char *)*(int *)b);
}

int cmp3(const void *a, const void *b)
{
    assert(a);
    assert(b);
    return (*(unsigned int *)a - *(unsigned int *)b);;
}

int cmp4(const void *a, const void *b)
{
    assert(a);
    assert(b);
    return (((*(double *)a - *(double *)b) > 0) ? 1 : -1);
}

int main()
{
    int i = 0;
    char c[20] = "adicfjgheb";
    char *s[5] = { "aaa", "ddd", "iii", "ccc", "fff" };
    int a[10] = { 1, 3, 4, 5, 8, 0, 9, 7, 2, 6 };
    double b[10] = { 0.3, 1.7, 2.5, 0.1, 3.9, 2.1, 0.4, 0.2, 1.5, 2.3 };
    qsort(c, 10, sizeof(char), cmp1);
    qsort(s, 5, sizeof(char *), cmp2);
    qsort(a, 10, sizeof(int), cmp3);
    qsort(b, 10, sizeof(double), cmp4);
    for (i = 0; i < 10; i++)
    {
        printf("%c ", c[i]);
    }
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        printf("%s ", s[i]);
    }
    printf("\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (i = 0; i < 10; i++)
    {
        printf("%lf ", b[i]);
    }
    printf("\n");
    return 0;
}

