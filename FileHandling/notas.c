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
    FILE* f = fopen("registro.txt", "rb");

    if(!f)
    {
        return;
    }

    size_t r1;
    int size = sizeof(Registro);
    Registro reg;
    r1 = fread(&reg, size, 1, f);

    while(r1 == 1)
    {
        printf("===================================================\n");
        printf("Matrícula:\t%d\n", reg.matricula);
        printf("Nota:\t%f\n", reg.nota);
        r1 = fread(&reg, size, 1, f);
    }

    fclose(f);
}

FILE* buscaAluno()
{
    FILE* f = fopen("registro.txt", "rb");

    if(!f)
    {
        return;
    }

    Registro reg;
    int matricula;
    int encontrado = 0;
    int size = sizeof(Registro);
    size_t r1;
    scanf("%d", &matricula);

    r1 = fread(&reg, size, 1, f);

    while(r1 == 1)
    {
        if(matricula == reg.matricula)
        {
            printf("Encontrado!");
            encontrado = 1;
            break;
        }
        r1 = fread(&reg, size, 1 ,f);
    }

    if(!encontrado)
        printf("Não encontrado");

    return f;
}

void atualizaNota()
{
    FILE* f = buscaAluno();
    Registro reg;
    int size = sizeof(Registro);
    fread(&reg, size, 1, f);
    fseek(f, -size, SEEK_CUR);

    scanf("%d", &reg.nota);

    fwrite(&reg, size, 1, f);

    fclose(f);
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