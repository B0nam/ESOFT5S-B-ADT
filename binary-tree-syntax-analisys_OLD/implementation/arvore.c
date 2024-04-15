#include "../headers/includes.h"

void inserirFolha(Folha **raiz, char palavra[MAX_TAMANHO_PALAVRAS])
{
    Folha *novaFolha = (Folha *)malloc(sizeof(Folha));
    strcpy(novaFolha->palavra, palavra);
    novaFolha->folhaDireita = NULL;
    novaFolha->folhaEsquerda = NULL;

    if (*raiz == NULL) {
        *raiz = novaFolha;
        return;
    }

    Folha *atual = *raiz;
    while (1) {
        if (strcmp(palavra, atual->palavra) < 0) {
            if (atual->folhaEsquerda == NULL) {
                atual->folhaEsquerda = novaFolha;
                break;
            } else {
                atual = atual->folhaEsquerda;
            }
        } else {
            if (atual->folhaDireita == NULL) {
                atual->folhaDireita = novaFolha;
                break;
            } else {
                atual = atual->folhaDireita;
            }
        }
    }
}

Folha* buscarPalavra(Folha *raiz, char palavra[MAX_TAMANHO_PALAVRAS]) {
    if (raiz == NULL || strcmp(raiz->palavra, palavra) == 0) {
        return raiz;
    }
    if (strcmp(palavra, raiz->palavra) < 0) {
        return buscarPalavra(raiz->folhaEsquerda, palavra);
    }
    return buscarPalavra(raiz->folhaDireita, palavra);
}
