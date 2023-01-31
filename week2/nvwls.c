#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Usage: ./nvwls words\n");
        return 1;
    }
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j] != 0; j++)
        {
            switch (argv[i][j])
            {
                case 'a':
                    argv[i][j] = '6';
                    break;
                case 'i':
                    argv[i][j] = '1';
                    break;
                case 'e':
                    argv[i][j] = '3';
                    break;
                case 'o':
                    argv[i][j] = '0';
                    break;
            }
        }
        printf("%s ", argv[i]);
    }
    printf("\n");
}
