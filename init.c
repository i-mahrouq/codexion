#include "codexion.h"

int parse_and_store(int argc, char **argv, t_config *config){
    if (argc != 9)
        return (0);
    if (!is_valid((const char **)argv))
        return (0);

    config->num_coders = atoi(argv[1]); 
    config->time_to_burnout = atoi(argv[2]);
    config->time_to_compile = atoi(argv[3]);
    config->time_to_debug = atoi(argv[4]);
    config->time_to_refactor = atoi(argv[5]);
    config->num_compiles_req = atoi(argv[6]);
    config->dongle_cooldown = atoi(argv[7]);
    if (strcmp(argv[8], "fifo") == 0)
        config->scheduler = FIFO;
    else
        config->scheduler = EDF;

    return (1);
}