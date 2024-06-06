/*
** Função : Classificação por Seleção
** Autor : Thiago Henrique Paiva de Sousa
** Data : 05/06/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        trocar(&arr[min_idx], &arr[i]);
    }
}



void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void gerarDados(int arr[], int n, int limite) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % limite;
    }
}

int main() {
    int n;
    int limite;

    printf("Digite o número de elementos no vetor: ");
    scanf("%d", &n);

    printf("Qual o limite máximo para os valores ");
    scanf("%d", &limite);

    int *arr = (int *)malloc(n * sizeof(int));

    gerarDados(arr, n, limite);

    printf("Vetor antes da ordenação:\n");
    imprimir(arr, n);

    Sort(arr, n);

    printf("Vetor depois da ordenação:\n");
    imprimir(arr, n);

    free(arr);
    return 0;
}
