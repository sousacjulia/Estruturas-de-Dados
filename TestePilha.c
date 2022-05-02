#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}No;
typedef struct{
    No *topo;
    int tam;
}Pilha;

void empilhar(Pilha *p, int x){
  No *no = malloc(sizeof(No));
  no->valor = x;
  no->prox = p->topo;
  p->topo = no;
}
No* desempilhar(Pilha *p){
  No *no = NULL;
  if(p->topo){
    no = p->topo;
    p->topo = no->prox;
  }
  return no;
}
void imprimir(No *no){
  if(no){
    printf("%d\n", no->valor);
    imprimir(no->prox);
    }
}
int main() {
    int op, valor;
    No *no;
    Pilha p;
    p.tam = 0;
    p.topo = NULL;
  do{
    printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
    scanf("%d", &op);
    switch(op){
    case 0:
      printf("Saindo...\n");
      break;
      case 1:
        printf("Valor a ser empilhado: ");
        scanf("%d", &valor);
        empilhar(&p, valor);
        break;
      case 2:
        no = desempilhar(&p);
        if(no){
          printf("\tDesempilhado: %d\n", no->valor);
          break;
          }
      case 3:
        printf("\n-------- PILHA --------\n");
        imprimir(p.topo);
        printf("-------- PILHA --------\n");
        break;
      default:
        printf("Opcao invalida!\n");
      }
    }while(op != 0);
  return 0;
}
