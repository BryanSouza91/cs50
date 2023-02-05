#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int valid(string key);

void encrypt(string message, string key, int length);

int main(int argc, string argv[])
{
    // declare variables
    int length;
    string key, message, cipher;

    // check that program receieves only one key
    if ((argc < 2) || (argc > 2))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // store key from CMD line args
    key = argv[1];

    // check that key is a valid key
    if (!valid(key))
    {
        printf("Invalid key\nKey must contain 1 of each letter in the alphabet(26)\nKey is case-insensitive\n");
        return 1;
    }

    // get message to encrypt
    do
    {
        message = get_string("Message: ");
        length = strlen(message);
    }
    while (length <= 0);

    printf("Cipher:  ");
    encrypt(message, key, length);
}

int valid(string key)
{
    // check lwngth of key
    int keyLength = strlen(key);
    if (keyLength != 26)
    {
        return 0;
    }
    // check that each char is a letter
    for (int i = 0; i < keyLength; i++)
    {
        if (!isalpha(key[i]))
        {
            return 0;
        }
    }
    return 1;
}

void encrypt(string message, string key, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (isalpha(message[i]))
        {
            if (isupper(message[i]))
            {
                printf("%c", toupper(key[message[i] - 65]));
            }
            else if (islower(message[i]))
            {
                printf("%c", tolower(key[message[i]- 97]));
            }
        }
        else
        {
            printf("%c", message[i]);
        }
    }
    printf("\n");
}
