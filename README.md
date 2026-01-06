# Gioco dell'Impiccato in C++

## Descrizione

Il gioco carica una lista di parole da un file di testo, ne seleziona una casualmente e il giocatore deve indovinarla lettera per lettera.

---

## Struttura del Progetto

Il progetto è composto da tre file:

1. **Impiccato.h** - File header che contiene la dichiarazione della classe Impiccato
2. **Impiccato.cpp** - File di implementazione che contiene il codice dei metodi della classe
3. **main.cpp** - File principale che contiene la logica del gioco e l'interazione con l'utente
4. **parole.txt** - File di testo contenente 150+ parole italiane per il gioco

---

## Come Compilare

### Con g++ (MinGW su Windows, o g++ su Linux/Mac):

```bash
g++ -o impiccato main.cpp Impiccato.cpp
```

### Con Visual Studio:

1. Crea un nuovo progetto Console C++
2. Aggiungi tutti e tre i file al progetto
3. Compila ed esegui

---

## Come Giocare

1. Avvia il programma
2. Inserisci il nome del file con le parole (es: `parole.txt`)
3. Il programma carica le parole e ne seleziona una casualmente
4. Prova a indovinare la parola inserendo una lettera alla volta
5. Ad ogni tentativo sbagliato, viene disegnata una parte dell'omino impiccato
6. Il gioco termina quando:
   - Indovini la parola completa (VITTORIA)
   - Esaurisci tutti i 6 tentativi disponibili (SCONFITTA)
7. Puoi giocare più partite consecutive (ogni volta verrà scelta una nuova parola casuale)

---

## Caratteristiche

- **Caricamento da file**: Legge le parole da un file di testo esterno
- **Selezione casuale**: Sceglie automaticamente una parola diversa ad ogni partita
- **150+ parole italiane**: File di esempio già pronto con tante parole
- **Classe ben strutturata**: Il codice usa la programmazione orientata agli oggetti
- **Commenti dettagliati**: Ogni metodo e sezione è commentata in italiano con spiegazioni dei concetti C++
- **Disegno ASCII**: Mostra visivamente l'omino impiccato che si completa ad ogni errore
- **Gestione input**: Controlla che l'utente inserisca lettere valide
- **Rigiocabilità**: Permette di giocare più partite consecutive

---

## Personalizzazione

Puoi creare il tuo file di parole personalizzato:

1. Crea un file `.txt` (es: `mieparole.txt`)
2. Inserisci una parola per riga
3. Salva il file nella stessa cartella del programma
4. Quando il gioco chiede il file, inserisci il nome del tuo file

---

## Concetti C++ Utilizzati

Per una guida completa sui concetti C++ usati nel progetto, consulta il file `CONCETTI_CPP.md`.

Include spiegazioni dettagliate su:
- Programmazione Orientata agli Oggetti (Classi, Oggetti, Incapsulamento)
- Struttura Header/Implementation
- Tipi di dati (int, char, bool, string, vector)
- Funzioni e metodi (costruttori, getter, passaggio per valore/riferimento)
- Operatori (aritmetici, logici, di confronto)
- Strutture di controllo (if, for, while, do-while)
- Input/Output (cin, cout)
- File I/O (ifstream, getline)
- Librerie standard (iostream, string, vector, algorithm, fstream, ctime, cstdlib)

