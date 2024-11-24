/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

int buscaSequencial(float *lista, int tamanho, float valorProcurado) {
    for (int i = 0; i < tamanho; i++) {
        if (*(lista + i) == valorProcurado) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    float lista[] = {1.5, 2.3, 4.8, 5.9, 7.1};
    int tamanho = sizeof(lista) / sizeof(lista[0]);
    float valorProcurado;

    printf("Digite o valor a ser procurado: ");
    scanf("%f", &valorProcurado);

    int posicao = buscaSequencial(lista, tamanho, valorProcurado);

    if (posicao != -1) {
        printf("Valor encontrado na posição %d.\n", posicao);
    } else {
        printf("Valor não encontrado.\n");
    }

    return 0;
}
