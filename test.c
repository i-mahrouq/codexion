#include "codexion.h"




int main()
{



    struct timeval tv;

    gettimeofday(&tv, NULL);

    printf("Seconds since Epoch: %ld\n", tv.tv_sec);
    printf("Microseconds: %ld\n", tv.tv_usec);


    gettimeofday(&tv, NULL);
    printf("%lld", (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
    return 0;
}