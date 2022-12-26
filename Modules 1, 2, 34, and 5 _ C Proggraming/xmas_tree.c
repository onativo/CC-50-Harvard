#include <stdio.h>

void tree(int);

int main()
{
    int height;

    printf("Qual a altura da pirâmide? \n A altura será: ");
    scanf("%d", &height);
    tree(height);
    return 0;
}
void tree(int height)
{
    int i, j;
    for(i = 1; i <= height; i++)
    {
        for(j = 1; j <= height - i; j++)
        {
            printf(" ");
        }
        for(j = 1;j <= 2 * i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}