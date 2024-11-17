/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

typedef struct {
    int idade;
    char nome[100];
} Pessoa;

Pessoa inserirDados() {
    Pessoa p;
    
    printf("\nDigite seu nome: ");
    fgets(p.nome, 100, stdin);
   
    size_t len = strlen(p.nome);
    if (len > 0 && p.nome[len - 1] == '\n') {
        p.nome[len - 1] = '\0';
    }
    
    printf("\nDigite sua idade: ");
    scanf("%d", &p.idade);
    getchar(); 
    
    return p;
}

void imprimePessoas(Pessoa p) {
   
   printf("\tNome : %s\n", p.nome);
   printf("\tIdade: %d\n\n", p.idade);
   
}

void funçãoDeTroca(Pessoa *p, Pessoa *q){
    Pessoa temp = *p;
    *p = *q;
    *q = temp;
}

int partition(Pessoa *arr, int low, int high){
    int pivot = arr[high].idade;
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j].idade < pivot) {
            i++;
            funçãoDeTroca(&arr[i], &arr[j]);
        }
    }
    funçãoDeTroca(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(Pessoa *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    Pessoa pessoa[3];

    for(int i = 0; i < sizeof(pessoa) / sizeof(pessoa[0]); i++) {
        pessoa[i] = inserirDados();
    }
    
    for(int i = 0; i < sizeof(pessoa) / sizeof(pessoa[0]); i++) {
        imprimePessoas(pessoa[i]);
    }
    
    quicksort(pessoa, 0, (sizeof(pessoa) / sizeof(pessoa[0])) - 1);
    
    printf("\nPessoas ordenadas por idade:\n");
    for (int i = 0; i < sizeof(pessoa) / sizeof(pessoa[0]); i++) {
        printf("Nome: %s, Idade: %d\n", pessoa[i].nome, pessoa[i].idade);
    }

    return 0;
}
