#include <stdio.h>

int contaLinhas(FILE *file)
{
    int acc = 0;
    char digito;
    while(digito = fgetc(file) != EOF)
    {
        if(digito == '\n')
        {
            acc++;
        }
    }

    return acc;
}

int contaChar(FILE *file)
{
    int caracteres[256];
    char digito;

    while(digito = fgetc(file) != EOF)
    {
        caracteres[digito]++;
    }

    return caracteres;
}



int main(int argc, char** argv)
{
    printf("%c", 7);

    FILE *file = fopen(argv, "r");

    if(!file)
    {
        fprintf(stderr, "Teu arquivo não existe meu");
        return 1;
    }

    fclose(file);

    return 0;
}
