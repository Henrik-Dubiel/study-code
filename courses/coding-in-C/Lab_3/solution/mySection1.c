#include <stdio.h>

int main() {

    float zahl1;
    float zahl2;
    char operation;
    float ergebnis;

    
    printf("Geben Sie die erste Zahl ein: \n");
    scanf("%f", &zahl1);
    printf("Geben Sie die zweite Zahl ein: \n");
    scanf("%f", &zahl2);
    printf("Waehlen Sie die Art der Operation (+; -; *; /): \n");
    scanf(" %c", &operation);

    if(operation == '+') {
        ergebnis = zahl1 + zahl2;
    }
    else if(operation == '-') {
        ergebnis = zahl1 - zahl2;
    }
    else if(operation == '/') {
        if(zahl2 == 0) {
            printf("Es darf nicht durch Null geteilt werden.\n");
        }
        else {
            ergebnis = zahl1/zahl2;
        }
    }
    else if(operation == '*') {
        ergebnis = zahl1 * zahl2;
    }
    else {
        printf("Falsche Eingabe für Operation. Starten Sie das Programm erneut.");
    }

    printf("Ergebnis: %f\n", ergebnis);

    return 0;
}