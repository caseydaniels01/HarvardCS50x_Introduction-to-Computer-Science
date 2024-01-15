#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calc_words(string text)
{
    int words = 1;
    for(int i = 0, len = strlen(text); i < len; i++)
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
    for(int i = 0, len = strlen(text); i < len; i++)
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
    for(int i = 0, len = strlen(text); i < len; i++)
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

    string text = get_string("Text: ");

    int words = calc_words(text);
    int letters = calc_letters(text);
    int sent = calc_sent(text);
    float L = (((float)letters / (float)words)) * 100;
    float S = (((float)sent / (float)words)) * 100;
    float coleman = round(0.0588 * L - 0.296 * S - 15.8);

    //printf("words %d ... letters %d ... sentences %d ... L %d ... S %d...coleman %d\n", words, letters, sent, L, S, coleman);

    if (coleman < 1)
        {
           printf("Before Grade 1\n");
           exit(0);
        }
    else if( coleman > 15)
        {
           printf("Grade 16+\n");
           exit(0);
        }

    switch (coleman) {
        case 1:
            printf("Grade 1\n");
            break;

        case 2:
            printf("Grade 2\n");
            break;

        case 3:
            printf("Grade 3\n");
            break;

        case 4:
            printf("Grade 4\n");
            break;

        case 5:
            printf("Grade 5\n");
            break;

        case 6:
            printf("Grade 6\n");
            break;

        case 7:
            printf("Grade 7\n");
            break;

        case 8:
            printf("Grade 8\n");
            break;

        case 9:
            printf("Grade 9\n");
            break;

        case 10:
            printf("Grade 10\n");
            break;

        case 11:
            printf("Grade 11\n");
            break;

        case 12:
            printf("Grade 12\n");
            break;

        case 13:
            printf("Grade 13\n");
            break;

        case 14:
            printf("Grade 14\n");
            break;

        case 15:
            printf("Grade 15\n");
            break;
    }
    return 0;
}