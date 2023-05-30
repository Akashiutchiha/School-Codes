//Creating a parent and a child process while sending a signal between them
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

static int Signal_handler(int signo){
    if(signo == SIGINT){
        printf("Caught Sigint AND Recieved the signal");
    }
}

int main(){
    printf("hello\n");
    printf("hello world this line is running\n");
    pid_t cid;
    cid = fork();
    int status;

    if(cid == 0){
        printf("This is the child process\n");
        printf("waiting for the signal\n");
        
        while (1) {
            sleep(1); // wait for signal
        }
        
        exit(0);

    }else if(cid > 0){
        printf("This is the parent process\n");
        kill(cid, SIGINT);      
        printf("Waiting for child process\n");

        wait(&status);
        printf("Child process ended");

    }else{
        printf("Error, Child process not created\n");
    }
    return 0;
}