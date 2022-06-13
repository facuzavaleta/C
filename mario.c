// Mario right-alligned pyramid

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, i, j, k;

    do
    {
        // Prompt for input
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // For each row
    for (i = 0; i < height; i++)
    {
        // Spaces for each row
        for (j = height - 1; j > i; j--)
        {
            printf(" ");
        }
        // For each column
        for (k = 0; k < height + 1 - (height - i); k++)
        {
            printf("#");
        }
        printf("\n");
    }
}