#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid;
    printf("Before fork (pid=%d)\n", getpid());
    int x = 1;

    pid = fork();
    if(pid == 0){
        sleep(5);
        printf("child: id=%d\n", pid);
                printf("child: pid=%d\n", getpid());

        printf("parents PID: x=%d\n", getppid());
        exit(0);
    }else if(pid < 0){
        perror("fork");
        exit(1);
    }else{
        printf("parent: pid=%d\n", pid);
        exit(0);
        }

        return 0;
}
