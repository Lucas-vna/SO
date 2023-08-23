#include <unistd.h> //biblioteca do write
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int count = 0;

void handlerINT(int signum){
    count++;

	if(count == 1){
        write(1, "\n\nsaindo...", 10);
    } 
    
    exit(0);
}

int main(){

    signal(SIGINT, handlerINT);

    while(1){
        write(1, "\nDentro de um loop...", 22);
        sleep(5);
    }


    return 0;
}
