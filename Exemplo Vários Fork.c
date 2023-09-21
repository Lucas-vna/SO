#include <stdio.h>
#include <unistd.h>

int main(){

    int pid1 = fork();
    int pid2 = fork();

    int pp[2];
    int pp2[2];

    char buf [1024];

    if (pid1>0 && pid2>0)
    {
        printf("Terceiro filho\n");
        write(pp[1], "WESLEY BAILARINA\n\n", 19);

    }else if (pid1==0 && pid2>0){

        printf("SEGUNDO Filho");
        read(pp[0], buf, 1024);
        

    }else if (pid1>0 && pid2==0){

        printf("PRIMEIRO Filho\n");
        write(pp2[1], buf, 1024);

    }else{

        printf("PAI");
        read(pp2[0], buf, 1024);
        printf("Mensagem final recebida do filho: %s", buf);

    }

    return 0;
}
