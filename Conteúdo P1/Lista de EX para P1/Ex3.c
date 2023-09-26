#include <unistd.h> //biblioteca do write
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

// 3) Crie um processo para printar na tela uma lista de processos em execução no sistema.

       int
       main()
{

    int pid = fork();

    if (pid == 0)
    {
        execl("/bin/ps", "ps", "-a", NULL);
    }

    return 0;
}
