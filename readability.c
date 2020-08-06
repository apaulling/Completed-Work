#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    float letters = 0;
    float words = 0;
    float sentences = 0;
    string text = get_string("Text: ");
    for (int p = 0, l = strlen(text); p < l; p++)
    {
        if (text[p] >= 65 && text[p] <= 90)
        {
//            the character is an uppercase letter
            letters++;
        }
        else if (text[p] >= 97 && text[p] <= 122)
        {
//            the character is a lowercase letter
            letters++;
        }
        else if (text[p] == 33 || text[p] == 46 || text[p] == 63)
        {
//            the character ends a sentence
            sentences++;
        }

        if (text[p - 1] == 32)
        {
//            the character is the start of a new word (character before it was a space)
            words++;
        }
    }
//    the first word will not have a space before it, so adding 1 to words makes up for this
    words++;
    float s = (sentences / words) * 100;
    float l = (letters / words) * 100;
    float grade = 0.0588 * l - 0.296 * s - 15.8;
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
//  if the grade is between 1 and 16 inclusive, round it to the nearest number, change it to an integer, and display it.
    else
    {
        printf("Grade %i\n", (int) round(grade));
    }
}