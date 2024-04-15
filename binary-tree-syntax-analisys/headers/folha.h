#ifndef FOLHA_H
#define FOLHA_H
#include "includes.h"

typedef struct Folha {
    char palavra[MAX_TAMANHO_PALAVRAS];
    struct Folha *folhaDireita;
    struct Folha *folhaEsquerda;
} Folha;

Folha *criarFolha(char palavra[MAX_TAMANHO_PALAVRAS], Folha *folhaDireita, Folha *folhaEsquerda);

#endif