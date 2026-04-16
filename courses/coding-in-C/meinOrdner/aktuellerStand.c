#include <stdio.h>

void main(void) {
    int n;
    printf("Geben Sie eine Zahl ein: ");
    scanf("%d", &n);
    int start = n % 2;
        for(int i = start; i <= n; i += 2) {
            printf("%d ", i);
        }
}