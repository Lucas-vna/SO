#include <unistd.h> //biblioteca do write
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main()
{

    char *nome = "Lucas dos Reis Viana \n";
    int ra = 23;

   ra = ra + '0';

    //nome
    write(1, nome, 23);
    
    //ra
    //char ra_str[12]; // Para converter o RA em string
    //sprintf(ra_str, "%d", ra);
    write(1, &ra, sizeof(int));

    return 0;
}
