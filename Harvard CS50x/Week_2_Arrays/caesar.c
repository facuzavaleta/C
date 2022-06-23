#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string cipher(string plaintext, int key);

int main(int argc, string argv[])
{
    // Check if one argument in command line
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Key
    string n = argv[1];

    // Check if digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Get plaintext
    string plaintext = get_string("Plaintext: ");
    int key = atoi(n);

    // Get ciphertext and print it
    printf("Ciphertext: ");

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 65) + key) % 26) + 65);
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 97) + key) % 26) + 97);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}