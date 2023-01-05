#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //pede o número
    long num = get_long("Digite o número do  cartão: ");
    int i = 0;
    long cc = num;
    //divide por 10 pra saber quantos dígitos tem
    while(cc > 0)
    {
        cc = cc / 10;
        i++;
    }
    //se tem menos de 13, 14, ou mais de 16 dígitos, quebra o programa
    //só pode ser número com exatamente 13, 15 ou 16 dígitos
    if(i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    //calcular checksum
        //inicia as variáveis
    int sum1 = 0;
    int sum2 = 0;
    long x = num;
    int total = 0;
    int mod1;
    int mod2;
    int d1;
    int d2;

    do
    {
        //remove o último digito e adiciona a sum1
        mod1 = x % 10;
        x = x / 10;
        sum1 += mod1;

        //remove o segundo penúltimo dígito
        mod2 = x % 10;
        x = x / 10;

        //dobra o valor do segundo penúltimo e adiciona em sum2
        mod2 *= 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while(x > 0);

    total = sum1 + sum2;


    //verificando se o total passa no checksum do algoritmo de Luhn
    if(total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //verificando os primeiros digitos para saber a bandeira do cartão
    long start = num;
    do
    {
        start /= 10;
    }
    while (start > 100);

    //verificando a bandeira MAster
    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }

    //verficando bandeira Amex
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }

    //verificando por visa
    else if(start / 10 == 4)
    {
        printf("VISA\n");
    }

    //outra bandeira
    else
    {
        printf("INVALID\n");
    }
}