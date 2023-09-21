#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    int pid;
    char comando[20];

    while(1){
        
        pid = fork();

        if(pid == 0){ 

            write(1, "Insira o comando: ", 18);
            scanf(%s, comando);

            if(strcmp(comando, "listar") == 0){
                printf("Entrei");
                execl("/bin/ls", "ls", "-l", NULL);
            }else if(strcmp(comando, "processos") == 0){
                execl("/bin/ps", "ps", "-a", NULL)
            }

        }
        wait(NULL);

    }//while



    return 0;
}
}
