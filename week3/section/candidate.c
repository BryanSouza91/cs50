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
    candidate candidates[3];
    for (int i = 0; i < 3; i++)
    {
        candidates[i] = get_candidate("Enter Candidate: ");
    }

};

candidate get_candidate(string prompt)
{
    candidate c;

    printf("%s\n", prompt);

    c.name = get_string("Candidate Name: ");
    c.votes = get_int("Candidate Votes: ");

    return c;
}
