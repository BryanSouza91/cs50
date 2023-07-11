#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate get_candidate(string prompt);

int main(void)
{
    candidate pres = get_candidate("Enter a President: ");
    printf("%s\n", pres.name);
    printf("%d\n", pres.votes);

};

candidate get_candidate(string prompt)
{
    candidate c;

    printf("%s\n", prompt);

    c.name = get_string("Candidate Name: ");
    c.votes = get_int("Candidate Votes: ");

    return c;
}
