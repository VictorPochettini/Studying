#include <stdio.h>
#include <string.h>

typedef struct _Endereco Endereco;

struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2]; // Ao Espaço no final da linha + quebra de linha
};

int main(int argc, char** argv)
{
    FILE* f = fopen("cep.dat", "r");
    char* CEP[8];
    Endereco e;
    int qt;
    int a = 1;

    if(f == NULL)
    {
        printf("Erro ao abrir arquivo");
        return 1;
    }

    qt = fread(&e, sizeof(Endereco), 1, f);

    while(qt > 0)
    {
        if(strncmp(e.cep, argv[1], 8) == 0)
        {
            printf("%s\n, %s\n, %s\n", e.cidade, e.bairro, e.logradouro);
            break;
        }

        a++;
        fread(&e, sizeof(Endereco), 1, f);
    }

    printf("CEP encontrado na posição: %d", a);

    return 0;
}