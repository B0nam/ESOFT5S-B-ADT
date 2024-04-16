#include "headers/includes.h"
#include "implementation/arvore.c"


char palavrasChave[MAX_PALAVRAS][MAX_TAMANHO_PALAVRAS];
char nomeArquivo[] = "PALAVRAS-CHAVE.txt";

void lerArquivo(char *nomeArquivo, char (*palavrasChave)[MAX_TAMANHO_PALAVRAS]);
void ordenarArray(char **palavrasChave);
void gerarArvore();

int main(void)
{
    printf("\n--- Programa Iniciado ---\n");
    printf("\n");

    Folha *raiz = NULL;
    lerArquivo(nomeArquivo, palavrasChave);

    for (int i = 1; i < MAX_PALAVRAS; i++)
    {
        if (palavrasChave[i] == "")
        {
            break;
        }
        inserirFolha(&raiz, palavrasChave[i]);
    }
    printf("\n-------------\n");
    printf("[+] Arvore Criada com sucesso.\n");

   char palavraBusca[MAX_TAMANHO_PALAVRAS];
    while (1)
    {
        printf("Digite a palavra que deseja buscar na arvore (ou 'sair' para encerrar): ");
        scanf("%s", palavraBusca);
        if (strcmp(palavraBusca, "sair") == 0)
        {
            break;
        }

        Folha *resultadoBusca = buscarPalavra(raiz, palavraBusca);
        if (resultadoBusca != NULL)
        {
            printf("Palavra '%s' encontrada na arvore.\n", palavraBusca);
        }
        else
        {
            printf("Palavra '%s' não encontrada na arvore.\n", palavraBusca);
        }
    }
    
    return 0;
}

void lerArquivo(char *nomeArquivo, char (*palavrasChave)[MAX_TAMANHO_PALAVRAS])
{
    FILE *filePointer;
    char fileContent[MAX_PALAVRAS];

    filePointer = fopen(nomeArquivo, "r");
    if (filePointer == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int i = 0;
    while (fgets(fileContent, MAX_PALAVRAS, filePointer) != NULL && i < MAX_QUANTIDADE_PALAVRAS)
    {
        strtok(fileContent, "\n");
        strcpy(palavrasChave[i], fileContent);
        printf("[+] Palavra adicionada - %s\n", palavrasChave[i]);
        i++;
    }

    fclose(filePointer);
}