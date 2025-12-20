#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ORDER 6
#define MAX_KEYS (ORDER - 1)
#define MIN_KEYS ((ORDER / 2) - 1)

typedef struct No {
    char CPF[MAX_KEYS][12];
    int posicao[MAX_KEYS];
    struct No* filhos[ORDER];
    int num_chaves;
    int eh_folha;
} No;

// Criar novo nó
No* criar_no(int eh_folha) {
    No* novo = (No*)malloc(sizeof(No));
    novo->num_chaves = 0;
    novo->eh_folha = eh_folha;
    
    for(int i = 0; i < MAX_KEYS; i++) {
        novo->CPF[i][0] = '\0';
        novo->posicao[i] = -1;
    }
    
    for(int i = 0; i < ORDER; i++) {
        novo->filhos[i] = NULL;
    }
    
    return novo;
}

// Buscar na árvore
int busca(No* no, char chave[12], int* posicao) {
    if(no == NULL) return 1;
    
    int i = 0;
    // Encontra a primeira chave maior ou igual
    while(i < no->num_chaves && strcmp(chave, no->CPF[i]) > 0) {
        i++;
    }
    
    // Chave encontrada
    if(i < no->num_chaves && strcmp(chave, no->CPF[i]) == 0) {
        *posicao = no->posicao[i];
        return 0;
    }
    
    // Se é folha, não encontrou
    if(no->eh_folha) {
        return 1;
    }
    
    // Busca recursiva no filho apropriado
    return busca(no->filhos[i], chave, posicao);
}

// Dividir filho cheio
void dividir_filho(No* pai, int i, No* filho_cheio) {
    No* novo_no = criar_no(filho_cheio->eh_folha);
    novo_no->num_chaves = MIN_KEYS;
    
    // Copia metade superior das chaves para novo nó
    for(int j = 0; j < MIN_KEYS; j++) {
        strcpy(novo_no->CPF[j], filho_cheio->CPF[j + MIN_KEYS + 1]);
        novo_no->posicao[j] = filho_cheio->posicao[j + MIN_KEYS + 1];
    }
    
    // Copia ponteiros dos filhos se não for folha
    if(!filho_cheio->eh_folha) {
        for(int j = 0; j <= MIN_KEYS; j++) {
            novo_no->filhos[j] = filho_cheio->filhos[j + MIN_KEYS + 1];
        }
    }
    
    filho_cheio->num_chaves = MIN_KEYS;
    
    // Move filhos do pai para abrir espaço
    for(int j = pai->num_chaves; j > i; j--) {
        pai->filhos[j + 1] = pai->filhos[j];
    }
    pai->filhos[i + 1] = novo_no;
    
    // Move chaves do pai para abrir espaço
    for(int j = pai->num_chaves - 1; j >= i; j--) {
        strcpy(pai->CPF[j + 1], pai->CPF[j]);
        pai->posicao[j + 1] = pai->posicao[j];
    }
    
    // Copia chave do meio para o pai
    strcpy(pai->CPF[i], filho_cheio->CPF[MIN_KEYS]);
    pai->posicao[i] = filho_cheio->posicao[MIN_KEYS];
    pai->num_chaves++;
}

// Inserir em nó não cheio
void inserir_nao_cheio(No* no, char chave[12], int pos) {
    int i = no->num_chaves - 1;
    
    if(no->eh_folha) {
        // Desloca chaves maiores para direita
        while(i >= 0 && strcmp(chave, no->CPF[i]) < 0) {
            strcpy(no->CPF[i + 1], no->CPF[i]);
            no->posicao[i + 1] = no->posicao[i];
            i--;
        }
        
        // Insere nova chave
        strcpy(no->CPF[i + 1], chave);
        no->posicao[i + 1] = pos;
        no->num_chaves++;
    } else {
        // Encontra filho onde inserir
        while(i >= 0 && strcmp(chave, no->CPF[i]) < 0) {
            i--;
        }
        i++;
        
        // Divide filho se estiver cheio
        if(no->filhos[i]->num_chaves == MAX_KEYS) {
            dividir_filho(no, i, no->filhos[i]);
            if(strcmp(chave, no->CPF[i]) > 0) {
                i++;
            }
        }
        
        inserir_nao_cheio(no->filhos[i], chave, pos);
    }
}

// Inserir na árvore
No* inserir(No* raiz, char chave[12], int pos) {
    if(raiz == NULL) {
        raiz = criar_no(1);
        strcpy(raiz->CPF[0], chave);
        raiz->posicao[0] = pos;
        raiz->num_chaves = 1;
        return raiz;
    }
    
    // Se raiz está cheia, divide
    if(raiz->num_chaves == MAX_KEYS) {
        No* nova_raiz = criar_no(0);
        nova_raiz->filhos[0] = raiz;
        dividir_filho(nova_raiz, 0, raiz);
        inserir_nao_cheio(nova_raiz, chave, pos);
        return nova_raiz;
    }
    
    inserir_nao_cheio(raiz, chave, pos);
    return raiz;
}

// Imprimir árvore (travessia em ordem)
void imprimir(No* no, int nivel) {
    if(no == NULL) return;
    
    printf("Nível %d: ", nivel);
    for(int i = 0; i < no->num_chaves; i++) {
        printf("%s(%d) ", no->CPF[i], no->posicao[i]);
    }
    printf("\n");
    
    if(!no->eh_folha) {
        for(int i = 0; i <= no->num_chaves; i++) {
            imprimir(no->filhos[i], nivel + 1);
        }
    }
}

// Liberar memória
void liberar(No* no) {
    if(no == NULL) return;
    
    if(!no->eh_folha) {
        for(int i = 0; i <= no->num_chaves; i++) {
            liberar(no->filhos[i]);
        }
    }
    
    free(no);
}

int main() {
    No* raiz = NULL;
    
    // Teste de inserção
    raiz = inserir(raiz, "12345678901", 100);
    raiz = inserir(raiz, "98765432109", 200);
    raiz = inserir(raiz, "11111111111", 300);
    raiz = inserir(raiz, "22222222222", 400);
    raiz = inserir(raiz, "33333333333", 500);
    raiz = inserir(raiz, "44444444444", 600);
    raiz = inserir(raiz, "55555555555", 700);
    
    printf("Árvore B:\n");
    imprimir(raiz, 0);
    
    // Teste de busca
    int posicao;
    if(busca(raiz, "22222222222", &posicao) == 0) {
        printf("\nCPF encontrado na posição: %d\n", posicao);
    } else {
        printf("\nCPF não encontrado\n");
    }
    
    liberar(raiz);
    return 0;
}