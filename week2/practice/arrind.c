#include <stdio.h>

int main(void)
{
    int arr[100];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = i;
    }
    printf("arr[99] is %i\n", arr[99]);
}
