#ifndef CODEXION_H
#define CODEXION_H


#include <stdio.h>
#include <string.h>

int is_valid(const char **input);


typedef enum e_sched {
    SCHED_FIFO,
    SCHED_EDF
}   t_sched;

typedef struct s_config {
    int     num_coders;
    long    time_to_burnout;
    long    time_to_compile;
    long    time_to_debug;
    long    time_to_refactor;
    int     num_compiles_req;
    long    dongle_cooldown;
    t_sched scheduler;
}   t_config;

#endif