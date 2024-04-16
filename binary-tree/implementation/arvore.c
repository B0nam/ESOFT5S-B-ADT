#include "../headers/includes.h"

void inserirFolha(Folha **raiz, char nome[MAX_TAMANHO_NOME], char telefone[MAX_TAMANHO_NUMERO])
{
    Folha *novaFolha = (Folha *)malloc(sizeof(Folha));
    if (novaFolha == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    strcpy(novaFolha->nome, nome);
    strcpy(novaFolha->telefone, telefone);
    novaFolha->folhaEsquerda = NULL;
    novaFolha->folhaDireita = NULL;

    if (*raiz == NULL) {
        *raiz = novaFolha;
        return;
    }

    Folha *atual = *raiz;
    while (1) {
        if (strcmp(nome, atual->nome) < 0) {
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

bool removerFolha(Folha **raiz, char nome[MAX_TAMANHO_NOME])
{
    Folha *pai = NULL;
    Folha *atual = *raiz;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        pai = atual;
        if (strcmp(nome, atual->nome) < 0) {
            atual = atual->folhaEsquerda;
        } else {
            atual = atual->folhaDireita;
        }
    }

    if (atual == NULL) {
        return false;
    }

    if (atual->folhaEsquerda == NULL && atual->folhaDireita == NULL) {
        if (pai == NULL) {
            *raiz = NULL;
        } else if (pai->folhaEsquerda == atual) {
            pai->folhaEsquerda = NULL;
        } else {
            pai->folhaDireita = NULL;
        }
        free(atual);
    }
    else if (atual->folhaEsquerda == NULL || atual->folhaDireita == NULL) {
        Folha *filho = (atual->folhaEsquerda != NULL) ? atual->folhaEsquerda : atual->folhaDireita;
        if (pai == NULL) {
            *raiz = filho;
        } else if (pai->folhaEsquerda == atual) {
            pai->folhaEsquerda = filho;
        } else {
            pai->folhaDireita = filho;
        }
        free(atual);
    }
    else {
        Folha *sucessor = atual->folhaDireita;
        while (sucessor->folhaEsquerda != NULL) {
            sucessor = sucessor->folhaEsquerda;
        }
        strcpy(atual->nome, sucessor->nome);
        strcpy(atual->telefone, sucessor->telefone);
        removerFolha(&atual->folhaDireita, sucessor->nome);
    }
    return true;
}

Folha* buscarContato(Folha *raiz, char nome[MAX_TAMANHO_NOME])
{
    Folha *atual = raiz;
    while (atual != NULL) {
        if (strcmp(nome, atual->nome) == 0) {
            return atual;
        } else if (strcmp(nome, atual->nome) < 0) {
            atual = atual->folhaEsquerda;
        } else {
            atual = atual->folhaDireita;
        }
    }
    return NULL;
}

void liberarArvore(Folha *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->folhaEsquerda);
        liberarArvore(raiz->folhaDireita);
        free(raiz);
    }
}

void imprimirContatos(Folha *raiz) {
    if (raiz != NULL) {
        imprimirContatos(raiz->folhaEsquerda);
        printf("Nome: %s, Telefone: %s\n", raiz->nome, raiz->telefone);
        imprimirContatos(raiz->folhaDireita);
    }
}