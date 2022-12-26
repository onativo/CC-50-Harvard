#include <stdio.h>
#include <cs50.h>

int main (void){
    string answ = get_string("Say your name: ");
    printf("oh... hello, %s", answ);
}