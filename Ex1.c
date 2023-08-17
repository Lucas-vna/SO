#include <unistd.h> //biblioteca do write
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

//char * msg = (char *) malloc(20*sizeof(char));

int main(){

    char * nome = "Lucas dos Reis Viana \n";
    int ra = 2321645; 

    //read(0, &ra , sizeof(int));

    write(1, nome, 23);
    write(1, &ra, 1);

    return 0;
}
