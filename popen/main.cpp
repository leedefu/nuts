#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>   //strlen
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>   //close
#include <arpa/inet.h>    //close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros
#include <netinet/tcp.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int status;
    char path[128];

    fp = popen("cat /proc/net/dev | grep eno1 | sed 's/:/ /g' | awk '{print $3}'", "r");
    if (fp == NULL)
        /* Handle error */;


    while (fgets(path, 128, fp) != NULL)
        printf("%s", path);


    status = pclose(fp);
    if (status == -1) {
        /* Error reported by pclose() */

    } else {
        /* Use macros described under wait() to inspect `status' in order
           to determine success/failure of command executed by popen() */

    }
    return 0;
}
