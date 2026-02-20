/*
 * File: lab7_section1.c
 * Description:
 *   Lab 7 / Section 1 (Dynamic Memory):
 *   - Read a positive integer N
 *   - Store N on the heap (malloc)
 *   - Allocate an int array with N elements (calloc)
 *   - Fill array with square numbers (i*i)
 *   - Resize array to 2*N (realloc)
 *   - Fill new part with square numbers
 *   - Print array
 *   - Free all allocated memory
 *
 * malloc vs calloc (main differences):
 *   1) malloc(size_in_bytes) allocates memory but does NOT initialize it (content is undefined).
 *   2) calloc(count, element_size) allocates count*element_size bytes AND initializes all bytes to 0.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Free allocated memory and set pointers to NULL.
 *
 * @param[in,out] pp_N   Address of the heap pointer that stores N
 * @param[in,out] pp_arr Address of the heap pointer that stores the array
 */
static void cleanup(int **pp_N, int **pp_arr)
{
    if ((pp_arr != NULL) && (*pp_arr != NULL))
    {
        free(*pp_arr);
        *pp_arr = NULL;
    }

    if ((pp_N != NULL) && (*pp_N != NULL))
    {
        free(*pp_N);
        *pp_N = NULL;
    }
}

int main(void)
{
    int *p_N = NULL;
    int *p_arr = NULL;
    int N = 0;

    /* Step 1: Read and validate N */
    if (scanf("%d", &N) != 1)
    {
        printf("Fehler: Ungueltige Eingabe\n");
        cleanup(&p_N, &p_arr);
        return 1;
    }

    if (N <= 0)
    {
        printf("ungueltige Eingabe\n");
        cleanup(&p_N, &p_arr);
        return 1;
    }

    printf("Erfolg!\n");

    /* Step 2: Store N on heap (malloc) */
    p_N = malloc(sizeof(int));
    if (p_N == NULL)
    {
        printf("Fehler: Speicher konnte nicht zugewiesen werden\n");
        cleanup(&p_N, &p_arr);
        return 1;
    }

    *p_N = N;
    printf("%d\n", *p_N);

    /* Step 3: Allocate array with calloc (zero-initialized) */
    p_arr = calloc((size_t)(*p_N), sizeof(int));
    if (p_arr == NULL)
    {
        printf("Fehler: Speicher konnte nicht zugewiesen werden\n");
        cleanup(&p_N, &p_arr);
        return 1;
    }

    /* Step 4: Fill first N values with squares */
    for (int i = 0; i < *p_N; i++)
    {
        p_arr[i] = i * i;
    }

    /* Step 5: Resize to 2*N using realloc (safe temp pointer) */
    {
        int old_n = *p_N;
        int new_n = 2 * old_n;

        int *p_temp = realloc(p_arr, (size_t)new_n * sizeof(int));
        if (p_temp == NULL)
        {
            printf("Fehler: Speicher konnte nicht zugewiesen werden\n");
            cleanup(&p_N, &p_arr);
            return 1;
        }

        p_arr = p_temp;

        /* Fill the newly allocated part */
        for (int i = old_n; i < new_n; i++)
        {
            p_arr[i] = i * i;
        }

        *p_N = new_n;
    }

    /* Step 6: Print array */
    for (int a = 0; a < *p_N; a++)
    {
        printf("%d ", p_arr[a]);
    }
    printf("\n");

    /* Step 7: Free all heap memory */
    cleanup(&p_N, &p_arr);
    return 0;
}