#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 20
#define NOME_FIFO "manelaaaa"


int main(int argc, char const *argv[])
{
    
    // ler mensagem do FIFO
    char buffer[BUFFER_SIZE];
    int fd = 0;

    if(mkfifo (NOME_FIFO, 0666) < 0)
    {
        perror ("Erro mkfifo ja ta criado");
        exit(1);
    }
    
    fd = open(NOME_FIFO, O_RDONLY);
    while(read(fd, buffer, BUFFER_SIZE) > 0)
    {
        buffer[BUFFER_SIZE-1] = '\0';
        printf("Received message: %s\n", buffer);
    }
    
    // fechar o FIFO
    close(fd);
    unlink(NOME_FIFO);
}
