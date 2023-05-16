#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

static int Gdata = 111;

int main(){
    int istack = 222;
    pid_t pid;
    printf("Before fork (pid=%d)\n", getpid());
    int x = 1;

    pid = fork();
    if(pid == 0){
        printf("I'm child process \n");
        Gdata *= 3;
        istack *= 3;
        printf("pid = %d, Gdata = %d, istack = %d\n", getpid(), Gdata, istack);
        exit(0);
    }else if(pid < 0){
        perror("fork");
        exit(-1);
    }else{
        printf("I'm the parent\n");
        printf("pid = %d, Gdata = %d, istack = %d\n", getpid(), Gdata, istack);

        exit(0);
        }

        return 0;
}