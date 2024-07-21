#include <stdio.h>

int E;
int D;

int main() {
    scanf("%d %d", &E, &D);

    if (E > D) {
        printf("%d", E + D);
    } else {
        printf("%d", 2 * (D - E));
    }
    return 0;
}