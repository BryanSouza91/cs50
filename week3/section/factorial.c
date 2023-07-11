#include <cs50.h>
#include <stdio.h>

int factorial(int num);

int main(void)
{
    // Print a prompt for nunber input
    int n = get_int("Enter number: ");
    printf("%d\n", factorial(n));
}

int factorial(int num)
{
    if (num == 1)
    {
        return 1;
    }

    return num * factorial(num - 1);
}


