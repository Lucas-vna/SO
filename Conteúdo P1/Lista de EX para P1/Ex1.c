#include <unistd.h> //biblioteca do write
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

//1) Faça um programa para disparar uma mensagen de bons estudos a cada 10 segundos utilizando a API posix do linux.

int main()
{

    while (1)
    {
        sleep(10);
        write(1, "Bons Estudos!!\n", 13);
    }
    

    return 0;
}
