#include <unistd.h>
#include "server/onvif_server.h"
int main()
{
    onvif_server_init();

    while (1)
    {
        sleep(60);
    }
    return 0;
}