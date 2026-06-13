#ifndef CODEXION_H
#define CODEXION_H

#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int is_valid(const char **input);
// mcros
typedef enum e_dongle_state{
    LOCKED,
    UNLOKED
}   t_dongle_state;

typedef enum e_dongle_heat{
    COLD,
    HOT
}   t_dongle_heat;
typedef enum e_state {
    COMPILING,
    DEBUGGING,
    REFACTORING,
    WAITING_FOR_DONGLE,
    BURNED_OUT
}   t_state;

typedef enum e_sched {
    FIFO,
    EDF
}   t_sched;
//


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
    // parameters for clodown
    t_dongle_state  state;
    t_dongle_heat   heat;


    // parms for queue
}   t_dongle;

typedef struct s_coder {
    int id;
    pthread_t thread_id;
    int count_comp;


    long long last_compile_start;

    t_dongle *left_dongle;
    t_dongle *right_dongle;

}   t_coder;



typedef struct s_simu {
    t_config *config;
    t_coder         *coders;        
    t_dongle        *dongles;       
    long long       start_ms;
}   t_simu;

#endif