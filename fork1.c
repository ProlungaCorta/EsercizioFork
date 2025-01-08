#include <stdio.h> //classica libreria
#include <stdlib.h> //allocazione della memoria e exit()
#include <unistd.h> //fork pid etc
#include <sys/wait.h> //waitpid()
#include <time.h> //sleep()

int main() {
    
    pid_t pid = fork();
        if (pid == 0) {
            printf("sono il figlio %d\n", getpid());
            sleep(1);
        } else if (pid > 0) {
            printf("Padre: Creato figlio numero: %d\n", pid);
        } else {
            perror("Fork fallita");
            exit(1);
        }

    int status; 
    waitpid(pid, &status, 0);
    printf("Padre: Figlio numero %d morto con status %d\n", WEXITSTATUS(status));
    printf("Padre: Tutti i figli sono morti, li seguo.\n");
    return 0;
}
