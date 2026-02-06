#include <stdio.h>
#include <string.h>

int main(void) {

    char word[50];

    printf("Geben Sie ein Wort ein: ");
    scanf("%49s", word);

    int len = strlen(word);

    for(int i = 0; i < len / 2; i++) {
        if(word[i] != word[len - 1 - i] && word[i] != word[len - 1 - i] + 32 && word[i] != word[len - 1 - i] - 32) {
            printf("Das Wort ist kein Palindrom.\n");
            return 0;
        }
    }

    printf("Das Wort ist ein Palindrom.\n");
    return 0;
}