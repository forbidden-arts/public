#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int shift, c;

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        for (int i = 0, len = strlen(argv[1]); i < len; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            else
            {
                shift = atoi(argv[1]);  // convert to integer
            }
        }
    }
    // printf("%i", shift); //
    string plaintext = get_string("plaintext:  ");
    // printf("%c", plaintext[0] + shift);  // works!
    
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            if ((plaintext[i] + shift % 26) > 90)
            {
                printf("%c", plaintext[i] + (shift % 26) - 26);
            }
            else
            {
                printf("%c", plaintext[i] + (shift % 26));
            }
        }
        else if (plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            if ((plaintext[i] + shift % 26) > 122)
            {
                printf("%c", plaintext[i] + (shift % 26) - 26);
            }
            else
            {
                printf("%c", plaintext[i] + (shift % 26));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}