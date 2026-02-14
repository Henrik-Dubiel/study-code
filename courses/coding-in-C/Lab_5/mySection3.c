/*
 * File: mySection3.c
 * Description: 1D particle simulation (3 particles) using pointers and a temp field.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum
{
    FIELD_SIZE = 10,
    MAX_STEPS = 10
};

static void print_field(const int *p_field, int step)
{
    printf("Time %d: ", step);

    for (int i = 0; i < FIELD_SIZE; i++)
    {
        printf("%d ", *(p_field + i));
    }

    printf("\n");
}

static void clear_field(int *p_field)
{
    for (int i = 0; i < FIELD_SIZE; i++)
    {
        *(p_field + i) = 0;
    }
}

int main(void)
{
    srand((unsigned int)time(NULL));

    int field[FIELD_SIZE] = {0};
    int next_field[FIELD_SIZE] = {0};

    int *p_field = field;
    int *p_next_field = next_field;

    *(p_field + 2) = 1;
    *(p_field + 4) = 1;
    *(p_field + 6) = 1;

    for (int step = 0; step < MAX_STEPS; step++)
    {
        print_field(p_field, step);
        clear_field(p_next_field);

        /* Collect moves into next_field by COUNTING arrivals */
        for (int i = 0; i < FIELD_SIZE; i++)
        {
            if (*(p_field + i) == 1)
            {
                int direction = rand() % 2; /* 0 = left, 1 = right */
                int new_i = i + (direction == 0 ? -1 : 1);

                if (new_i < 0)
                {
                    new_i = 0;
                }
                else if (new_i >= FIELD_SIZE)
                {
                    new_i = FIELD_SIZE - 1;
                }

                *(p_next_field + new_i) += 1;
            }
        }

        /* Resolve collisions: only exactly one particle survives in a cell */
        for (int i = 0; i < FIELD_SIZE; i++)
        {
            if (*(p_next_field + i) == 1)
            {
                *(p_field + i) = 1;
            }
            else
            {
                *(p_field + i) = 0;
            }
        }
    }

    return 0;
}