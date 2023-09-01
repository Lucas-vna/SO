#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

    int pid;

    pid = fork();

    if (pid > 0)
    {
        
        wait(pid);
        printf("\nEu sou o precesso A (PID - %d)", getpid());
        sleep(2);
        

    }else if(pid == 0){

        wait(pid);
        sleep(3);
        printf("\nEu sou o processo B (PID - %d), filho de A", getpid());
        
        pid = fork();

        if(pid > 0){

        }else if(pid == 0){

            sleep(1);
            printf("\nEu sou o processo C (PID - %d), filho de B e neto de A\n\n", getpid());

        }else if(pid < 0){
            printf("Erro");
        }

    }
    

    return 0;
}
