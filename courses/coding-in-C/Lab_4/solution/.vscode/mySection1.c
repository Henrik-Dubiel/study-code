#include <stdio.h>

void funktion(char *text) {
    text[1] = 'c';
}

int main(void) {
    char satz[] = "Curly bird catches the worm.";
    char *p = satz;

    printf("%s\n", satz);
    printf("%s\n", p);

    p[0] = 'E';
    p[1] = 'a';

    printf("%s\n", satz);
    printf("%s\n", p);

    char satz2[] = "AActions speak louder than words.";

    funktion(satz2);

    printf("%s\n", satz2);

    return 0;
}