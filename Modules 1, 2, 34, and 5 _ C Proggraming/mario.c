#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        printf("Qual a altura da pirâmide? \n A altura será: ");
        scanf("%d", &height);

    }
    while (height < 1 || height > 8);

    for (int row = 0; row < height; row++)
    {
        for (int j = 0; j < height; j++)
        {
            if(row + j < height - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  #");
        for (int j = 0; j < height; j++)
        {
            if(row + j > height - 1)
            {
                printf("#");
            }
        }
    printf("\n");
    }
}