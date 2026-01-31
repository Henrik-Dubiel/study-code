#include <stdio.h>

int main() {
//------------------------------------------------------------------------
    int liste1[2][1] = {
        {33},
        {44}
    };

    int liste2[2][1] = {
        {55},
        {66}
    };
//-----------------------------------------------------------------------
    printf("liste1:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 1; j++) {
            printf("%d\n", liste1[i][j]);
        }
    }

    printf("liste2:\n");
    for(int k = 0; k < 2; k++) {
        for(int l = 0; l < 1; l++) {
            printf("%d\n", liste2[k][l]);
        }
    }
//-------------------------------------------------------------------------
    int zwischen1 = liste1[0][0];
    int zwischen2 = liste1[1][0];
//-------------------------------------------------------------------------
    liste1[0][0] = liste2[0][0];
    liste1[1][0] = liste2[1][0];
    liste2[0][0] = zwischen1;
    liste2[1][0] = zwischen2;
//-------------------------------------------------------------------------
    printf("liste1 invertiert:\n");
    for(int p = 0; p < 2; p++) {
        for(int o = 0; o < 1; o++) {
            printf("%d\n", liste1[p][o]);
        }
    }

    printf("liste2 invertiert:\n");
    for(int w = 0; w < 2; w++) {
        for(int e = 0; e < 1; e++) {
            printf("%d\n", liste2[w][e]);
        }
    }

    return 0;
}