/*
** Função : Gerenciador de Pilha de Processos
** Autor : Thiago Henrique Paiva de Sousa
** Data : 05/06/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char descricao[100];
} Processo;

typedef struct Node {
    Processo processo;
    struct Node *proximo;
} Node;

typedef struct {
    Node *topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = NULL;
}

int pilhaVazia(Pilha *p) {
    return (p->topo == NULL);
}

void empilhar(Pilha *p, Processo proc) {
    Node *novoNode = (Node *)malloc(sizeof(Node));
    novoNode->processo = proc;
    novoNode->proximo = p->topo;
    p->topo = novoNode;
}

Processo desempilhar(Pilha *p) {
    if (pilhaVazia(p)) {
        Processo vazio = {0, "Pilha Vazia"};
        return vazio;
    }
    Node *temp = p->topo;
    Processo proc = temp->processo;
    p->topo = p->topo->proximo;
    free(temp);
    return proc;
}

void esvaziarPilha(Pilha *p) {
    while (!pilhaVazia(p)) {
        desempilhar(p);
    }
}

void exibirPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia\n");
        return;
    }
    Node *atual = p->topo;
    while (atual != NULL) {
        printf("Processo #%d - %s\n", atual->processo.id, atual->processo.descricao);
        atual = atual->proximo;
    }
}

int main() {
    Pilha p;
    inicializarPilha(&p);
    int escolha, id;
    char descricao[100];
    Processo proc;

    do {
        printf("\nMenu:\n");
        printf("1. Incluir processo\n");
        printf("2. Retirar processo\n");
        printf("3. Encerrar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o identificador: ");
                scanf("%d", &id);
                printf("Digite a descricao: ");
                getchar(); 
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strcspn(descricao, "\n")] = '\0'; 

                proc.id = id;
                strcpy(proc.descricao, descricao);

                empilhar(&p, proc);
                printf("Processo incluído. \n Estado atual da pilha:\n");
                exibirPilha(&p);
                break;

            case 2:
                proc = desempilhar(&p);
                if (strcmp(proc.descricao, "Pilha Vazia") == 0) {
                    printf("Pilha vazia\n");
                } else {
                    printf("Removido #%d - %s\n", proc.id, proc.descricao);
                    printf("Estado atual:\n");
                    exibirPilha(&p);
                }
                break;

            case 3:
                esvaziarPilha(&p);
                printf("Fim\n");
                break;

            default:
                printf("Opcao invalida\n");
        }
    } while (escolha != 3);

    return 0;
}
