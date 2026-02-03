#include <stdio.h>

int main(void) {

    int j = 8;
    printf(" ");
    for (char spalte = 'A'; spalte <= 'H'; spalte++) {
            printf("   %c", spalte);
    }
    printf("\n");

    for(int i = j; i > 0; i--) {
        printf("  ");
        for(int k = 1; k < 9; k++) {
            printf("+---");
        }
        printf("+\n");
        
        printf("%d ", i);
        if(i%2==1) {
            for(int l = 1; l < 5; l++) {
                printf("|   |###");
            }
        }
        else {
            for(int o = 1; o < 5; o++) {
                    printf("|###|   ");
            }
        }
        printf("| %d\n", i);   
    }
    printf("  +");
    for (int k = 0; k <= 7; k++)
    {
        printf("---+");
    }
    printf("\n");
    printf(" ");
    for (char spalte = 'A'; spalte <= 'H'; spalte++) {
            printf("   %c", spalte);
    }
    printf("\n");

    return 0;
}