#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start, end;
    do
    {
        start = get_int("Start:\t");
    }
    while (start <= 9);
    // TODO: Prompt for end size
    do
    {
        end = get_int("End:\t");
    }
    while (end < start);
    // TODO: Calculate number of years until we reach threshold
    int years = 0, pop = start, births, deaths;
    do
    {
       births =  pop / 3;
       deaths = pop / 4;
       pop += births;
       pop -= deaths;
       years++;
    }
    while (pop <= end);
    // TODO: Print number of years
    printf("Years:\t%i\nPopulation:\t%i\n", years, pop);
}
