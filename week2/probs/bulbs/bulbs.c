#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

long dec_to_bin(int letter);

int main(void)
{
    // TODO
    int length;
    string message;
    do
    {
        message = get_string("Message:  ");
        length = strlen(message);
    }
    while (length == 0);

    for (int i = 0; i < length; i++)
    {
        int dec = (int) message[i];
       	long binary = dec_to_bin(dec);
        int rBinary[BITS_IN_BYTE];
        for (int j = 1; j <= BITS_IN_BYTE; j++)
        {
            int digit = binary % 10;
    	    rBinary[BITS_IN_BYTE - j] = digit;
	        binary /= 10;
        }
    	for (int j = 0; j < BITS_IN_BYTE; j++)
    	{
    	    print_bulb(rBinary[j]);
    	}
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

long dec_to_bin(int dec)
{
    long binary = 0;
    int remainder = 0;
    int i = 1;

    while (dec != 0)
    {
        remainder = dec % 2;
        dec /= 2;
        binary += remainder * i;
        i *= 10;
    }
    return binary;
}

