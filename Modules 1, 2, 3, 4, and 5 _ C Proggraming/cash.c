#include <stdio.h>
#include <cs50.h>
#include <math.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main (void)
{
    //pergunta qual o troco
    float cents = get_cents();

    //calcula quantas moedas de 25
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    //calcula quantas moedas de 10
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;


    //calcula quantas moedas de 5
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    //calcula quantas moedas de 1
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;


    //calcula o número total de moedas
    int coins = quarters + nickels + dimes + pennies;

    printf("%f\n", round(coins));
}

int get_cents(void)
{
    float cents;
    do
    {
        cents = get_float("Valor: ");
    }
    while (cents < 0);

    return round(cents*100);
}

int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        cents = cents - 25;
        quarters++;
    }
    return quarters;
}
int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        cents = cents - 10;
        dimes++;
    }
    return dimes;
}
int calculate_nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5)
    {
        cents = cents - 5;
        nickels++;
    }
    return nickels;
}
int calculate_pennies(int cents)
{
    int pennies = 0;
    while (cents >= 1)
    {
        cents = cents - 1;
        pennies++;
    }
    return pennies;
}