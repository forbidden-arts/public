#include <stdio.h>
#include <cs50.h>

//Fake call later functions
void prsp(int n);
void prha(int n);
int height;

int main(void)
{
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    for (int i = 1; i <= height; i++)
    {
        prsp(height - i);
        prha(i);
        prsp(2);
        prha(i);
        //prsp(height - i);  get rid of trailing whitespace
        printf("\n");
    }
}

void prsp(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void prha(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}