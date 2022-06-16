#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int number = get_int("Tell me a number to check if it is even or odd: ");
    if (number % 2 == 0)
    {
        printf("It is even.\n");
    }
    else
    {
        printf("It is odd.\n");
    }
}