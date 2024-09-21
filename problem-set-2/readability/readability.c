#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float x = 0.0588;
float y = 0.296;
float z = 15.8;

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int num_of_letters = count_letters(text);
    int num_of_words = count_words(text);
    int num_of_sentences = count_sentences(text);

    float average_letters = ((float) num_of_letters / num_of_words) * 100;
    float average_sentences = ((float) num_of_sentences / num_of_words) * 100;

    float index = x * average_letters - y * average_sentences - z;

    double grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int) grade);
    }
}

int count_letters(string text)
{
    int num_of_letters = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        char current_char = text[i];

        if (isalpha(current_char))
        {
            num_of_letters++;
        }
    }

    return num_of_letters;
}

int count_words(string text)
{
    int num_of_words = 1;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        char current_char = text[i];

        if (isspace(current_char))
        {
            num_of_words++;
        }
    }

    return num_of_words;
}

int count_sentences(string text)
{
    int num_of_sentences = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        char current_char = text[i];

        if (current_char == '.' || current_char == '!' || current_char == '?')
        {
            num_of_sentences++;
        }
    }

    return num_of_sentences;
}
