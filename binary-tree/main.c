#include "headers/includes.h"
#include "implementation/arvore.c"

void limpar(Folha *raiz) {
    liberarArvore(raiz);
}

int main(void)
{
    printf("\n--- Programa Iniciado ---\n\n");

    Folha *raiz = NULL;

    int opcao;
    char nome[MAX_TAMANHO_NOME];
    char telefone[MAX_TAMANHO_NUMERO];

    do {
        printf("Menu:\n");
        printf("1. Adicionar contato\n");
        printf("2. Remover contato\n");
        printf("3. Buscar contato\n");
        printf("4. Visualizar todos os contatos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do contato: ");
                scanf("%s", nome);
                printf("Digite o telefone do contato: ");
                scanf("%s", telefone);
                inserirFolha(&raiz, nome, telefone);
                printf("Contato adicionado com sucesso!\n");
                break;
            case 2:
                printf("Digite o nome do contato a ser removido: ");
                scanf("%s", nome);
                if (removerFolha(&raiz, nome)) {
                    printf("Contato removido com sucesso!\n");
                } else {
                    printf("Contato nao encontrado!\n");
                }
                break;
            case 3:
                printf("Digite o nome do contato a ser buscado: ");
                scanf("%s", nome);
                Folha *resultadoBusca = buscarContato(raiz, nome);
                if (resultadoBusca != NULL) {
                    printf("Contato encontrado! Nome: %s, Telefone: %s\n", resultadoBusca->nome, resultadoBusca->telefone);
                } else {
                    printf("Contato nao encontrado.\n");
                }
                break;
            case 4:
                printf("\nContatos cadastrados:\n");
                imprimirContatos(raiz);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    // Liberar a memória alocada para a árvore
    limpar(raiz);

    return 0;
}
