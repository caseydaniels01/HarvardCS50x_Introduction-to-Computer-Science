#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int calc_points[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int calc(string word_check)
{
    int points = 0;
    for (int i = 0, len = strlen(word_check); i < len; i++)
    {
        points += calc_points[word_check[i] - 'A'];
    }
    return points;
}

char remove_punct(string punct_check)
{
    char* word[100];
    for (int i = 0, len = strlen(punct_check); i < len; i++)
    {
        if(ispunct(i)== 0)
         {
            word[i] = (char)punct_check[i];
         }
    }
    return word;
}

int main(void)
{

char first_word_unchecked[100];
char first_word[100];
printf("Player 1: ");
scanf("%s", first_word_unchecked);
char first_word = remove_punct(first_word_unchecked);
char first_word_upper[100];
int p1i = 0;
    while(first_word[p1i])
    {
      first_word[p1i] = toupper(first_word[p1i]);
      p1i++;
    }

char second_word[100];
printf("Player 2: ");
scanf("%s", second_word);

    int p2i = 0;
    while(second_word[p2i])
    {
        second_word[p2i] = toupper(second_word[p2i]);
        p2i++;
    }

int p1s = calc(first_word);
int p2s = calc(second_word);

if ( p1s > p2s)
{
    printf("Player 1 wins!\n");
}
else if ( p1s < p2s)
{
    printf("Player 2 wins!\n");
}
else
{
    printf("Tie!\n");
}

}
