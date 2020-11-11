#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float let = 0, word = 1, sent = 0, index;
int gl;

int main(void)
{
    string s = get_string("Text: ");
//    printf("Output: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //printf("%c", s[i]);
        if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            let++;
        }
        else if (s[i] == 32)
        {
            word++;
        }
        else if (s[i] == 33 || s[i] == 46 || s[i] == 63)
        {
            sent++;
        }
        
    }
    index = 0.0588 * let * (100 / word) - 0.296 * sent * (100 / word) - 15.8;
    //printf("%f\n", index);
    // printf("%i\n", word);
    // printf("%i\n", sent);
    gl = round(index);
    
    if (gl < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (gl > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", gl);
    }
}