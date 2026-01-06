# Concetti C++ Utilizzati

Guida completa ai concetti di programmazione C++ utilizzati nel progetto Impiccato.

---

## 1. PROGRAMMAZIONE ORIENTATA AGLI OGGETTI (OOP)

### Classe (`class`)
- **Cos'è**: Un tipo di dato personalizzato che raggruppa dati (attributi) e funzioni (metodi)
- **Dove**: `Impiccato.h` - definizione della classe Impiccato
- **Esempio**:
```cpp
class Impiccato {
private:
    string parolaSegreta;  // Attributo
public:
    bool haVinto();        // Metodo
};
```

### Oggetto (Istanza)
- **Cos'è**: Una variabile di tipo classe, creata usando il costruttore
- **Dove**: `main.cpp` - `Impiccato gioco(parola, 6);`
- **Concetto**: Ogni oggetto ha la sua copia degli attributi

### Incapsulamento
- **Cos'è**: Nascondere i dettagli interni usando `private` e `public`
- **Perché**: Protegge i dati da modifiche non controllate
- **Esempio**: Gli attributi sono `private`, accessibili solo tramite metodi `public`

---

## 2. STRUTTURA DEL PROGETTO

### Header File (.h)
- **Cos'è**: File con dichiarazioni di classi e funzioni
- **File**: `Impiccato.h`
- **Scopo**: Definisce l'interfaccia (cosa può fare la classe)

### Implementation File (.cpp)
- **Cos'è**: File con l'implementazione (il codice) delle funzioni
- **File**: `Impiccato.cpp`
- **Scopo**: Contiene il codice vero e proprio dei metodi

### Header Guards
- **Cos'è**: `#ifndef`, `#define`, `#endif`
- **Dove**: Inizio e fine di `Impiccato.h`
- **Scopo**: Previene l'inclusione multipla dello stesso header

### Inclusione di File
- **Sintassi**: 
  - `#include <libreria>` per librerie standard
  - `#include "file.h"` per file locali
- **Dove**: All'inizio di ogni file

---

## 3. TIPI DI DATI

### Tipi Primitivi
- **int**: Numeri interi (`tentativiRimasti`, `maxTentativi`)
- **char**: Singolo carattere (`lettera`)
- **bool**: Vero/falso (`haVinto()`, `haPerso()`)

### Tipi Composti
- **string**: Sequenza di caratteri (`parolaSegreta`, `parolaMostrata`)
- **vector<T>**: Array dinamico (`vector<char> lettereProvate`, `vector<string> parole`)

---

## 4. FUNZIONI E METODI

### Costruttore
- **Cos'è**: Funzione speciale chiamata quando si crea un oggetto
- **Dove**: `Impiccato::Impiccato(string parola, int maxErrori)`
- **Caratteristiche**: Stesso nome della classe, nessun tipo di ritorno

### Metodi Getter
- **Cos'è**: Funzioni per leggere attributi privati
- **Esempi**: `getParolaMostrata()`, `getTentativiRimasti()`
- **Scopo**: Accesso controllato ai dati

### Funzioni Normali
- **Dove**: `caricaParoleDaFile()`, `selezionaParolaCasuale()`
- **Caratteristiche**: Non appartengono a una classe

### Parametri con Valore Default
- **Sintassi**: `Impiccato(string parola, int maxErrori = 6)`
- **Scopo**: Valore automatico se non specificato

### Passaggio per Valore vs Riferimento
- **Per valore**: `void funzione(int x)` - copia il valore
- **Per riferimento**: `void funzione(int& x)` - usa l'originale (più efficiente)
- **Esempio**: `selezionaParolaCasuale(vector<string>& parole)`

---

## 5. OPERATORI

### Aritmetici
- `+` addizione, `-` sottrazione
- `++` incremento, `--` decremento
- `%` modulo (resto della divisione)

### Di Confronto
- `==` uguale a
- `!=` diverso da
- `<` minore, `>` maggiore
- `<=` minore o uguale, `>=` maggiore o uguale

### Logici
- `&&` AND logico (entrambi veri)
- `||` OR logico (almeno uno vero)
- `!` NOT logico (negazione)

### Di Assegnazione
- `=` assegnazione
- `+=` aggiunge e assegna (es: `x += 5` → `x = x + 5`)

### Altri
- `.` accesso ai membri (`oggetto.metodo()`)
- `::` risoluzione dello scope (`Impiccato::tentaLettera`)
- `[]` accesso agli elementi di array/vector

---

## 6. STRUTTURE DI CONTROLLO

### If-Else
```cpp
if (condizione) {
    // codice se vero
} else {
    // codice se falso
}
```

### If-Else If-Else
```cpp
if (condizione1) {
    // ...
} else if (condizione2) {
    // ...
} else {
    // ...
}
```

### Ciclo For
```cpp
for (int i = 0; i < n; i++) {
    // ripeti n volte
}
```

### Ciclo While
```cpp
while (condizione) {
    // continua finché vero
}
```

### Ciclo Do-While
```cpp
do {
    // esegui almeno una volta
} while (condizione);
```

### Break e Continue
- **break**: esce dal ciclo
- **continue**: salta alla prossima iterazione

---

## 7. INPUT/OUTPUT

### Output (cout)
```cpp
cout << "Testo" << variabile << endl;
```
- `<<` operatore di inserimento
- `endl` va a capo

### Input (cin)
```cpp
cin >> variabile;
```
- `>>` operatore di estrazione

---

## 8. FILE I/O

### Lettura da File
```cpp
ifstream file("nome.txt");  // Apre file in lettura
string riga;
while (getline(file, riga)) {
    // leggi riga per riga
}
file.close();
```

### Metodi Utili
- `is_open()`: verifica se il file è aperto
- `getline()`: legge una riga completa

---

## 9. LIBRERIE STANDARD USATE

### \<iostream\>
- Input/output su console (`cin`, `cout`)

### \<string\>
- Classe `string` per gestire testo
- Metodi: `length()`, `empty()`

### \<vector\>
- Template `vector<T>` - array dinamici
- Metodi: `push_back()`, `size()`, `empty()`

### \<algorithm\>
- Funzioni per manipolare dati
- Usata: `transform()` per convertire in maiuscolo

### \<fstream\>
- File stream (`ifstream` per leggere)

### \<ctime\> e \<cstdlib\>
- Generazione numeri casuali
- `time()`, `srand()`, `rand()`

---

## 10. CONCETTI AVANZATI USATI

### Iteratori
- Usati con `transform()`
- `.begin()` e `.end()` per scorrere container

### Template
- `vector<char>`, `vector<string>`
- Classi generiche che funzionano con diversi tipi

### Namespace
- `using namespace std;`
- Evita di scrivere `std::` ogni volta

### Operatore di Risoluzione dello Scope (::)
- `Impiccato::metodo()` - il metodo appartiene a Impiccato
- `::toupper()` - funzione globale

---

## CHECKLIST PER LA PRESENTAZIONE

Quando presenti il progetto, spiega:

- Struttura del progetto: Header (.h) + Implementation (.cpp) + Main
- Classe Impiccato: Attributi privati e metodi pubblici (incapsulamento)
- Costruttore: Come inizializzi l'oggetto
- Vector: Array dinamico che cresce automaticamente
- Cicli: For per scorrere, while per il gioco, do-while per rigiocare
- Condizioni: If-else per controllare vittoria/sconfitta
- File I/O: Leggere parole da file con ifstream
- Numeri casuali: srand() e rand() per selezionare parole
- Input/Output: cin e cout per interagire con l'utente

---

## DOMANDE PROBABILI E RISPOSTE

**Q: Perché usi un header file separato?**
A: Per separare interfaccia (cosa fa la classe) dall'implementazione (come lo fa). Rende il codice più organizzato e riutilizzabile.

**Q: Cos'è l'incapsulamento?**
A: Nascondere i dettagli interni (attributi privati) e fornire un'interfaccia pubblica (metodi pubblici) per accedervi in modo controllato.

**Q: Perché usi vector invece di array normale?**
A: I vector sono dinamici (dimensione variabile), più sicuri (controllano i limiti) e hanno metodi utili (push_back, size).

**Q: Come funziona il generatore di numeri casuali?**
A: srand(time(0)) inizializza il seed con il tempo corrente, rand() % n genera un numero tra 0 e n-1.

**Q: Cosa fa l'operatore :: ?**
A: È l'operatore di risoluzione dello scope. Dice a quale classe/namespace appartiene una funzione (es: Impiccato::tentaLettera).

---

## PUNTI CHIAVE DA RICORDARE

1. **OOP**: Classi e oggetti - modo moderno di organizzare il codice
2. **Separazione**: Header per dichiarazioni, .cpp per implementazione
3. **Incapsulamento**: Private protegge, public espone
4. **STL**: Usiamo librerie standard (string, vector, iostream)
5. **Buone pratiche**: Commenti, nomi chiari, funzioni piccole e specifiche
