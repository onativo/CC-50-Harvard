#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

#define BLOCKSIZE 512

int inputError()
{
    printf("usage: ./recover image\n");
    return 1;
}

int main(int argc, char *argv[])
{
    //checa argumentos da linha de comando
    if (argc != 2)
    {
        return inputError();
    }

    //abre o arquivo passado na linha de comando
    FILE *inFile = fopen(argv[1], "r");

    //checa se o arquivo passado é válido
    if (inFile == NULL)
    {
        return inputError();
    }

    //armazena blocos de 520 bytes
    unsigned char buffer [512];

    //conta o número de imagens geradas
    int imgCount = 0;

    //filepointer para as imagens recuperadas
    FILE *outFile = NULL;

    //separa um espaço para o filename
    char *fName = malloc(8 * sizeof(char));

    //lê os blocos de 512 bytes
    while (fread(buffer, sizeof(char), 512, inFile))
    {
        //checa se os bytes correspondem a assinaturas de jpegs
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (imgCount > 0)
            {
                fclose(outFile);
            }
            //escreve o arquivo jpeg
            sprintf(fName, "%03i.jpg", imgCount);

            //cria arquivo de saída
            outFile = fopen(fName, "w");


            imgCount++;
        }
        if (outFile != NULL)
        {
            fwrite(buffer, sizeof(char), 512, outFile);
        }

    }

    fclose(outFile);
    fclose(inFile);
    free(fName);

    return 0;

}