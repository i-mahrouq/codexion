#include "codexion.h"

// time since epoch
long long   get_epoch_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((long long)tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}// this needs more understanding 

long long   now_ms(t_simu *simu)
{
    return get_epoch_ms() - simu->start_ms;
}


// time in ms since the start of simuulation

// void    sleep_ms(long long ms)
// {
//     if (ms > 0)
//         usleep((useconds_t)(ms * 1000));
// }
// 