#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define BLKB "\e[40m"
#define WHTHB "\e[0;107m"

#define VIVO ' '
#define MORTO '#'

void ImprimeMatriz(int l, int c, char mat[l][c]);
void Simula(int l, int c, char mat[l][c]);
int QtdVizinhos(int l, int c, char mat[l][c], int i, int j);
void GeraMatriz(int l, int c, char mat[l][c]);

int l, c;

int main() {
    scanf("%d %d", &l, &c);
    char matriz[l][c];

    GeraMatriz(l, c, matriz);

    Simula(l, c, matriz);

    return 0;
}

void ImprimeMatriz(int l, int c, char mat[l][c]) {
    int i, j;

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            if (mat[i][j] == VIVO)
                printf(BLKB "%c", mat[i][j]);
            else
                printf(WHTHB "%c", mat[i][j]);
        }
        printf("\n");
    }
}

void Simula(int l, int c, char mat[l][c]) {
    int i, j, qtdVizinhos;
    int t;
    char proxMat[l][c];

    while (1) {
        ImprimeMatriz(l, c, mat);
        usleep(200 * 1000);
        system("clear");

        for (i = 0; i < l; i++) {
            for (j = 0; j < c; j++) {
                proxMat[i][j] = mat[i][j];
            }
        }

        for (i = 0; i < l; i++) {
            for (j = 0; j < c; j++) {
                qtdVizinhos = QtdVizinhos(l, c, mat, i, j);
                if (mat[i][j] == MORTO) {
                    if (qtdVizinhos == 3) {
                        proxMat[i][j] = VIVO;
                    }
                } else {
                    if (!(qtdVizinhos == 2 || qtdVizinhos == 3)) {
                        proxMat[i][j] = MORTO;
                    }
                }
            }
        }

        for (i = 0; i < l; i++) {
            for (j = 0; j < c; j++) {
                mat[i][j] = proxMat[i][j];
            }
        }
    }
}

int QtdVizinhos(int l, int c, char mat[l][c], int i, int j) {
    int a, b;
    int vizinhos = 0;

    for (a = -1; a <= 1; a++) {
        for (b = -1; b <= 1; b++) {
            if (mat[i + a][j + b] == VIVO) {
                if (a || b)
                    if ((i + a < l && i + a >= 0) && (j + b < c && j + b >= 0))
                        vizinhos++;
            }
        }
    }
    return vizinhos;
}

void GeraMatriz(int l, int c, char mat[l][c]) {
    printf("GeraMatriz\n");

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (rand() % 5) {
                mat[i][j] = MORTO;
            } else {
                mat[i][j] = VIVO;
            }
        }
    }

    ImprimeMatriz(l, c, mat);
}
