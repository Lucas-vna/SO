#include <unistd.h>
#include <signal.h>

int count;
int count2;

void handlerTSTP(int signum){
	cont++;
	write(1, "ctrl+z recebido ", 25);
	if(count == 10) exit(0);
	
	write(1, "ctrl+z apertado", 14);
	int aux = count + '0';
	write(1, &aux, 1);
	write(1, " vezes \n", 15);
	
}

void handlerAL(int signum){
	write(1, "sinal de alarme recebido\n", 25);
}

void handlerINT(int signum){
	count2++;
	write(1, "ctrl+c apertado", 25);
	if(count2 == 1) alarm(0);
}

int main(){

	int count = 0;
	int count2 = 0;
	
	signal(SIGALRM, handlerAL);
	signal(SIGTSTP, handlerTSTP);
	signal(SIGINT, handlerINT);

	while(1){
		alarm(5);
		pause();
	}


	return 0;
}
























