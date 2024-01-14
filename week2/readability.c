#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int calc_words(string text)
{
    int words = 1;
    for(int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

    return words;
}

int calc_letters(string text)
{
    int letters = 0;
    for(int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            continue;
        }
        else if (ispunct(i)!= 0)
        {
            continue;
        }
        else
        {
            letters++;
        }
    }

    return letters;
}

int calc_sent(string text)
{
    int sent = 0;
    for(int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sent++;
        }
    }

    return sent;
}

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int words = calc_words(text);
    int letters = calc_letters(text);
    int sent = calc_sent(text);

    int coleman =

    printf("words %d ... letters %d ... sentences %d\n", words, letters, sent);


    // Compute the Coleman-Liau index

    // Print the grade level
}

