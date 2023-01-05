#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string key = argv[1];

    //verifica se tem 2 argumentos
    if (argc != 2)
    {
        printf("Use: ./ key\n");
        return 1;
    }
    else if (strlen(key) != 26)
    {
        printf("Chave deve conter 26 caracteres\n");
        return 1;
    }

    //verifica se a key é letra
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Uso: ./substitution key=letters_only\n");
        }
        break;
        return 1;
    }

    //verificando se cada letra da chave é única
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        for (int j = i + 1; j <= strlen(key); j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Uso: ./substitution unique_key\n");
                return 1;
            }
            if (tolower(key[i]) == tolower(key[j]))
            {
                printf("Uso: ./substitution unique_key\n");
                return 1;
            }
            if (!isalpha(key[i]))
            {
                printf("Uso: ./substitution unique_key\n");
                return 1;
            }
        }
    }

    string text = get_string("plaitext: ");
    printf("ciphertext: ");

    //converting characters in key to upper case
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (islower(key[i]))
        {
            key[i] = key[i] - 32;
        }
    }

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isupper(text[i]))
        {
            int letter = text[i] - 65;
            printf("%c", key[letter]);
        }
        else if (islower(text[i]))
        {
            int letter = text[i] - 97;
            printf("%c", key[letter] + 32);
        }
        else printf("%c", text[i]);
    }
    printf("\n");
}