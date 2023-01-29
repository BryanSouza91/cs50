#include <cs50.h>
#include <stdio.h>

#define between(x, a, b)  (((a) <= (x)) && ((x) <= (b)))

int main(void) 
{
    int first2, c = 1, sum_a = 0, sum_b = 0, total = 0;
    long n;
    n = get_long("Number:\t");
    do
    {
        // printf("Counter:\t%i\n", c);
        int digit = n % 10;
        if (c % 2 == 0)
        {
            // printf("Digit:\t%i\n", digit);
            if (digit * 2 >= 10)
            {
                sum_a += (digit * 2 - 10);
                sum_a++;
                // printf("Sum_a:\t%i\n", sum_a);
            }
            else
            {
                sum_a += digit * 2;
                // printf("Sum_a:\t%i\n", sum_a);
            }
        }
        else
        {
            sum_b += digit;
        }
        c++;
        if (between(n, 10, 99))
        {
            first2 = n;
            // printf("%ld\n", n);
        }
    }
    while (n /= 10);
    total = sum_a + sum_b;
    if (total % 10 == 0)
    {
        switch (first2)
        {
            case 34:
                printf("AMEX\n");
                break;
            case 37:
                printf("AMEX\n");
                break;
            case 40:
                printf("VISA\n");
                break;
            case 51:
                printf("MASTERCARD\n");
                break;
            case 52:
                printf("MASTERCARD\n");
                break;
            case 53:
                printf("MASTERCARD\n");
                break;
            case 54:
                printf("MASTERCARD\n");
                break;
            case 55:
                printf("MASTERCARD\n");
                break;
            case 60:
                printf("DISCOVER\n");
                break;
        }
    }
    else
    {
        printf("INVALID\n");
    }
    // printf("Total:\t%i\nLast Digit:\t%i\n", total, total % 10);
}
