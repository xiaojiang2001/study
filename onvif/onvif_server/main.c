#include <unistd.h>
// #include "wsdd.nsmap"

extern int create_onvif_server();
int main()
{
    create_onvif_server();

    while (1)
    {
        sleep(60);
    }

    return 0;
}