import os
import time
import random


def figlio():
    print(f"Figlio numero{os.getpid()}: Il mio numero preferito é:{random.randint(1, 560)}",flush=True)
    time.sleep(5)  
    print(f"Figlio numero{os.getpid()}: Muoio",flush=True)
    os._exit(0)  

def sforna_figli(n):
    child_pids = [] 

    for i in range(n):
        pid = os.fork()
        if pid == 0:
            figlio()
        elif pid > 0:
            child_pids.append(pid)
            print(f"Padre: Creato figlio numero {pid}",flush=True)
        else:
            print("Fork fallita",flush=True)
            os._exit(1)

    # Sala di attesa
    for pid in child_pids:
        finished_pid, status = os.waitpid(pid, 0)
        print(f"Parent: Figlio numero {finished_pid} deceduto con status {status}",flush=True)

    print("Parent: Figli tutti morti, Li seguo",flush=True)

if __name__ == "__main__":
    try:
        n = int(input("Numero di figli da creare: "))
        if n > 0:
            sforna_figli(n)
        else:
            print("Devi creare almeno un figlio")
    except ValueError:
        print("Input non valido, inserisci un numero")
