#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int x = get_int("Insert a number: ");
    int y = get_int("Insert a number: ");
    
    printf("The division of these numbers are: %f.2f\n", (float)x * (float)y);
}