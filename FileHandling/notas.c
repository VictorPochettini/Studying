#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct 
{ 
    int matricula; 
    float nota; 
} Registro;

void cria_arquivo(char *nome_arquivo)
{
    int fd = open(nome_arquivo, O_RDWR | O_CREAT);
    if(fd < 0) perror("Erro ao criar arquivo");
    int qtd;

    scanf("%d", &qtd);
    Registro buffer[qtd];

    for(int i = 0; i < qtd; i++)
    {
        scanf("%d", &buffer[i].matricula);
        scanf("%f", &buffer[i].nota);
    }

    write(fd, buffer, sizeof(Registro) * qtd);
}

void lista_registro(char *nome_arquivo)
{
    int fd = open(nome_arquivo, O_RDWR);

    if(fd < 0) perror("Erro ao abrir arquivo");
    
    size_t size = sizeof(Registro);
    struct stat st;
    fstat(fd, &st);
    size_t total_size = st.st_size;
    unsigned int quantidade = total_size/size;
    
    Registro buffer[quantidade];

    read(fd, buffer, total_size);

    for(int i = 0; i < quantidade; i++)
    {
        printf("%d", buffer[i].matricula);
        printf("%f", buffer[i].nota);
    }
}

FILE* busca_aluno(char* nome_arquivo, int matricula)
{
    int fd = open(nome_arquivo, O_RDWR);
    if (fd < 0) return NULL;

    struct stat st;
    if (fstat(fd, &st) < 0) {
        close(fd);
        return NULL;
    }
    
    size_t quantidade = st.st_size / sizeof(Registro);
    Registro *buffer = malloc(st.st_size);
    if (!buffer) {
        close(fd);
        return NULL;
    }
    
    if (read(fd, buffer, st.st_size) < 0) {
        free(buffer);
        close(fd);
        return NULL;
    }

    for(size_t i = 0; i < quantidade; i++)
    {
        if(buffer[i].matricula == matricula)
        {
            // Reposiciona o fd para o registro encontrado
            off_t posicao = i * sizeof(Registro);
            lseek(fd, posicao, SEEK_SET);
            
            FILE* f = fdopen(fd, "r+b");
            free(buffer);
            return f;
        }
    }

    free(buffer);
    close(fd);
    return NULL;
}

int main(int argc, char* argv)
{

    return 0;
}