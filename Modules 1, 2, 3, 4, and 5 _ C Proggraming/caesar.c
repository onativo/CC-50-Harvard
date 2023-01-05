#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key");
            return 1;
        }
    }
    
    int key = atoi(argv[1]);

    string text = get_string("plaitext: ");
    printf("ciphertext: ");

    for (int j = 0; j < strlen(text); j++)
    {
        if (isupper(text[j]))
        {
            printf("%c", (text[j] - 65 + key) % 26 + 65);
        }
        else if (islower(text[j]))
        {
            printf("%c", (text[j] - 97 + key) % 26 + 97);
        }
        else
        {
            printf("%c", text[j]);
        }
    }
    printf("\n");
}