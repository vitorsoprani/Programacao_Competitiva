#include <stdio.h>

void LeVetor(int n, int vet[]);
void ImprimeVetor(int n, int vet[]);
void OrdenaVetor(int n, int vet[]);
int ENcontraIdxMenorEntreAeB(int vet[], int a, int b);

int qtdCandidatos;
int qtdAprovados;
int notaDeCorte;

int main() {
    scanf("%d%d", &qtdCandidatos, &qtdAprovados);

    int candidatos[qtdCandidatos];
    
    LeVetor(qtdCandidatos, candidatos);

    OrdenaVetor(qtdCandidatos, candidatos);

    printf("%d", candidatos[qtdCandidatos - (qtdAprovados)]);
    //ImprimeVetor(qtdCandidatos, candidatos);

    return 0;
}

void LeVetor(int n, int vet[]) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }
}

void ImprimeVetor(int n, int vet[]) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
}

void OrdenaVetor(int n, int vet[]) {
    int i, aux;

    for (i = 0; i < n-1; i++) {
        aux = ENcontraIdxMenorEntreAeB(vet, i+1, n);
        if (vet[aux] < vet[i]) {
            int aux2;
            aux2 = vet[i];
            vet[i] = vet[aux];
            vet[aux] = aux2;
            // ImprimeVetor(n, vet);
            // printf("\n");
        }
    }
}

int ENcontraIdxMenorEntreAeB(int vet[], int a, int b) {
    int i;
    int idxMenor = a;

    for (i = a+1; i < b; i++) {
        if (vet[i] < vet[idxMenor]) {
            idxMenor = i;
        }
    }
    return idxMenor;
}
