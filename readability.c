#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Ask for a text
    string text = get_string("Text: ");

    // Apply the secondary functions
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);

    // Determine L and S values
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;

    // Calculate index
    float index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade
    if (index > 16)
    {
        // printf("%f letters, %f words, %f sentences. L = %f, S = %f.\n", letters, words, sentences, L, S);
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        // printf("%f letters, %f words, %f sentences. L = %f, S = %f.\n", letters, words, sentences, L, S);
        printf("Before Grade 1\n");
    }
    else
    {
        // printf("%f letters, %f words, %f sentences. L = %f, S = %f.\n", letters, words, sentences, L, S);
        printf("Grade %i\n", (int) index);
    }
}

// Count letters
int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalnum(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}

// Count words
int count_words(string text)
{
    int words = 1;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            words += 1;
        }
    }
    return words;
}

// Count sentences
int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences += 1;
        }

    }
    return sentences;
}