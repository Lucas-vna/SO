#include <unistd.h> //biblioteca do write
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

int count, iaux;
char aux;

void handlerAL(int signum){
    write(1, "\n\nSaindo do Programa...\n\n", 23);
    exit(0);
}

void handlerINT(int signum){

    count++;
    iaux++;

    if (count == 3)
    {
        write(1, "\nDeseja said do programa? [y/n]", 31);
        alarm(20);

        read(1, &aux, sizeof(aux));
        signal(SIGALRM, handlerAL);

        if (aux == 'y')
        {
            write(1, "\n\nFINALIZANDO O PROGRAMA...\n\n", 28);
            exit(0);

        }else if(aux == 'n'){

            count = 0;
            write(1, "\nCONTINUANDO...\n\n", 17);
        }
    }//if
}//funcao

void handlerTSTP(int signum){

    iaux = iaux + '0';

    write(1, "\nCTRL+C FOI APERTADO ", 21);
    write(1, &iaux, 1);
    write(1, " VEZES\n", 7);
}

int main(int argc, char *argv[]){
    
    int iaux = 0;
    int count = 0;

    signal(SIGALRM, handlerAL);
    signal(SIGTSTP, handlerTSTP);
    signal(SIGINT, handlerINT);

    while (1){
        pause();
    }

    return 0;
}
