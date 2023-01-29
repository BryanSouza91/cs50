#include <cs50.h>
#include <stdio.h>

#define between(x, a, b)  (((a) < (x)) && ((x) <= (b)))

int main(void) 
{
    int first2, c = 1, sum_a = 0, sum_b = 0, total = 0;
    long n;
    n = get_long("Number:\t");
    do
    {
        int digit = n % 10;
        if (c % 2 == 0)
        {
            sum_a += digit * 2;
        }
        else
        {
            sum_b += digit;
        }
        c++;
        printf("%ld\n", n);
        if (between(n, 10, 100))
        {
            first2 = n;
        }
    }
    while (n /= 10);
    total += sum_a + sum_b;
    if (total % 10 == 0)
    {
        switch (first2)
        {
            case 34 | 37:
                printf("AMEX\n");
            case 40:
                printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    printf("Total:\t%i\nLast Digit:\t%i\n", total, total % 10);
}
