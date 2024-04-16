#ifndef ARVORE_H
#define ARVORE_H
#include "includes.h"

typedef struct Folha {
    char palavra[MAX_TAMANHO_PALAVRAS];
    struct Folha *folhaDireita;
    struct Folha *folhaEsquerda;
} Folha;

void inserirFolha(Folha **raiz, char palavra[MAX_TAMANHO_PALAVRAS]);
Folha* buscarPalavra(Folha *raiz, char palavra[MAX_TAMANHO_PALAVRAS]);

#endif