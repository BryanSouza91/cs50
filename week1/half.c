#include <stdio.h>
#include <cs50.h>

float half(float bill, float tax, float tip);

int main(void)
{
    float subtotal = get_float("Bill before tax and tip:\t");
    float tax_rate = get_float("Sales Tax Rate:\t");
    float tip_rate = get_float("Tip Rate:\t");

    float total = half(subtotal, tax_rate, tip_rate);

    printf("You each pay $%.2f!\n", total);
}

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