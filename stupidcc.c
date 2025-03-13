#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "参数不足\n");
        return 1;
    }
    char *p = argv[1];

    printf(".globl main\n");
    printf("main:\n");
    printf("  movq $%ld, %%rax\n", strtol(p, &p, 10));

    while (*p)
    {
        if (*p == '+')
        {
            p++;
            printf("  addq $%ld, %%rax\n", strtol(p, &p, 10));
            continue;
        }

        if (*p == '-')
        {
            p++;
            printf("  subq $%ld, %%rax\n", strtol(p, &p, 10));
            continue;
        }

        fprintf(stderr, "不是:'%c'\n", *p);
        return 1;
    }

    printf("  ret\n");
    return 0;
}