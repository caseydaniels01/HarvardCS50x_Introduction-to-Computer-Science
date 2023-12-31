#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

long check(long input)
{
    long check_one = input;
    long check_one_total = 0;

    while (check_one > 0)
    {
        long lastNumber = check_one / 10;
        long everyOther = check_one % 10;
        check_one = check_one / 100;
        check_one_total += everyOther;
    }

    long check_two = input / 10;
    long check_two_total = 0;
    int num = 0;

    while (check_two > 0)
    {
        long lastNumbertwo = check_two / 10;
        long everyOthertwo = (check_two % 10) * 2;

        num = everyOthertwo;
        while (num > 0)
        {
            int mod = num % 10;
            check_two_total += mod;
            num = num / 10;
        }
        check_two = check_two / 100;
    }

    long final_total = check_one_total + check_two_total;
    return final_total;
}

int main(void)
{

    long nDigits = 0;
    long input = 0;

    input = get_long("Number: ");

    nDigits = floor(log10(labs(input))) + 1;

    if (nDigits != 13 && nDigits != 15 && nDigits != 16)
    {
        printf("INVALID\n");
        exit(0);
    }

    int first_int = getFirstDigit(input);
    int two_first_int = getFirst2Digits(input);
    int check_num = check(input);

    char result[50] = "";

    if (check_num % 10 != 0)
    {
        strcpy(result, "INVALID\n");
    }
    else if (first_int == 4)
    {
        if (nDigits != 13 && nDigits != 16)
        {
            printf("INVALID\n");
            exit(0);
        }

        strcpy(result, "VISA\n");
    }
    else if (getFirst2Digits(input) == 34 || getFirst2Digits(input) == 37)
    {
        if (nDigits != 15)
        {
            printf("INVALID\n");
            exit(0);
        }

        strcpy(result, "AMEX\n");
    }
    else if (getFirst2Digits(input) == 51 || getFirst2Digits(input) == 52 || getFirst2Digits(input) == 53 ||
             getFirst2Digits(input) == 54 || getFirst2Digits(input) == 55)
    {
        if (nDigits != 16)
        {
            printf("INVALID\n");
            exit(0);
        }

        strcpy(result, "MASTERCARD\n");
    }
    else
    {

        printf("INVALID\n");
        exit(0);
    }

    printf("%s", result);
}