#include <stdio.h> //classica libreria
#include <stdlib.h> //allocazione della memoria e exit()
#include <unistd.h> //fork pid etc
#include <sys/wait.h> //waitpid()
#include <time.h> //sleep()

void figlio(int r) {
    printf("Figlio numero %d: Il mio numero preferito è: %d\n", getpid(), r);
    sleep(5);
    printf("Figlio numero %d: Muoio\n", getpid());
    exit(0);
}

void sforna_figli(int n) {
    int r;
    for (int i = 0; i < n; i++) { 
        pid_t pid = fork();
        r = rand() % 6721;
        if (pid == 0) {
            figlio(r);
        } else if (pid > 0) {
            printf("Padre [%d]: Creato figlio numero: %d\n",getpid(), pid);
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
}

int main() {
    srand(time(NULL));
    int n;
    printf("Numero di figli da sfornare: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input invalido devi creare almeno un figlio.\n");
        return 1;
    }

    sforna_figli(n);

    return 0;
}
