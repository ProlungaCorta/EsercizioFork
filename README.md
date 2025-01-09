# Progetto Esempio: Creazione di Processi Figli con `fork`

Questo repository serve come esempio per comprendere come creare e gestire i processi figli utilizzando la chiamata di sistema `fork`. Il progetto include codice scritto in più linguaggi, tutti dimostrando la stessa funzionalità di base: creare `n` processi figli e gestirli correttamente per evitare processi zombie.

## Struttura del Progetto

Per semplificare il processo di apprendimento, il repository contiene tre programmi in C di complessità progressivamente maggiore:

1. **fork1.c**  
   Introduce il concetto base di `fork` e come creare un singolo processo figlio.

2. **fork2.c**  
   Dimostra la creazione di più processi figli, basandosi sui concetti introdotti in `fork1`.

3. **forkpulito.c**  
   Fornisce un esempio più avanzato, in cui ogni processo figlio esegue un'azione specifica diversa da `sleep`. Questo esempio illustra anche le migliori pratiche per gestire i processi figli in modo pulito.

Ognuno di questi esempi mira ad approfondire gradualmente la comprensione di `fork` e della gestione dei processi in modo chiaro e strutturato.

## Altri Linguaggi

Oltre ai programmi in C, vengono forniti esempi equivalenti in Perl e Python per mostrare l'implementazione di funzionalità simili in diversi linguaggi di programmazione.

---
