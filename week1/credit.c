#include <cs50.h>
#include <stdio.h>

#define between(x, a, b)  (((a) <= (x)) && ((x) <= (b)))

int first2;

bool valid(long card_number);
string identify_provider(int first2);

int main(void) 
{
    long cc_num = get_long("CC Number:\t");
    if (valid(cc_num))
    {
        printf("%s\n", identify_provider(first2));
    }
    else
    {
        printf("INVALID\n");
    } 
}

bool valid(long card_number)
{
    int c = 1, sum_a = 0, sum_b = 0, total = 0;
    do
    {
        // printf("Counter:\t%i\n", c);
        int digit = card_number % 10;
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
        if (between(card_number, 10, 99))
        {
            first2 = card_number;
            // printf("%ld\n", card_number);
        }
    }
    while (card_number /= 10);
    total = sum_a + sum_b;
    // printf("Total:\t%i\nLast Digit:\t%i\n", total, total % 10);
    if (total % 10 == 0)
    {
        return true;
    }
    return false;
}

string identify_provider(int first2)
{
    string a = "AMEX";
    string v = "VISA";
    string m = "MASTERCARD";
    string d = "DISCOVER";
    switch (first2)
    {
        case 34:
            return a;
        case 37:
            return a;
        case 40:
            return v;
        case 51:
            return m;
        case 52:
            return m;
        case 53:
            return m;
        case 54:
            return m;
        case 55:
            return m;
        case 60:
            return d;
    }   
    return "NO MATCH";   
}
