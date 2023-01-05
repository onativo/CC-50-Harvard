#include <stdio.h>
#include <cs50.h>

int main (void)
{
    //inicializa variavel size
    int size;
    int spaces;
    int hash;

    //pede por entrada
    do
    {
        size = get_int("Qual a altura da pirâmide? \n A altura será: ");
    }
    //enquanto entrada não for entre 1 e 8, repete o DO
    while(size < 0 || size > 8);

    for(int i = 0; i < size; i++)
        {
            //loop de imprimir os espaços em branco
            for(spaces = (size -i); spaces >= 2 ; spaces --)
            {
                printf(" ");
            }
            //loop de criar os hastags
            for(hash = 1; hash <= (i + 1); hash++)
            {
                printf("#");
            }
            printf("\n");
        }
}