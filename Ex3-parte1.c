#include <unistd.h> //biblioteca do write
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


void myprintf(int x, int y, char* msg){
 
    int size = strlen(msg);
    char msg2[11];
    strcpy(msg2,"\033[ B\033[ C");   
     
    msg2[2]= x + '0';
    msg2[6]= y + '0';

       
    write(1, msg2, 10);
    write(1, msg, sizeof(msg));
    write(1, "\n", 1);
}

int main(){

    myprintf(4, 5, "Teste");

    return 0;
}
