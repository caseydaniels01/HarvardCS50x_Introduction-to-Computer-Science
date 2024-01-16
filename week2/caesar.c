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
        return false;
    }

    int key = atoi(argv[1]);
    //printf("%i\n",key);

    string text = get_string("plaintext: ");

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            text[i] = text[i + *argv[1]];
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            text[i] = text[i + *argv[1]];
        }
    }

    printf("ciphertext: %s\n",text);

}
