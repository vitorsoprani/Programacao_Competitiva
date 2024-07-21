#include <stdio.h>

void LeMatriz(int l, int c, char mat[l][c]);
void ImprimeMatriz(int l, int c, char mat[l][c]);
void Simula(int tam, char mat[tam][tam], int passos);
int QtdVizinhos(int tam, char mat[tam][tam], int i, int j);

int tam, passos;

int main() {
    scanf("%d %d\n", &tam, &passos);
    char matriz[tam][tam];

    LeMatriz(tam, tam, matriz);
    Simula(tam, matriz, passos);
    ImprimeMatriz(tam, tam, matriz);
    return 0;
}

void LeMatriz(int l, int c, char mat[l][c]) {
    int i, j;

    for(i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            scanf("%c", &mat[i][j]);
        }
        scanf("%*c");
    }
}

void ImprimeMatriz(int l, int c, char mat[l][c]) {
    int i, j;

    for(i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}

void Simula(int tam, char mat[tam][tam], int passos) {
    int i, j, qtdVizinhos;
    int t;
    char proxMat[tam][tam];

    //ImprimeMatriz(tam, tam, mat);

    for (t = 1; t <= passos; t++) {
        for (i = 0; i < tam; i++) {
            for (j = 0; j < tam; j++) {
                proxMat[i][j] = mat[i][j];
            }
        }

        for (i = 0; i < tam; i++) {
            for (j = 0; j < tam; j++) {
                qtdVizinhos = QtdVizinhos(tam, mat, i, j);
                //printf("'%d'", qtdVizinhos);
                if (mat[i][j] == '0') {
                    if (qtdVizinhos == 3) {
                        proxMat[i][j] = '1';
                    }
                } else {
                    if (!(qtdVizinhos == 2 || qtdVizinhos == 3)) {
                        proxMat[i][j] = '0';
                    } 
                }
            }
        }
        //ImprimeMatriz(tam, tam, proxMat);
        //printf("\n");
        for (i = 0; i < tam; i++) {
            for (j = 0; j < tam; j++) {
                mat[i][j] = proxMat[i][j];
            }
        }
    }
}

int QtdVizinhos(int tam, char mat[tam][tam], int i, int j) {
    int k, l;
    int vizinhos = 0;

    for (k = -1; k <= 1; k++) {
        for (l = -1; l <= 1; l++) {
            if (mat[i + k][j + l] == '1') {
                if (k || l)
                    if((i + k < tam && i + k >= 0) && (j + l < tam && j + l >= 0))
                        vizinhos++;
            }
        }
    }
    return vizinhos;
}