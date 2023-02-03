#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt(string message, int length, int key);

int main(int argc, string argv[])
{
    // check that program receieves only one key
    while ((argc < 2) || (argc > 2))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = 0;
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        // check that program receives only numeric keys
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key(must be positive integer)\n");
            return 1;
        }
    }
    // convert ASCII to integer
    key = atoi(argv[1]);
    // xheck for non-zero key
    if (key <= 0)
    {
        printf("Usage: ./caesar key(must be positive integer)\n");
        return 1;
    }
    // printf("%i\n", key);

    int length;
    string message;
    // check for length of message
    do
    {
        message = get_string("Message: ");
        length = strlen(message);
    }
    while (length <= 0);

    printf("Cipher:  ");
    encrypt(message, length, key);
}

void encrypt(string message, int length, int key)
{
    // correct key for proper rotation
    if (key > 26)
    {
        key -= 26;
    }

    // iterate through message
    for (int i = 0; i < length; i++)
    {
        // only encrypt alphabetic chars
        if (isalpha(message[i]))
        {
            // check case of char
            if (isupper(message[i]))
            {
                int c = message[i] + key;
                // correct key for proper rotation
                if (c > 90)
                {
                    c = message[i] + key - 26;
                }
                // print encrypted char
                printf("%c", c);
            }
            // check case of char
            else if (islower(message[i]))
            {
                int c = message[i] + key;
                // correct key for proper rotation
                if (c > 122)
                {
                    c = message[i] + key - 26;
                }
                // print encrypted char
                printf("%c", c);
            }
        }
        // print character as is if not alphabetic
        else
        {
            printf("%c", message[i]);
        }
    }
    // print new line
    printf("\n");
}
