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

   // do
    //{
        printf("Number: ");
        scanf("%ld", &input);
        nDigits = floor(log10(labs(input))) + 1;
   //}
    //while( nDigits != 13 && nDigits != 15 && nDigits != 16 );

    if (nDigits != 13 && nDigits != 15 && nDigits != 16 )
        {
            printf("INVALID\n");
            exit(0);
        }

    char Card;

    int first_int = getFirstDigit(input);
    int two_first_int = getFirst2Digits(input);

long check_one = input;
long check_one_total = 0;

while(check_one > 0)
{
    long lastNumber = check_one / 10;
    long everyOther = check_one % 10;
    check_one = check_one / 100;
    check_one_total += everyOther;
}

//printf("%ld\n", check_one_total);

long check_two = input / 10;
long check_two_total = 0;

while(check_two > 0)
{
    long lastNumbertwo = check_two / 10;
    long everyOthertwo = (check_two % 10)*2;
    check_two = check_two / 100;
    check_two_total += everyOthertwo;
}

//printf("%ld\n", check_two_total);
long final_total = check_one_total + check_two_total;
//printf("%ld\n", final_total);

if(first_int == 4)
{
    Card = 'V';
    printf("VISA\n");
}
else if(getFirst2Digits(input) == 34 || getFirst2Digits(input) == 37 )
{
    Card = 'X';
    printf("AMEX\n");
}
else if(getFirst2Digits(input) == 51 || getFirst2Digits(input) == 52 || getFirst2Digits(input) == 53 || getFirst2Digits(input) == 54 || getFirst2Digits(input) == 55)
{
    Card = 'M';
    printf("MASTERCARD\n");
}
else
{
    Card = 'I';
}

if(final_total % 10 != 0)
{
    Card = 'I';
}

if( Card == 'I')
{
    printf("INVALID\n");
}

}
