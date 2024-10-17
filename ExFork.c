/*
Excrever um programa C que cria uma árvore de 3 processos, onde o processo A faz um fork() criando um processo B, o processo B, por sua vez, faz um fork() 
criando um processo C. Cada processo deve exibir uma mensagem "Eu sou o processo XXX, filho de YYY", onde XXX e YYY são PIDs de processos. Utilizar wait() 
para garantir que o processo C imprima sua resposta antes do B
 e que o processo B imprima sua resposta antes do A. Utilizar sleep() (man 3 sleep) para haver um intervalo de 1 segundo entre cada mensagem impressa.
*/


#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(){

    int PID = fork();

    if (PID < 0){
        
        
        printf("Erro ao chamar o sitema\n\n");


    }else if (PID > 0){

        wait(PID);
        printf("Sou o processo A %d, filho de %d\n", getpid(), getppid());
        sleep(1);

    } else if (PID == 0){
        

        int PID2 = fork();

        if (PID2 < 0){

            printf("Erro ao chamar o sitema\n\n");

        }else if (PID2 > 0){
            
        }else if (PID2 == 0){
            
            
            wait(PID);
            printf("Sou o processo C %d\n", getpid());
            sleep(3);

            exit(0);

        }

        wait(PID);
        printf("Sou o processo B %d, filho de %d\n", getpid(), getppid());
        sleep(2);

    } 
    
    return 0;
}
