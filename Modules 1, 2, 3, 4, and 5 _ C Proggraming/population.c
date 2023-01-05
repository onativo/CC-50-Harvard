#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int final = 0;
    int year = 0;
    int start = 0;
    int end = 0;

    //pede um número da pop inicial maior/igual que 9, se for menor, repete o pedido
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    //pede um número da pop final maior que o inicial, se for menor, repete o pedido
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    while (start < end)
    {
        //nascem (start/3) lhamas e morrem (start/4) lhamas
        start = round(start + (start / 3) - (start / 4));

        //adiciona +1 ano
        year++;
    }

    printf("Final: %i\n", start);
    printf("Years: %i\n", year);

}