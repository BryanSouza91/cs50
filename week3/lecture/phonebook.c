#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];
    people[0].name = "Bryan";
    people[0].number = "+1-999-555-0101";
    printf("%s: %s\n", people[0].name, people[0].number);
}
