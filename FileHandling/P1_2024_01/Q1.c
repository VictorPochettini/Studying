#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[18];
    int qtd;
    float custo;

} Registro;

void cria_arquivo()
{
    FILE* f = fopen("ferramentas.dat", "w");
    Registro reg;
    size_t size = sizeof(reg);
    reg.custo = 0;
    reg.nome[0] = '\0';
    reg.qtd = 0;

    fwrite(&reg, size, 100, f);

    fclose(f);
}

void insere_arquivo(char* argv[])
{
    unsigned int numero = atoi(argv[0]);

    Registro reg;
    strcpy(reg.nome, argv[1]);
    reg.qtd = atoi(argv[2]);
    int custo = atoi(argv[3]);
    size_t size = sizeof(reg);

    Registro reg1;
    FILE* f = fopen("ferramentas.dat", "r+");
    fseek(f, (size * numero), SEEK_SET);
    fread(&reg1, size, 1, f);
    if(reg1.nome[0] == '\0')
    {
        fseek(f, -size, SEEK_CUR);
        fwrite(&reg, size, 1, f);
    }
    else
    {
        printf("Erro. Registro já ocupado");
    }

    fclose(f);
}

void lista_ferramentas()
{
    size_t r1 = 1;
    size_t size = sizeof(Registro);
    Registro reg;
    FILE* f = fopen("ferramentas.dat", "rb");
    unsigned int qtdAcc = 0;
    unsigned int ferAcc = 0;

    while(r1 != 0)
    {
        r1 = fread(&reg, size, 1, f);
        qtdAcc += reg.qtd;
        ferAcc++;
        printf("%s", reg.nome);
    }

    printf("Número de ferramentas distintas: %d", ferAcc);
    printf("Número total de ferramentas: %d\n", qtdAcc);
}

int main(int argc, char* argv[])
{

    return 0;
}