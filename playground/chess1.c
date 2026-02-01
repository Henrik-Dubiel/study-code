#include <stdio.h>

int main(void) {
    for (int zeile = 8; zeile >= 1; zeile--) {
        for (char spalte = 'A'; spalte <= 'H'; spalte++) {
            printf("%c%d", spalte, zeile);
            if (zeile != 'H') printf(" ");
        }
        printf("\n");
    }
    return 0;
}