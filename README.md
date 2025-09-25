# Gestione Studenti e Corsi Universitari

Questo progetto in C++ implementa un semplice sistema per gestire **studenti**, **corsi** e un **corso di laurea**.  
Ogni studente può essere iscritto a più corsi e ogni corso può avere più studenti.

---

##  Struttura del progetto

- **`header.hpp`** → contiene tutte le classi:
  - `studente`
  - `nodo`
  - `corso`
  - `CorsoDiLaurea`
- **`main.cpp`**  test per utilizzare le classi e simulare l’iscrizione di studenti ai corsi.

---

##  Classi principali

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
