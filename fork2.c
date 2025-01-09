#include <stdio.h> //classica libreria
#include <stdlib.h> //allocazione della memoria e exit()
#include <unistd.h> //fork pid etc
#include <sys/wait.h> //waitpid()
#include <time.h> //sleep()

void figlio(int r) {
    
}

int main() {
    
    int n;
    printf("Numero di figli da sfornare: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input invalido devi creare almeno un figlio.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) { 
        pid_t pid = fork();
        if (pid == 0) {
            sleep(1);
            printf("Figlio numero %d: Muoio\n", getpid());
            exit(0);
        } else if (pid > 0) {
            printf("Padre [%d]: Creato figlio numero: %d\n", getpid(), pid);
        } else {
            perror("Fork fallita");
            exit(1);
        }
    }

    //sala di attesa
    pid_t pid_morti;
    int status;
    for (int i = 0; i<n; i++){
        pid_morti = waitpid(-1, &status, 0);
        printf("Padre: Figlio numero %d morto con status %d\n", pid_morti, WEXITSTATUS(status));
    }

    printf("Padre: Tutti i figli sono morti, li seguo.\n");

    return 0;
}
