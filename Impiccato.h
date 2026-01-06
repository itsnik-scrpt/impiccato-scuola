/*
 * HEADER GUARD (#ifndef, #define, #endif)
 * Previene l'inclusione multipla dello stesso file header.
 * Se IMPICCATO_H non è definito, lo definisce e include il contenuto,
 * altrimenti salta tutto fino a #endif. Questo evita errori di compilazione.
 */
#ifndef IMPICCATO_H
#define IMPICCATO_H

/*
 * INCLUSIONE DI LIBRERIE STANDARD
 * #include serve per includere file header di librerie standard o personalizzate
 * <string> fornisce la classe string per gestire stringhe di testo
 * <vector> fornisce il template vector per array dinamici (dimensione variabile)
 */
#include <string>
#include <vector>

/*
 * NAMESPACE
 * using namespace std; permette di usare gli elementi della libreria standard
 * senza scrivere "std::" ogni volta (es: string invece di std::string)
 */
using namespace std;

/*
 * DICHIARAZIONE DI CLASSE
 * Una classe è un tipo di dato personalizzato che raggruppa:
 * - DATI (variabili membro/attributi)
 * - FUNZIONI (metodi) che operano su quei dati
 * Questo è il concetto base della Programmazione Orientata agli Oggetti (OOP)
 * 
 * Classe Impiccato
 * Gestisce la logica del gioco dell'impiccato
 */
class Impiccato {
/*
 * SEZIONE PRIVATE
 * I membri dichiarati come "private" sono accessibili SOLO all'interno della classe.
 * Questo è il concetto di INCAPSULAMENTO (information hiding):
 * nascondiamo i dettagli interni e proteggiamo i dati da modifiche esterne non controllate.
 */
private:
    // ATTRIBUTI (variabili membro) - rappresentano lo STATO dell'oggetto
    
    string parolaSegreta;           // La parola da indovinare (tipo string)
    string parolaMostrata;          // La parola con le lettere indovinate e i trattini
    
    /*
     * VECTOR: è un array dinamico (dimensione variabile)
     * vector<char> significa: vettore che contiene elementi di tipo char (caratteri)
     * Possiamo aggiungere/rimuovere elementi senza preoccuparci della dimensione
     */
    vector<char> lettereProvate;    // Tutte le lettere già provate dal giocatore
    
    int tentativiRimasti;           // Numero di tentativi rimasti (tipo int = numero intero)
    int maxTentativi;               // Numero massimo di errori consentiti
    
    /*
     * METODI PRIVATI (funzioni helper)
     * Sono funzioni di supporto usate solo internamente dalla classe
     * Non devono essere chiamate dall'esterno
     */
    
    /*
     * Metodo privato per verificare se una lettera è già stata provata
     * TIPO DI RITORNO: bool (booleano - può essere true o false)
     * PARAMETRO: char lettera (un singolo carattere passato PER VALORE)
     * Ritorna: true se la lettera è già stata provata, false altrimenti
     */
    bool letteraGiaProvata(char lettera);
    
    /*
     * Metodo privato per aggiornare la parola mostrata dopo aver indovinato una lettera
     * TIPO DI RITORNO: void (non ritorna nessun valore)
     * PARAMETRO: char lettera (il carattere indovinato)
     */
    void aggiornaParolaMostrata(char lettera);

/*
 * SEZIONE PUBLIC
 * I membri dichiarati come "public" sono accessibili da qualsiasi parte del programma.
 * Questi formano l'INTERFACCIA pubblica della classe - ciò che gli utenti possono usare.
 */
public:
    /*
     * COSTRUTTORE
     * Funzione speciale che viene chiamata automaticamente quando creiamo un oggetto.
     * Ha lo stesso nome della classe e NON ha tipo di ritorno.
     * Serve per INIZIALIZZARE lo stato dell'oggetto.
     * 
     * PARAMETRI:
     * - string parola: la parola segreta da indovinare (passata per valore)
     * - int maxErrori = 6: numero massimo di errori (PARAMETRO CON VALORE DEFAULT)
     *   Se non specifichi maxErrori, usa automaticamente 6
     * 
     * Esempio di utilizzo:
     * Impiccato gioco1("CIAO", 5);    // maxErrori = 5
     * Impiccato gioco2("CASA");        // maxErrori = 6 (default)
     */
    Impiccato(string parola, int maxErrori = 6);
    
    /*
     * METODI PUBBLICI (interfaccia della classe)
     * Queste funzioni possono essere chiamate dall'esterno per interagire con l'oggetto
     */
    
    /*
     * Metodo per tentare di indovinare una lettera
     * TIPO DI RITORNO: bool (true = lettera presente, false = lettera assente)
     * PARAMETRO: char lettera - il carattere da provare
     * Questo metodo modifica lo stato interno dell'oggetto (lettereProvate, tentativiRimasti)
     */
    bool tentaLettera(char lettera);
    
    /*
     * Metodo per verificare se il gioco è vinto
     * TIPO DI RITORNO: bool (true = hai vinto, false = non ancora)
     * NESSUN PARAMETRO (funzione senza argomenti)
     */
    bool haVinto();
    
    /*
     * Metodo per verificare se il gioco è perso
     * TIPO DI RITORNO: bool (true = hai perso, false = puoi ancora giocare)
     */
    bool haPerso();
    
    /*
     * METODI GETTER (accessor methods)
     * Servono per LEGGERE i valori degli attributi privati
     * È buona pratica usare getter invece di rendere gli attributi pubblici
     * perché possiamo controllare come i dati vengono acceduti
     */
    
    /*
     * Getter per ottenere la parola mostrata con i trattini
     * TIPO DI RITORNO: string (la parola parzialmente svelata)
     */
    string getParolaMostrata();
    
    /*
     * Getter per ottenere il numero di tentativi rimasti
     * TIPO DI RITORNO: int (numero intero)
     */
    int getTentativiRimasti();
    
    /*
     * Getter per ottenere la lista delle lettere già provate
     * TIPO DI RITORNO: string (lettere separate da virgola)
     */
    string getLettereProvate();
    
    /*
     * Metodo per mostrare il disegno dell'impiccato
     * TIPO DI RITORNO: void (non ritorna nulla, stampa solo a schermo)
     * Usa cout per output su console
     */
    void mostraImpiccato();
    
    /*
     * Getter per ottenere la parola segreta (usato quando si perde per mostrarla)
     * TIPO DI RITORNO: string (la parola completa)
     */
    string getParolaSegreta();
};

#endif
