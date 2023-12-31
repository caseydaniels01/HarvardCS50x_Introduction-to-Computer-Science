#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long getFirst2Digits(long input)
{
    long two_local = input;
    while (two_local >= 100)
    {
        two_local /= 10;
    }
    return two_local;
}

long getFirstDigit(long input)
{
    long one_local = input;
    while (one_local >= 10)
    {
        one_local /= 10;
    }
    return one_local;
}

int main(void)
{

long nDigits = 0;
long input = 0;

    do
    {
        printf("Number: ");
        scanf("%ld", &input);
        nDigits = floor(log10(labs(input))) + 1;
    }
    while( nDigits != 13 && nDigits != 15 && nDigits != 16 && nDigits != 4 );

    char Card;

    int first_int = getFirstDigit(input);
    printf("%d\n", first_int);
    int two_first_int = getFirst2Digits(input);
    printf("%d\n", two_first_int);


if(first_int == 4)
{
    Card = 'V';
    printf("VISA\n");
}
else if(getFirst2Digits(input) == 34 || getFirst2Digits(input) == 37 )
{
    Card = 'X';
    printf("AMERICAN EXPRESS\n");
}
else if(getFirst2Digits(input) == 51 || getFirst2Digits(input) == 52 || getFirst2Digits(input) == 53 || getFirst2Digits(input) == 54 || getFirst2Digits(input) == 55)
{
    Card = 'M';
    printf("MasterCard\n");
}
else
{
    Card = 'I';
    printf("INVALID\n");
}

}
