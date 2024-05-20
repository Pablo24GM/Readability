#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_sentences(string text);
int count_words(string text);
int Coleman_Liau_index(int letters, int sentences, int words);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int sentences = count_sentences(text);
    int words = count_words(text);
    int index = Coleman_Liau_index(letters, sentences, words);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}
int count_sentences(string text)
{
    int sentences = 0;
    for (int j = 0, n = strlen(text); j < n; j++)
    {
        if (text[j] == '.' || text[j] == '!' || text[j] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
int count_words(string text)
{
    int words = 0;
    for (int k = 0, n = strlen(text); k < n; k++)
    {
        if (isblank(text[k]))
        {
            words++;
        }
    }
    return words + 1;
}
int Coleman_Liau_index(int letters, int sentences, int words)
{
    float l = (float) letters / words * 100;
    float s = (float) sentences / words * 100;

    int index = round(0.0588 * l - 0.296 * s - 15.8);

    return index;
}
