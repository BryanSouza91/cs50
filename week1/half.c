#include <stdio.h>
#include <cs50.h>

// function declaration 
float half(float bill, float tax, float tip);

int main(void)
{
    // request information from the user
    float subtotal = get_float("Bill before tax and tip:\t");
    float tax_rate = get_float("Sales Tax Rate:\t");
    float tip_rate = get_float("Tip Rate:\t");

    // return half of bill to user
    printf("You each pay $%.2f!\n", half(subtotal, tax_rate, tip_rate));
}

// calculate tax add to bill
// calculate tip from bill w/tax and add to bill
// return half of bill 
float half(float bill, float tax, float tip)
{
    tax /= 100;
    tax *= bill;
    bill += tax;
    tip /= 100;
    tip *= bill;
    bill += tip;
    return bill / 2;
}