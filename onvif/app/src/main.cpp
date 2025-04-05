#include <iostream>
#include <unistd.h>
#include "./soap/wsdd.nsmap"

using namespace std;

#ifdef __cplusplus
extern "C"
{
#endif

    extern int create_onvif_server();

#ifdef __cplusplus
}
#endif

int main()
{
    create_onvif_server();

    while (1)
    {
        sleep(60);
    }

    return 0;
}
