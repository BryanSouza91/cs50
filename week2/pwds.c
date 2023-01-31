#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool upper = false, lower = false, num = false, sym = false;
    int length = strlen(password);
    for (int i = 0; i < length; i++)
    {
        if (isupper(password[i]))
        {
            upper = true;
        }
        else if (islower(password[i]))
        {
            lower = true;
        }
        else if (isdigit(password[i]))
        {
            num = true;
        }
        else if (ispunct(password[i]))
        {
            sym = true;
        }
        if ((upper) && (lower) && (num) && (sym))
        {
            return true;
        }
    }
    return false;
}
