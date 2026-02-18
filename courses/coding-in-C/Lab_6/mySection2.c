#include <stdio.h>

int main(void)
{
    FILE *p_file = fopen("sensor1.txt", "r");

    if (p_file == NULL)
    {
        printf("Fehler beim Öffnen der Datei\n");
        return 1;
    }

    const double threshold = 0.5;

    float time;
    double probability;

    int detection[3000];
    int index = 0;

    while (index < 3000 &&
           fscanf(p_file, "%f %lf", &time, &probability) == 2)
    {
        if (probability > threshold)
        {
            detection[index] = 1;
        }
        else
        {
            detection[index] = 0;
        }

        printf("%d\n", detection[index]);

        index++;
    }

    fclose(p_file);
    return 0;
}
