#include <cs50.h>
#include <stdio.h>

// helper function
#define between(x, a, b)  (((a) <= (x)) && ((x) <= (b)))

// global declaration to pass through functions
int first2;

// function declaration to validate CC Number Checksum
bool valid(long card_number);
// function declaration to identify CC provider
string identify_provider(int first2);

int main(void) 
{
    // request CC Number from user
    long cc_num = get_long("CC Number:\t");
    // validate CC Number
    if (valid(cc_num))
    {
        // if valid, identify provider
        printf("%s\n", identify_provider(first2));
    }
    else
    {
        printf("INVALID\n");
    } 
}

// Validates CC Number Checksum using Luhn's Algorithm
bool valid(long card_number)
{
    int c = 1, sum_a = 0, sum_b = 0, total = 0;
    do
    {
        // printf("Counter:\t%i\n", c);
        // iterate through cc number in reverse
        int digit = card_number % 10;
        // counter to keep track of iterations
        if (c % 2 == 0)
        {
            // printf("Digit:\t%i\n", digit);
            // adding the digits of the products to sum a
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
        // adding the other digits to sum b
        else
        {
            sum_b += digit;
        }
        // increment the counter
        c++;
        // capture the first 2 digits of the card to pass to provider identification function
        if (between(card_number, 10, 99))
        {
            first2 = card_number;
            // printf("%ld\n", card_number);
        }
    }
    while (card_number /= 10);
    // add sums of digits to validate checksum
    total = sum_a + sum_b;
    // printf("Total:\t%i\nLast Digit:\t%i\n", total, total % 10);
    if (total % 10 == 0)
    {
        return true;
    }
    return false;
}

// Identify CC Provider by checking the first 2 digits of the CC Number
string identify_provider(int first2)
{
    // Define various providers
    string a = "AMEX";
    string v = "VISA";
    string m = "MASTERCARD";
    string d = "DISCOVER";
    // determine provider and return name
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
