/*
** Função : Pilha de Números Reais
** Autor : Thiago Henrique Paiva de Sousa
** Data : 05/06/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    float valor;
    struct No* proximo;
} No;

No* criarNo(float valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

void push(No** topo, float valor) {
    No* novo = criarNo(valor);
    novo->proximo = *topo;
    *topo = novo;
}

void pop(No** topo) {
    if (*topo == NULL) {
        printf("A pilha está vazia.\n");
        return;
    }
    No* temp = *topo;
    *topo = (*topo)->proximo;
    printf("Elemento removido: %.2f\n", temp->valor);
    free(temp);
}

int estaVazia(No* topo) {
    return topo == NULL;
}

void exibirPilha(No* topo) {
    if (estaVazia(topo)) {
        printf("A pilha está vazia.\n");
        return;
    }
    printf("Elementos na pilha:\n");
    No* atual = topo;
    while (atual != NULL) {
        printf("%.2f\n", atual->valor);
        atual = atual->proximo;
    }
}

int main() {
    No* topo = NULL;
    int opcao;
    float valor;

    do {
        printf("\nMenu\n");
        printf("1. Inserir (push)\n");
        printf("2. Retirar (pop)\n");
        printf("3. Verificar se a pilha está vazia\n");
        printf("4. Exibir a pilha\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Entre com o valor a ser inserido: ");
                scanf("%f", &valor);
                push(&topo, valor);
                exibirPilha(topo);
                break;
            case 2:
                pop(&topo);
                exibirPilha(topo);
                break;
            case 3:
                if (estaVazia(topo)) {
                    printf("A pilha está vazia.\n");
                } else {
                    printf("A pilha não está vazia.\n");
                }
                break;
            case 4:
                exibirPilha(topo);
                break;
            case 0:
                printf("Fim\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    while (topo != NULL) {
        No* temp = topo;
        topo = topo->proximo;
        free(temp);
    }

    return 0;
}
