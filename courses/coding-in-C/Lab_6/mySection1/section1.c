#include <stdio.h>


int main(void)
{
    FILE *p_file;
    p_file = fopen("mytext.txt", "r");

    if (p_file == NULL)
    {
        printf("Fehler\n");
        return 1;
    }

    int c;
    while ((c = fgetc(p_file)) != EOF)
    {
        printf("%c", c);
    }
    printf("\n");
    rewind(p_file);
    char line[100];
    while (fgets(line, sizeof(line), p_file) != NULL)
    {
        printf("%s", line);
    }
    printf("\n");
    rewind(p_file);
    char a;
    while(fscanf(p_file, "%c", &a) == 1)
    {
        printf("%c", a);
    }
    printf("\n");
    fclose(p_file);

    FILE *p_out;
    p_out = fopen("output.txt", "w");

    if (p_out == NULL)
    {
        printf("Fehler beim Erstellen der Datei\n");
        return 1;
    }

    fputc('H', p_out);
    fputc('i', p_out);
    fputc('\n', p_out);

    rewind(p_out);

    fputs("Hello, World!", p_out);

    int i = 67;
    fprintf(p_out, "Der Wert von i ist: %d\n", i);

    fclose(p_out);

    return 0;
}
