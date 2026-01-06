/*
 * FILE DI IMPLEMENTAZIONE (.cpp)
 * Questo file contiene l'implementazione (il codice) dei metodi dichiarati nell'header
 */

/*
 * INCLUSIONE DI FILE
 * "Impiccato.h" - tra virgolette perché è un file locale (nostro)
 * <iostream> - tra parentesi angolari perché è una libreria standard
 * <algorithm> - fornisce funzioni come transform() per manipolare dati
 */
#include "Impiccato.h"
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * IMPLEMENTAZIONE DEL COSTRUTTORE
 * Sintassi: NomeClasse::NomeMetodo
 * :: è l'operatore di risoluzione dello scope (dice che questo metodo appartiene a Impiccato)
 * 
 * Questo costruttore inizializza tutti gli attributi dell'oggetto
 * PASSAGGIO PER VALORE: parola viene copiata (non modifichiamo l'originale)
 */
Impiccato::Impiccato(string parola, int maxErrori) {
    // ASSEGNAZIONE: l'operatore = assegna un valore alla variabile
    parolaSegreta = parola;
    maxTentativi = maxErrori;
    tentativiRimasti = maxErrori;
    
    /*
     * FUNZIONE transform() dalla libreria <algorithm>
     * Trasforma ogni carattere della stringa
     * Parametri:
     * 1. iteratore inizio (parolaSegreta.begin())
     * 2. iteratore fine (parolaSegreta.end())
     * 3. dove mettere il risultato (stesso posto)
     * 4. funzione da applicare (::toupper converte in maiuscolo)
     * 
     * ITERATORI: sono "puntatori intelligenti" che permettono di scorrere container
     */
    transform(parolaSegreta.begin(), parolaSegreta.end(), parolaSegreta.begin(), ::toupper);
    
    /*
     * CICLO FOR classico
     * Sintassi: for (inizializzazione; condizione; incremento)
     * int i = 0 : dichiara e inizializza la variabile contatore
     * i < parolaSegreta.length() : condizione da verificare ad ogni iterazione
     * i++ : incrementa i di 1 dopo ogni iterazione (equivale a i = i + 1)
     */
    parolaMostrata = "";  // Stringa vuota iniziale
    for (int i = 0; i < parolaSegreta.length(); i++) {
        // OPERATORE += concatena stringhe (aggiunge alla fine)
        parolaMostrata += "_ ";
    }
}

/*
 * IMPLEMENTAZIONE METODO letteraGiaProvata
 * Cerca una lettera nel vector lettereProvate
 * TIPO DI RITORNO: bool (vero/falso)
 */
bool Impiccato::letteraGiaProvata(char lettera) {
    /*
     * METODO .size() del vector
     * Ritorna il numero di elementi contenuti nel vector
     * È una funzione MEMBRO del vector (si chiama con il punto)
     */
    for (int i = 0; i < lettereProvate.size(); i++) {
        /*
         * OPERATORE [] (accesso agli elementi)
         * lettereProvate[i] accede all'elemento in posizione i (parte da 0)
         * OPERATORE == confronta due valori (uguale a)
         */
        if (lettereProvate[i] == lettera) {
            return true;  // RETURN: esce dalla funzione e ritorna il valore
        }
    }
    return false;  // Se arrivo qui, la lettera non è stata trovata
}

/*
 * IMPLEMENTAZIONE aggiornaParolaMostrata
 * Ricostruisce la parolaMostrata mostrando le lettere indovinate
 */
void Impiccato::aggiornaParolaMostrata(char lettera) {
    parolaMostrata = "";
    // CICLO ESTERNO: scorre ogni carattere della parola segreta
    for (int i = 0; i < parolaSegreta.length(); i++) {
        /*
         * VARIABILE BOOLEANA (bool)
         * Può contenere solo true o false
         * Serve come "flag" per ricordare se abbiamo trovato qualcosa
         */
        bool trovata = false;
        
        // CICLO INTERNO (nested loop = ciclo annidato)
        // Controlla se il carattere corrente è tra le lettere provate
        for (int j = 0; j < lettereProvate.size(); j++) {
            if (parolaSegreta[i] == lettereProvate[j]) {
                parolaMostrata += parolaSegreta[i];
                parolaMostrata += " ";
                trovata = true;
                break;  // BREAK: esce dal ciclo interno (non serve continuare a cercare)
            }
        }
        
        /*
         * OPERATORE ! (NOT logico)
         * !trovata significa "se trovata è false" (negazione)
         */
        if (!trovata) {
            parolaMostrata += "_ ";
        }
    }
}

/*
 * IMPLEMENTAZIONE tentaLettera
 * Metodo principale per giocare: prova una lettera e aggiorna lo stato del gioco
 */
bool Impiccato::tentaLettera(char lettera) {
    /*
     * FUNZIONE toupper()
     * Converte un carattere in maiuscolo
     * È una funzione della libreria <cctype> (inclusa da iostream)
     */
    lettera = toupper(lettera);
    
    // Controlla se la lettera è già stata provata
    if (letteraGiaProvata(lettera)) {
        /*
         * COUT (Character OUTput)
         * Oggetto per stampare su console (output stream)
         * << è l'operatore di inserimento (mette dati nello stream)
         * endl fa andare a capo (end line)
         */
        cout << "Hai gia' provato questa lettera!" << endl;
        return false;
    }
    
    /*
     * METODO .push_back() del vector
     * Aggiunge un elemento alla fine del vector
     * Il vector si ridimensiona automaticamente (array dinamico)
     */
    lettereProvate.push_back(lettera);
    
    // Verifica se la lettera è presente nella parola segreta
    bool letteraTrovata = false;
    for (int i = 0; i < parolaSegreta.length(); i++) {
        if (parolaSegreta[i] == lettera) {
            letteraTrovata = true;
            break;
        }
    }
    
    /*
     * STRUTTURA CONDIZIONALE IF-ELSE
     * if (condizione) { codice se vero } else { codice se falso }
     */
    if (letteraTrovata) {
        aggiornaParolaMostrata(lettera);
        cout << "Bravo! La lettera '" << lettera << "' e' presente!" << endl;
    } else {
        /*
         * OPERATORE -- (decremento)
         * tentativiRimasti-- equivale a: tentativiRimasti = tentativiRimasti - 1
         */
        tentativiRimasti--;
        cout << "Mi dispiace, la lettera '" << lettera << "' non c'e'!" << endl;
    }
    
    return letteraTrovata;
}

/*
 * Verifica se il giocatore ha vinto
 * Ha vinto se non ci sono più trattini nella parola mostrata
 */
bool Impiccato::haVinto() {
    // Controlla se ci sono ancora trattini
    for (int i = 0; i < parolaMostrata.length(); i++) {
        if (parolaMostrata[i] == '_') {  // Confronto con il carattere underscore
            return false;
        }
    }
    return true;
}

/*
 * Verifica se il giocatore ha perso
 * OPERATORE <= (minore o uguale a)
 * Altri operatori di confronto: < (minore), > (maggiore), >= (maggiore o uguale)
 */
bool Impiccato::haPerso() {
    return tentativiRimasti <= 0;
}

/*
 * METODI GETTER - ritornano il valore degli attributi privati
 * Non modificano lo stato dell'oggetto, solo lettura
 */
string Impiccato::getParolaMostrata() {
    return parolaMostrata;
}

int Impiccato::getTentativiRimasti() {
    return tentativiRimasti;
}

/*
 * Costruisce una stringa con tutte le lettere provate separate da virgole
 */
string Impiccato::getLettereProvate() {
    string lettere = "";
    for (int i = 0; i < lettereProvate.size(); i++) {
        lettere += lettereProvate[i];
        /*
         * OPERATORE < (minore)
         * i < lettereProvate.size() - 1 significa: "se non è l'ultimo elemento"
         * Così non mettiamo la virgola dopo l'ultima lettera
         */
        if (i < lettereProvate.size() - 1) {
            lettere += ", ";
        }
    }
    return lettere;
}

/*
 * Mostra il disegno dell'impiccato in base agli errori commessi
 * Usa caratteri ASCII per disegnare
 */
void Impiccato::mostraImpiccato() {
    /*
     * OPERATORE - (sottrazione)
     * Calcola quanti errori sono stati fatti
     */
    int errori = maxTentativi - tentativiRimasti;
    
    // Stampa la struttura base (sempre visibile)
    cout << "\n  +---+" << endl;
    cout << "  |   |" << endl;
    
    /*
     * OPERATORE >= (maggiore o uguale)
     * Controlla se abbiamo fatto almeno N errori
     * STRUTTURA IF-ELSE IF-ELSE: catena di condizioni mutualmente esclusive
     */
    
    // Testa (1° errore)
    if (errori >= 1) {
        cout << "  |   O" << endl;
    } else {
        cout << "  |    " << endl;
    }
    
    // Corpo e braccia (2°, 3°, 4° errore)
    if (errori >= 4) {
        cout << "  |  /|\\" << endl;  // \\ serve per stampare il carattere backslash
    } else if (errori >= 3) {
        cout << "  |  /|" << endl;
    } else if (errori >= 2) {
        cout << "  |   |" << endl;
    } else {
        cout << "  |    " << endl;
    }
    
    // Gambe (5° e 6° errore)
    if (errori >= 6) {
        cout << "  |  / \\" << endl;
    } else if (errori >= 5) {
        cout << "  |  /" << endl;
    } else {
        cout << "  |    " << endl;
    }
    
    cout << "  |" << endl;
    cout << "======" << endl << endl;
}

string Impiccato::getParolaSegreta() {
    return parolaSegreta;
}
