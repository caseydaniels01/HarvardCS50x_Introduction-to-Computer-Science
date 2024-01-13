#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int calc_points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calc(string word_check)
{
    int points = 0;
    for (int i = 0, len = strlen(word_check); i < len; i++)
    {
        // points += calc_points[word_check[i] - 'A'];
        //  printf("point %d ... Player 2: %c\n",points,word_check[i]);

        // THIS LOOP AVOIDS THE PUNCTUATION ISSUE, BECAUSE PUNCTUATION IS NEITHER UPPER OR LOWER, IGNORES PUNCTUATION ALL TOGETHER
        if (isupper(word_check[i]))
        {
            points += calc_points[word_check[i] - 'A'];
        }
        else if (islower(word_check[i]))
        {
            points += calc_points[word_check[i] - 'a'];
        }
    }
    return points;
}

void remove_punct(char *punct_check)
{
    // char j[100];
    int k = 0;
    for (int i = 0, len = strlen(punct_check); i < len; i++)
    {
        if (!ispunct(punct_check[i]))
        {
            {
                // punct_check[j++] = punct_check[i];
                // strcat(j[k], punct_check[i]);
                // punct_check[i] = j[i];
                punct_check[k] = punct_check[i];
                // printf("Punct Check: %d\n",punct_check[k]);
                k++;
            }
        }
        else
        {
            len--;
        }
        // punct_check[] = j[]
    }
}

int main(void)
{

    char first_word[100];
    // string first_word = get_string("Player 2: ");
    printf("Player 1: ");
    scanf("%s", first_word);
    // remove_punct(first_word);
    // int p1i = 0;
    //     while(first_word[p1i])
    //    {
    //     first_word[p1i] = toupper(first_word[p1i]);
    //    p1i++;
    // }

    char second_word[100];
    // string second_word = get_string("Player 2: ");
    printf("Player 2: ");
    scanf("%s", second_word);
    // remove_punct(second_word);

    //    int p2i = 0;
    //   while(second_word[p2i])
    //  {
    //     second_word[p2i] = toupper(second_word[p2i]);
    //    p2i++;
    //}

    int p1s = calc(first_word);
    int p2s = calc(second_word);

    if (p1s > p2s)
    {
        printf("Player 1 wins!\n");
        // printf("Player 1: %d ... Player 2: %d\n",p1s,p2s);
        // printf("Player 1: %s ... Player 2: %s\n",first_word,second_word);
    }
    else if (p1s < p2s)
    {
        printf("Player 2 wins!\n");
        // printf("Player 1: %d ... Player 2: %d\n",p1s,p2s);
        //  printf("Player 1: %s ... Player 2: %s\n",first_word,second_word);
    }
    else
    {
        printf("Tie!\n");
        // printf("Player 1: %d ... Player 2: %d\n",p1s,p2s);
        // printf("Player 1: %s ... Player 2: %s\n",first_word,second_word);
    }
}
