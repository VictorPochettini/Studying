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

    FILE* f = fopen("cep_ordenado.dat", "rb");
    Endereco e;

    fseek(f, 0, SEEK_END);
    int fim = ftell(f);
    int ini = 0;
    int meio = (fim + ini) / 2;
    fseek(f, meio, SEEK_SET);

    int qt = fread(&e, sizeof(Endereco), 1, f);


    while(qt > 0)
    {
        if(strncmp(e.cep, argv[1], 8) == 0)
        {
            printf("Encontrado\n");
            printf("%s\n%s\n%s\n%s", e.cidade, e.bairro, e.logradouro);
            break;
        }
        else if(e.cep > argv[1])
        {
            
        }
    }


    return 0;
}