#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Definições dos comandos internos
#define CMD_LS "ls"
#define CMD_PS "ps"

// Função para ler uma linha do terminal
char *read_line() {
  char *line = NULL;
  size_t len = 0;

  // Lê a linha do terminal até encontrar o caractere '\n'
  while (getline(&line, &len, stdin) != -1) {
    // Remove o caractere '\n' do final da linha
    line[strcspn(line, "\n")] = '\0';

    // Se a linha estiver vazia, continua lendo
    if (line[0] == '\0') {
      continue;
    }

    // Retorna a linha lida
    return line;
  }

  // Se a linha for inválida, retorna NULL
  return NULL;
}

// Função para executar um comando interno
int execute_internal_command(char *command) {
  // Verifica se o comando é válido
  if (strcmp(command, CMD_LS) == 0) {
    // Executa o comando `ls`
    return system("ls");
  } else if (strcmp(command, CMD_PS) == 0) {
    // Executa o comando `ps`
    return system("ps");
  } else {
    // O comando é inválido
    return -1;
  }
}

// Função para executar um comando externo
int execute_external_command(char *command) {
  // Cria um processo filho para executar o comando
  pid_t pid = fork();

  // Se o processo for filho, executa o comando
  if (pid == 0) {
    // Executa o comando
    return system(command);
  }

  // Se o processo for pai, aguarda o término do filho
  if (waitpid(pid, NULL, 0) == -1) {
    // Erro ao aguardar o filho
    return -1;
  }

  // Retorna o código de saída do filho
  return WEXITSTATUS(pid);
}

// Função principal
int main() {
  // Loop principal
  while (1) {
    // Lê uma linha do terminal
    char *command = read_line();

    // Se a linha estiver vazia, continua
    if (command == NULL) {
      continue;
    }

    // Verifica se o comando é interno
    if (execute_internal_command(command) == 0) {
      // Comando interno executado com sucesso
      continue;
    }

    // Executa o comando externo
    int status = execute_external_command(command);

    // Se o comando externo falhou, imprime o erro
    if (status != 0) {
      printf("Erro ao executar o comando '%s'\n", command);
    }
  }

  return 0;
}
