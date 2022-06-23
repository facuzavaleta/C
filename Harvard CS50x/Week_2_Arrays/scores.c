#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("Cuantos scores deseas anotar: ");
    int scores[n];
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        scores[i] = get_int("Score %i: ", i+1);
        sum += scores[i];
    }
    printf("Average: %f", sum / (float) n);
}