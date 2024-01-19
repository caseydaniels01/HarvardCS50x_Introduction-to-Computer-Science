#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    if (argc != 2 || isdigit(*argv[1]) == 0 || argv < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int j = 0, len = strlen(argv[1]); j < len; j++)
    {
        if (isdigit(argv[1][j]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    printf("%i\n", key);

    string text = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            // text[i] = text[i + *argv[1]];
            char temp;
            // printf("%c\n",text[i]);
            temp = (text[i] - 65 + key) % 26 + 65;
            // printf("%c\n",text[i]);
            printf("%c", temp);
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            // text[i] = text[i + *argv[1]];
            char temp;
            // printf("%c\n",text[i]);
            temp = (text[i] - 97 + key) % 26 + 97;
            // printf("%c\n",text[i]);
            printf("%c", temp);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
