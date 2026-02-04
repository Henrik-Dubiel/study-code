#include <stdio.h>

int main() {

    float zahl1, zahl2, ergebnis;
    char operation;

    printf("Geben Sie die erste Zahl ein: \n");
    scanf("%f", &zahl1);

    printf("Geben Sie die zweite Zahl ein: \n");
    scanf("%f", &zahl2);

    printf("Waehlen Sie die Art der Operation (+; -; *; /): \n");
    scanf(" %c", &operation);

    switch(operation) {

        case '+':
            ergebnis = zahl1 + zahl2;
            break;

        case '-':
            ergebnis = zahl1 - zahl2;
            break;

        case '*':
            ergebnis = zahl1 * zahl2;
            break;

        case '/':
            if(zahl2 == 0) {
                printf("Es darf nicht durch Null geteilt werden.\n");
                return 1;
            }
            ergebnis = zahl1 / zahl2;
            break;

        default:
            printf("Falsche Eingabe für Operation.\n");
            return 1;
    }

    printf("Ergebnis: %f\n", ergebnis);

    return 0;
}