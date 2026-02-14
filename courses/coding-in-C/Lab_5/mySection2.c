/*
 * File: args.c
 * Description: Print command-line arguments (index, address, content, length)
 *              using both indexing and pointer arithmetic.
 */

#include <stdio.h>
#include <string.h>

/**
 * @brief Print all command-line arguments using array indexing.
 *
 * @param[in] argc Number of command-line arguments
 * @param[in] argv Array of pointers to null-terminated strings
 */
static void print_args_with_indexing(int argc, char **argv)
{
    for (int arg_index = 0; arg_index < argc; arg_index++)
    {
        const char *p_arg = argv[arg_index];

        printf("Argument %d at address %p has content: %s (length: %zu)\n",
               arg_index,
               (void *)p_arg,
               p_arg,
               strlen(p_arg));
    }
}

/**
 * @brief Print all command-line arguments using pointer arithmetic.
 *
 * @param[in] argc Number of command-line arguments
 * @param[in] argv Array of pointers to null-terminated strings
 */
static void print_args_with_pointers(int argc, char **argv)
{
    for (int arg_index = 0; arg_index < argc; arg_index++)
    {
        const char *p_arg = *(argv + arg_index);

        printf("Argument %d at address %p has content: %s (length: %zu)\n",
               arg_index,
               (void *)p_arg,
               p_arg,
               strlen(p_arg));
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <arg1> [arg2] ...\n", argv[0]);
        return 1;
    }

    print_args_with_indexing(argc, argv);
    print_args_with_pointers(argc, argv);

    return 0;
}
