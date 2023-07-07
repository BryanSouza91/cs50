#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int h = get_int("Height: ");
    draw(h);
}

void draw(int n)
{
    if (n <= 0)
    {
        return;
    }

    draw(n - 1);

    for (int i =0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}



