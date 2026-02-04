#include <stdio.h>

float addieren(float a, float b);
float subtrahieren(float a, float b);
float multiplizieren(float a, float b);
float dividieren(float a, float b);

int main() {

    float zahl1, zahl2, ergebnis;
    char operation;

    printf("Geben Sie die erste Zahl ein: ");
    scanf("%f", &zahl1);

    printf("Geben Sie die zweite Zahl ein: ");
    scanf("%f", &zahl2);

    printf("Operation (+ - * /): ");
    scanf(" %c", &operation);

    if(operation == '+') {
        ergebnis = addieren(zahl1, zahl2);
    }
    else if(operation == '-') {
        ergebnis = subtrahieren(zahl1, zahl2);
    }
    else if(operation == '*') {
        ergebnis = multiplizieren(zahl1, zahl2);
    }
    else if(operation == '/') {
        ergebnis = dividieren(zahl1, zahl2);
    }
    else {
        printf("Falsche Eingabe.\n");
        return 1;
    }

    printf("Ergebnis: %f\n", ergebnis);
    return 0;
}

float addieren(float a, float b) {
    return a + b;
}

float subtrahieren(float a, float b) {
    return a - b;
}

float multiplizieren(float a, float b) {
    return a * b;
}

float dividieren(float a, float b) {
    if(b == 0) {
        printf("Division durch Null nicht erlaubt!\n");
        return 0;
    }
    return a / b;
}