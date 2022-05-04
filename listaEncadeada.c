#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct No{
    int valor;
    struct No *proximo;
} No;
typedef struct {
    No *inicio, *fim;
    int tam;
} Lista;
// inserção
void inserirInicio(Lista *lista, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    if(lista->inicio == NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
            lista->fim = novo;
    } else { // a lista não está vazia
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
    lista->tam++;
}
// inserir
void inserirFim(Lista *lista, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    if(lista->inicio == NULL) { // lista vazia
            lista->inicio = novo;
            lista->fim = novo;
    } else { // lista não vazia
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    lista->tam++;
}
// imprimir
void imprimir(Lista *lista) {
    No *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tam);
    while(inicio != NULL) {
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n\n");
}
// remover
void remover(Lista *lista, int valor){
    No *inicio = lista->inicio;
    No * noARemover = NULL;
    if(inicio != NULL && lista->inicio->valor == valor){
            noARemover = lista->inicio;
            lista->inicio = noARemover->proximo;
        if(lista->inicio == NULL)
            lista->fim = NULL;
    } else {
        while(inicio != NULL && inicio->proximo != NULL && inicio->proximo->valor != valor) {
            inicio = inicio->proximo;
        }
        if(inicio != NULL && inicio->proximo != NULL){
                noARemover = inicio->proximo;
                inicio->proximo = noARemover->proximo;
        if(inicio->proximo == NULL)
        lista->fim = inicio;
        }
    }
    if(noARemover){
            free(noARemover);  //libera a memoria do no
            lista->tam--; // decrementa o tamanho da lista
    }
}
// função que remove e retorna o primeiro nó
No* removerPrimeiroNO(Lista *lista){
    if(lista->inicio != NULL) {
        No *no = lista->inicio;
        lista->inicio = no->proximo;
        lista->tam--;
        if(lista->inicio == NULL)
            lista->fim = NULL;
        return no;
    } else
        return NULL;
}
// procedimento que divide uma lista em duas
void dividirLista(Lista *lista, Lista *listaI, Lista *listaP) {
    No *removido;
    while(lista->inicio != NULL) {
        removido = removerPrimeiroNO(lista);
        inserirFim(listaI, removido->valor);
        free(removido);

        removido = removerPrimeiroNO(lista);
        if(removido != NULL) {
            inserirFim(listaP, removido->valor);
            free(removido);
        }
    }
}
int main() {
    Lista lista, listaI, listaP;
    int opcao, valor;

    lista.inicio = NULL;
    lista.fim = NULL;
    lista.tam = 0;

    listaI.inicio = NULL;
    listaI.fim = NULL;
    listaI.tam = 0;

    listaP.inicio = NULL;
    listaP.fim = NULL;
    listaP.tam = 0;

    do {
        printf("1 - Inserir no inicio\n2 - Imprimir\n3 - Inserir no fim\n4 - Remover\n6 - Dividir lista\n5 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao) {
        case 1:
            printf("Digite um valor a ser inserido: ");
            scanf("%d", &valor);
            inserirInicio(&lista, valor);
            break;
        case 2:
            printf("\nLista original:\n");
            imprimir(&lista);
            printf("\nLista impar:\n");
            imprimir(&listaI);
            printf("\nLista par:\n");
            imprimir(&listaP);
            break;
        case 3:
            printf("Digite um valor a ser inserido: ");
            scanf("%d", &valor);
            inserirFim(&lista, valor);
            break;
        case 4:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            remover(&lista, valor);
            break;
        case 5:
            printf("Finalizando...\n");
            break;
        case 6:
            dividirLista(&lista, &listaI, &listaP);
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while(opcao != 5);

    return 0;
}
