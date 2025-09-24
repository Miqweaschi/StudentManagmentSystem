# Gestione Studenti e Corsi Universitari

Questo progetto in C++ implementa un semplice sistema per gestire **studenti**, **corsi** e un **corso di laurea**.  
Ogni studente può essere iscritto a più corsi e ogni corso può avere più studenti.

---

## 📂 Struttura del progetto

- **`header.hpp`** → contiene tutte le classi:
  - `studente`
  - `nodo`
  - `corso`
  - `CorsoDiLaurea`
- **`main.cpp`**  test per utilizzare le classi e simulare l’iscrizione di studenti ai corsi.

---

## 🏗️ Classi principali

### 🔹 `studente`
- Rappresenta uno studente con **nome**, **cognome** e **matricola univoca** (generata automaticamente).
- Metodi principali:
  - `getNome()`
  - `getCognome()`
  - `getMatricola()`

### 🔹 `nodo`
- Nodo di una lista concatenata che contiene uno studente.
- Utilizzato per memorizzare gli studenti iscritti a un corso.

### 🔹 `corso`
- Rappresenta un corso universitario con:
  - Nome del corso
  - Numero di crediti (CFU)
  - Lista di studenti iscritti
- Metodi principali:
  - `inserisciStudente(studente s)`
  - `getStudenti()`
  - `getNomeCorso()`

### 🔹 `CorsoDiLaurea`
- Contiene fino a **16 corsi**.
- Metodi principali:
  - `inserisciCorsi(corso t)`
  - `getCorso(string nome)`
  - `getStudentiDalCorso(string nome)`

---

## ▶️ Esempio di utilizzo

Crea un file `main.cpp` con questo contenuto:

```cpp
#include "header.hpp"

int main() {
    // Creazione di un corso di laurea
    CorsoDiLaurea informatica("Informatica");

    // Creazione corsi
    corso prog("Programmazione", 12);
    corso reti("Reti di Calcolatori", 6);

    // Creazione studenti
    studente s1("Mario", "Rossi");
    studente s2("Luca", "Bianchi");

    // Iscrizione studenti ai corsi
    prog.inserisciStudente(s1);
    prog.inserisciStudente(s2);
    reti.inserisciStudente(s1);

    // Aggiunta corsi al corso di laurea
    informatica.inserisciCorsi(prog);
    informatica.inserisciCorsi(reti);

    // Ricerca di un corso
    informatica.getCorso("Programmazione");

    // Stampa studenti di un corso
    informatica.getStudentiDalCorso("Programmazione");

    return 0;
}
