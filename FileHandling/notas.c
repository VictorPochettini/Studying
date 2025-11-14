#include <stdio.h>

typedef struct
{
    int matricula;
    float nota;
} Registro;

void criaArquivo()
{
    FILE* file = fopen("registro.txt", "wb");

    if(!file)
    {
        return;
    }

    int qtd;
    int size = sizeof(Registro);

    scanf("%d", &qtd);

    Registro reg[qtd];

    for(int i = 0; i < qtd; i++)
    {
        scanf("%d", &reg[i].matricula);
        scanf("%f", &reg[i].nota);

        fwrite(&reg[i], size, 1, file);
    }

    fclose(file);
}

void listaRegistro()
{

}

void buscaAluno()
{

}

void atualizaNota()
{

}

void geraArqAprovados()
{

}

void ordenaMatricula()
{

}

int main(int argc, char *argv[])
{
    int option;

    scanf("%d", &option);

    switch(option)
    {
        case 1:
            criaArquivo();
        case 2:
            listaRegistro();
        case 3:
            buscaAluno();
        case 4:
            atualizaNota();
        case 5:
            geraArqAprovados();
        case 6:
            ordenaMatricula();
    }

    return 0;
}