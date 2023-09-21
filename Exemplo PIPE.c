#include <stdio.h>
#include <unistd.h>

int main(){

    int pp [2];
    pipe(pp);

    char Buf [1024];
    int pid = fork();

    if (pid == 0)
    {
        //filho
        write(pp[1], "heallo\n", 8);
    }else{
        //pai
        read(pp[0], Buf, 1024);
        printf("Mensagem Recebida do Filho: %s", Buf);
    }
    
    return 0;
}
