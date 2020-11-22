#include<stdio.h>
int int_cmp(const void* p1, const void* p2)
{
    return (*(int *)p1 > *(int *)p2);
}
void swap(void* p1, void* p2, int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        char tmp = *((char*)p1 + i);
        *((char*)p1 + i) = *((char*)p2 + i);
        *((char*)p2 + i) = tmp;
    }
}
void bubble(void* arr, int count, int size, int(*cmp)(void*, void*))
{
    int i = 0;
    int j = 0;
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (cmp((char*)arr + j * size, (char*)arr + (j + 1) * size) > 0)
            {
                swap((char*)arr + j * size, (char*)arr + (j + 1) * size, size);
            }
        }
    }
}
int main()
{
    int arr[] = { 1, 2, 3, 8, 9, 5, 4, 7, 6, 0 };
    int count = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    bubble(arr, count, sizeof(int), int_cmp);
    for (i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
