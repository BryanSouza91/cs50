#include <stdio.h>
#include <cs50.h>

#define outside(x, a, b)  (((x) < (a)) || ((b) < (x)))

int main(void)
{
    int p;
    do
    {
        p = get_int("Pyramid size:\t");
    }
    while (outside(p, 1, 4));

    for (int i = 0; i < p; i++)
    {
        switch (i)
        {
          case 0:
            printf("   # #   \n");
            break;
          case 1:
            printf("  ## ##  \n");
            break;
          case 2:
            printf(" ### ### \n");
            break;
          case 3:
            printf("#### ####\n");
            break;
        }
    }
}
