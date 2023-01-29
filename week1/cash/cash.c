#include <stdio.h>
#include <cs50.h>

#define between(x, a, b)  (((a) < (x)) && ((x) <= (b)))
#define outside(x, a, b)  (((x) < (a)) || ((b) < (x)))
int main(void)
{
    int c;
    do
    {
      c = get_int("Change Due:\t");
    }
    while (!between(c, 0, 99));
    if (c > 25)
    {
      int q = c / 25;
      printf("Quarters:\t%i\n", q);
      c %= 25;
    }
    if (c > 10)
    {
      int d = c / 10;
      printf("Dimes:\t%i\n", d);
      c %= 10;
    }
    if (c > 5)
    {
      int n = c / 5;
      printf("Nickels:\t%i\n", n);
      c %= 5;
    }
    if (c > 0)
    {
      int p = c / 1;
      printf("Pennies:\t%i\n", p);
      c %= 1;
    }
}
