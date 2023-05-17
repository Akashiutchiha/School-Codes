#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>


static void signal_hander(int signo){
    if (signo == SIGINT)
        printf("Caught SIGINT!\n");
    else if (signo == SIGINT)
        printf("Caught SIGTERM!\n");
    exit(EXIT_SUCCESS);
        
}

int main(void){
    printf("process ID is %d\n ", getpid());

    if (signal(SIGINT, signal_hander) == SIG_ERR){
        perror("signal");
        exit(EXIT_FAILURE);
    }
    if (signal(SIGTERM, signal_hander) == SIG_ERR){
        fprintf(stderr, "Cannot handle SIGHUP!\n");
        exit(-1);
    }
    while (1);
    {
        /* code */
    }
    
}