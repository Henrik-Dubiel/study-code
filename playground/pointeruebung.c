#include <stdio.h>

int main(void) {
    int myNumbers[5] = {10, 20, 30, 40, 50};
    int* p1 = myNumbers + 1;
    int* p2 = myNumbers + 4;
    printf("Adresse des ersten pointers: %p\n", p1);
    printf("Adresse des zweiten pointers: %p\n", p2);
    printf("Differenz der Adressen: %ld\n", (long)(p2 - p1));
    return 0;
}