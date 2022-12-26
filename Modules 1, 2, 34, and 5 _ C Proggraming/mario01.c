#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int size = 0;
    do
    {
        size = get_int("Qual a altura da pirâmide? \n A altura será: ");
    }
    while(size < 0 || size > 8);
    for(int i = 0; i <= size; i++)
        {
            for(int j = 0;j < i; j++)
            {
                printf("#");
            }
            printf("\n");
        }
}