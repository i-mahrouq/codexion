#ifndef CODEXION_H
#define CODEXION_H

#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int is_valid(const char **input);


typedef enum e_sched {
    FIFO,
    EDF
}   t_sched;

typedef struct s_config {
    int     num_coders;
    int    time_to_burnout;
    int    time_to_compile;
    int    time_to_debug;
    int    time_to_refactor;
    int     num_compiles_req;
    int    dongle_cooldown;
    t_sched scheduler;
}   t_config;

typedef struct s_dongle {
    int id;
    int position;
}

typedef struct s_coder {
    int id;
    int count_comp;
}


#endif