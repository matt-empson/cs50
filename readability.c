#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void calc_index(int letters, int sentences, int words);
int count_letters(string text);
int count_sentence(string text);
int count_words(string text);

int main(void)
{

    string text = get_string("Text: ");

    int letters = count_letters(text);
    int sentences = count_sentence(text);
    int words = count_words(text);

    calc_index(letters, sentences, words);

}

void calc_index(int letters, int sentences, int words)
{
   float index = 0.0588 * (letters * 100.0 / words) - 0.296 * (sentences * 100.0 / words) - 15.8;

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
       printf("Grade %i\n", (int) round(index));
   }

}

int count_letters(string text)
{
    int letterCount = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letterCount++;
        }
    }

    return letterCount;
}

int count_words(string text)
{
    int wordCount = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            wordCount++;
        }
    }

    return wordCount;
}

int count_sentence(string text)
{
    int sentenceCount = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentenceCount++;
        }
    }

    return sentenceCount;
}