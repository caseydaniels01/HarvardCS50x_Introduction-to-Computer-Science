#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);

    // TODO: Prompt for end size

    int i;
    do
    {
        i = get_int("End size: ");
    }
    while (i < n);

    // TODO: Calculate number of years until we reach threshold

    int years = 0;

    if (n == i)
    {
        printf("Years: 0");
    }
    else
    {
        do
        {
            n = n + (n / 3) - (n / 4);
            years++;
        }
        while (n < i);

        // TODO: Print number of years

        printf("Years: %i\n", years);
    }
}