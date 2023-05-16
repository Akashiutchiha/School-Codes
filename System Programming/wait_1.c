#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t cpid;
    int status = 0;

    cpid = fork();
    if(cpid == 0){
        printf("I'm child process\n");
        printf("child Executing first");
        sleep(20);
        printf("child pid %d", getpid());
        exit(3);


}else if(cpid < 0){
    perror("fork");
    exit(-1);
}else{
    printf("I'm the parent, Executing before wait\n");
    cpid = wait(&status);
    printf("wait done PPID - %d \n", getpid());
    printf("returned status - %d \n", status);
    
}
}