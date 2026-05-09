#include "codexion.h"

#include <stdio.h>

int main(int ac, char const *av[])
{
    if (ac == 9 && is_valid(av))
        printf("hah:");
    else
        printf("usage");
    return 0;
}
