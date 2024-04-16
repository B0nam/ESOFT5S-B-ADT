#ifndef ARVORE_H
#define ARVORE_H
#include "includes.h"

typedef struct Folha {
    char nome[MAX_TAMANHO_NOME];
    char telefone[MAX_TAMANHO_NOME];
    struct Folha *folhaDireita;
    struct Folha *folhaEsquerda;
} Folha;

void inserirFolha(Folha **raiz, char nome[MAX_TAMANHO_NOME], char telefone[MAX_TAMANHO_NUMERO]);
bool removerFolha(Folha **raiz, char nome[MAX_TAMANHO_NOME]);
Folha* buscarFolha(Folha *raiz, char nome[MAX_TAMANHO_NOME]);
void liberarArvore(Folha *raiz);
void imprimirContatos(Folha *raiz);

#endif