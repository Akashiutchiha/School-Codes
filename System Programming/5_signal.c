#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>


static void signal_hander(int signo){
    if (signo == SIGUSR1)
        printf("Caught SIGINT!\n");
    
}

int main(void){
    pid_t cpid;
    int status = 0;
    int num = 5;
    cpid = fork();
    if(cpid == -1){
        printf("Error");
        exit(-1);

    }else if()
    
}