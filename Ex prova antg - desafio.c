#include <unistd.h> //biblioteca do write
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

int count;
char aux;

void handlerAL(int signum){
	write(1, "\nSaindo do Programa...\n", 23);
	exit(0);
}

void handlerINT(int signum){
	count++;
	write(1, "\nctrl+c apertado", 16);
	
	if(count == 3){
        write(1, "Realmente Deseja Sair? [Y/N]: ", 31);
        alarm(20);

        read(0, &aux, sizeof(aux));
        //signal(SIGALRM, handlerAL);

         if (aux == 'y')
         {
            printf("1");
            exit(0);
         }else
         {
            printf("2");
            count = 0;
         }
        
    };
}

void handlesrTSTP(int signum){

	int iaux = count + '0';

	write(1, "\nctrl+c apertado ", 18);
	write(1, &aux, 1);
	write(1, " vezes\n", 8);
	
}

int main (){

    signal(SIGALRM, handlerAL);
	//signal(SIGTSTP, handlerTSTP);
	signal(SIGINT, handlerINT);

    while(1){
        pause();
    }

    return 0;
}
