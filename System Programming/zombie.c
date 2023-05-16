#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Creating a zombie process
int main(){
    pid_t pid;
    int status = 0;

    pid = fork();
    if(pid == 0){
        sleep(5);
        printf("I'm child process\n");
        printf("child Executing first\n");
        sleep(20);
        printf("child pid %d", getpid());
        
    }else if(pid < 0){
        perror("fork");
        exit(-1);
    }else{
        sleep(15);
        printf("I'm the parent\n");
        printf("parent exited\n");
        return 0;
        
    }
        return 0;
    }