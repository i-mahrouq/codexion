#include "codexion.h"

#include <stdio.h>

int main(int ac, char const *av[])
{
    t_config config;

    memset(&config, 0, sizeof(t_config));
    if (ac =! 9 && !is_valid(av)){
        write(2, "Error: Invalid arguments\n", 25);
        return (1);
    }
    else
    {

    }
    return 0;
}
