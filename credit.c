#include <stdio.h>
#include <cs50.h>

//placeholders
long num;
int l, digit, j;
int get_length(long value);
int hash(long value);
int get_digit(int pos, long value);

//end placeholders

int main(void)
{
    do
    {
        num = get_long("Number: ");
    }
    
    while (num <= 0);
    
//    printf("%i\n", get_length(num));
//    printf("%d", hash(num));
//    printf("%i", digit);
    if (get_length(num) == 15 && (get_digit(14, num) == 34 || get_digit(14, num) == 37) && hash(num) % 10 == 0)
    {
        printf("AMEX\n");
//        printf("%i %i %i", get_length(num), get_digit(14, num), hash(num));
    }
    else if (get_length(num) == 16 &&  get_digit(16, num) == 4 && hash(num) % 10 == 0)
    {
        printf("VISA\n");
//        printf("%i %i %i", get_length(num), get_digit(16, num), hash(num));
    }
    else if (get_length(num) == 13 &&  get_digit(13, num) == 4 && hash(num) % 10 == 0)
    {
        printf("VISA\n");
//        printf("%i %i %i", get_length(num), get_digit(13, num), hash(num));
    }
    else if (get_length(num) == 16 && get_digit(15, num) >= 51 && get_digit(15, num) <= 55 && hash(num) % 10 == 0)
    {
        printf("MASTERCARD\n");
//        printf("%i %i %i", get_length(num), get_digit(16, num), hash(num));
    }
    else
    {
        printf("INVALID\n");
//        printf("%i %i %i", get_length(num), get_digit(4, num), hash(num));
    }
}

int get_length(long value)
{
    l = 1;
    while (value > 9) // if input to function is over 10, divide by 10, ignore decimals
    {
        l++;
        value /= 10;
    }
    return l;
}

int get_digit(int pos, long value)
{
    long last = 1;
    for (j = 1; j < pos; j++)
    {
        last *= 10;
    }
    return value / last;
}

int hash(long value)
{
    int i = 1, sum = 0;
    long pwr = 10;
    digit = 0;
    while (i <= get_length(num))
    {
        digit = (value % pwr) / (pwr / 10);
        // printf("%d\n", digit);
        pwr *= 10;
//        printf("%i  -  ", digit);
        // factor time!
        if (i % 2 == 0)
        {
            digit = 2 * digit;

            if (digit > 9)
            {
                sum += digit % 10;
                sum += digit / 10;
            }
            else
            {
                sum += digit;
            }
//            printf("%i   -   %i\n", digit, sum);
        }
        else
        {
            sum += digit;
//            printf("%i   -   %i\n", digit, sum);
        }
        i++;
    }
//    printf("%i", sum);
    return sum;
}