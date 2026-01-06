/*
 * LIBRERIE NECESSARIE
 * Ogni libreria fornisce funzionalità specifiche
 */
#include <iostream>   // Input/Output su console (cin, cout)
#include <string>     // Gestione di stringhe di testo
#include <fstream>    // File stream - per leggere e scrivere file
#include <vector>     // Vector - array dinamici
#include <ctime>      // Funzioni per lavorare con il tempo (per numeri casuali)
#include <cstdlib>    // Libreria standard C (contiene rand(), srand())
#include "Impiccato.h" // Il nostro header personalizzato

using namespace std;

/*
 * DICHIARAZIONE DI FUNZIONE (function prototype)
 * Dichiara la funzione prima di usarla, l'implementazione è sotto
 * 
 * Funzione per caricare le parole da un file di testo
 * TIPO DI RITORNO: vector<string> (un vettore di stringhe)
 * PARAMETRO: string nomeFile (nome del file da aprire)
 * 
 * Questa funzione legge un file di testo riga per riga e ritorna tutte le parole
 */
vector<string> caricaParoleDaFile(string nomeFile) {
    /*
     * DICHIARAZIONE DI VARIABILI LOCALI
     * Esistono solo all'interno di questa funzione
     */
    vector<string> parole;  // Vector vuoto che conterrà le parole
    
    /*
     * IFSTREAM (Input File STREAM)
     * Oggetto per leggere da file
     * Apre il file in modalità lettura
     */
    ifstream file(nomeFile);
    
    /*
     * METODO .is_open()
     * Verifica se il file è stato aperto correttamente
     * Ritorna bool: true se aperto, false se errore
     */
    if (!file.is_open()) {
        cout << "ERRORE: Impossibile aprire il file '" << nomeFile << "'!" << endl;
        return parole;  // Ritorna vector vuoto in caso di errore
    }
    
    string parola;  // Variabile temporanea per ogni riga letta
    
    /*
     * CICLO WHILE
     * Continua finché la condizione è vera
     * getline(stream, stringa) legge una riga dal file e la mette nella stringa
     * Ritorna true se ha letto qualcosa, false se è finito il file
     */
    while (getline(file, parola)) {
        /*
         * METODO .empty()
         * Verifica se la stringa è vuota
         * ! (NOT) nega il risultato: !parola.empty() = "se NON è vuota"
         */
        if (!parola.empty()) {
            parole.push_back(parola);  // Aggiunge la parola al vector
        }
    }
    
    /*
     * Chiude il file (buona pratica, anche se si chiude automaticamente)
     */
    file.close();
    
    return parole;  // Ritorna il vector con tutte le parole lette
}

/*
 * Funzione per selezionare una parola casuale dal vettore
 * PASSAGGIO PER RIFERIMENTO: vector<string>& parole
 * Il & significa che passiamo un RIFERIMENTO (non una copia)
 * Così evitiamo di copiare tutto il vector (più efficiente)
 * 
 * TIPO DI RITORNO: string (una singola parola)
 */
string selezionaParolaCasuale(vector<string>& parole) {
    if (parole.empty()) {
        return "";  // Ritorna stringa vuota se non ci sono parole
    }
    
    /*
     * GENERAZIONE NUMERO CASUALE
     * rand() genera un numero pseudo-casuale
     * % (operatore MODULO) ritorna il resto della divisione
     * rand() % n genera un numero tra 0 e n-1
     * Così otteniamo un indice valido per il vector
     */
    int indice = rand() % parole.size();
    return parole[indice];  // Ritorna la parola all'indice casuale
}

/*
 * FUNZIONE MAIN
 * Punto di ingresso del programma - da qui inizia l'esecuzione
 * TIPO DI RITORNO: int (per convenzione ritorna 0 se tutto ok, altro se errore)
 */
int main() {
    /*
     * INIZIALIZZAZIONE GENERATORE NUMERI CASUALI
     * srand() imposta il "seed" (seme) per la generazione casuale
     * time(0) ritorna il tempo corrente in secondi
     * Così ogni volta che eseguiamo il programma abbiamo numeri diversi
     */
    srand(time(0));
    // Titolo del gioco
    cout << "========================================" << endl;
    cout << "       GIOCO DELL'IMPICCATO" << endl;
    cout << "========================================" << endl << endl;
    
    // Chiede il nome del file contenente le parole
    string nomeFile;
    cout << "Inserisci il nome del file con le parole (es: parole.txt): ";
    cin >> nomeFile;
    
    // Carica le parole dal file
    vector<string> parole = caricaParoleDaFile(nomeFile);
    
    // Verifica che ci siano parole disponibili
    if (parole.empty()) {
        cout << "Nessuna parola trovata nel file. Il gioco non puo' iniziare." << endl;
        return 1;
    }
    
    cout << "Caricate " << parole.size() << " parole dal file!" << endl << endl;
    
    /*
     * CICLO DO-WHILE
     * Esegue il blocco di codice ALMENO UNA VOLTA, poi controlla la condizione
     * Sintassi: do { codice } while (condizione);
     * Continua finché scelta è 's' o 'S'
     */
    char scelta;
    do {
        // Seleziona una parola casuale
        string parola = selezionaParolaCasuale(parole);
        
        cout << "Una parola e' stata scelta casualmente!" << endl;
        cout << "Prova a indovinarla!" << endl << endl;
        
        /*
         * CREAZIONE DI UN OGGETTO (istanza della classe)
         * Sintassi: NomeClasse nomeOggetto(parametri);
         * Questo chiama il COSTRUTTORE della classe Impiccato
         * "gioco" è un oggetto che contiene:
         * - gli attributi (parolaSegreta, tentativiRimasti, ecc.)
         * - i metodi (tentaLettera(), haVinto(), ecc.)
         */
        Impiccato gioco(parola, 6);
        
        cout << "Hai " << gioco.getTentativiRimasti() << " tentativi a disposizione." << endl << endl;
        
        /*
         * CICLO PRINCIPALE DEL GIOCO (game loop)
         * OPERATORE && (AND logico)
         * Continua FINCHÉ: non ha vinto E non ha perso
         * !gioco.haVinto() = "se NON ha vinto"
         * !gioco.haPerso() = "se NON ha perso"
         */
        while (!gioco.haVinto() && !gioco.haPerso()) {
            // ========== MOSTRA STATO DEL GIOCO ==========
            
            /*
             * CHIAMATA DI METODI
             * Sintassi: oggetto.metodo()
             * Il . (punto) è l'operatore di accesso ai membri
             */
            gioco.mostraImpiccato();
            cout << "Parola: " << gioco.getParolaMostrata() << endl;
            cout << "Tentativi rimasti: " << gioco.getTentativiRimasti() << endl;
            
            /*
             * METODO .length() delle stringhe
             * Ritorna la lunghezza della stringa (numero di caratteri)
             * OPERATORE > (maggiore di)
             */
            if (gioco.getLettereProvate().length() > 0) {
                cout << "Lettere provate: " << gioco.getLettereProvate() << endl;
            }
            
            // Chiede al giocatore di inserire una lettera
            char lettera;
            cout << "\nInserisci una lettera: ";
            cin >> lettera;
            
            /*
             * FUNZIONE isalpha()
             * Verifica se un carattere è una lettera alfabetica
             * Ritorna true se è a-z o A-Z, false altrimenti
             */
            if (!isalpha(lettera)) {
                cout << "Devi inserire una lettera valida!" << endl;
                continue;  // CONTINUE: salta il resto del ciclo e ricomincia
            }
            
            // Tenta la lettera chiamando il metodo dell'oggetto
            gioco.tentaLettera(lettera);
            cout << endl;
        }
        
        // ========== FINE DEL GIOCO - MOSTRA RISULTATO ==========
        
        gioco.mostraImpiccato();  // Mostra l'ultima versione del disegno
        
        /*
         * STRUTTURA IF-ELSE per determinare vittoria o sconfitta
         */
        if (gioco.haVinto()) {
            // Il giocatore ha vinto
            cout << "========================================" << endl;
            cout << "  COMPLIMENTI! HAI VINTO!" << endl;
            cout << "========================================" << endl;
            cout << "La parola era: " << gioco.getParolaSegreta() << endl;
        } else {
            // Il giocatore ha perso
            cout << "========================================" << endl;
            cout << "  HAI PERSO! L'OMINO E' STATO IMPICCATO!" << endl;
            cout << "========================================" << endl;
            cout << "La parola era: " << gioco.getParolaSegreta() << endl;
        }
        
        // Chiede se si vuole giocare di nuovo
        cout << "\nVuoi giocare ancora? (s/n): ";
        cin >> scelta;
        cout << endl;
        
    /*
     * OPERATORE || (OR logico)
     * Continua se scelta è 's' OPPURE 'S' (maiuscola o minuscola)
     */
    } while (scelta == 's' || scelta == 'S');
    
    // Messaggio di uscita
    cout << "Grazie per aver giocato!" << endl;
    
    /*
     * RETURN 0
     * Indica che il programma è terminato correttamente senza errori
     * È lo standard per la funzione main()
     */
    return 0;
}
