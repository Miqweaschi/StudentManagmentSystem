//
// Created by svitl on 24/09/2025.
//

// Realizzare un programma che gestisce studenti e corsi universitari. Ogni studente può essere iscritto a piu
// corsi e ogni corso puo avere piu studenti
#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

//creazione classe studente
class studente {
    private:
        static int contatore;
        string nome;
        string cognome;
        int matricola;
    public:
        studente() : nome(""), cognome("") {}    //costruttore di default

        studente(string n, string c) {
            nome = n;
            cognome = c;                            // costruttore parametrizzato contenente l'attributo matricola che viene
            matricola = ++contatore;                // incrementato ogni volta che un nuovo sudente viene creato. al primo studente creato diventa 1
        }                                           // diventerà successivamente 000001 tramite il metodo getMatricola.

        string getNome() {                          //metodo per ricavare il nome dello studente
            return nome;
        }
        string getCognome() {                       //metodo per ricavare il cognome dello studente
            return cognome;
        }

        string getMatricola() {
            stringstream ss;
            ss << setw(6) << setfill('0') << matricola;           //metodo per ricavare la matricola come stringa
            return ss.str();
        }
};
int studente::contatore = 0;  //variabile statica utilizzata per assegnare una matricola univoca ad ogni studente;



// creazione della classe nodo, viene creata questa classe per implementare la lista a singolo puntatore successivamente, ogni nodo
// contiene uno studente, un nodo punta al prossimo studente inserito.
class nodo {
private:
    studente stud;
    nodo* next;
public:
    nodo(studente s) : next(nullptr) {
        stud = s;
    }
    void setNext(nodo* n) {
        next = n;
    }
    nodo* getNext() {
        return next;
    }
    string getNome() {
        return stud.getNome();
    }
    string getMatricola() {
        return stud.getMatricola();
    }
};


//creazione classe corso, questa è la nostra lista che contiene un head ed una tail
class corso {
    private:

        string nomeCorso;
        int cfu;
        nodo* head;
        nodo* tail;
    public:
        corso() : nomeCorso(""), cfu(0), head(nullptr), tail(nullptr) {}
        corso(string n,int c): head(nullptr), tail(nullptr) {
            cfu = c;
            nomeCorso = n;
        }

        string getNomeCorso() {
            return nomeCorso;
        }

        nodo* getHead() {
            return head;
        }

        void inserisciStudente(studente s) {
            nodo* newNodo = new nodo(s);
            if (head == nullptr) {
                head = tail = newNodo;
            }
            else {
                tail->setNext(newNodo);
                tail = newNodo;
            }
        }
};


//creazione della classe corso di laurea, questa classe contiene un array di 16 corsi, come un normale corso di laurea,

class CorsoDiLaurea {
private:
    static int codiceCorsoDiLaurea;
    int puntatore;
    corso c[16];
    string nome;

    int getPuntatore() {
        return puntatore;
    }


    string getCodiceCorsoDiLaurea() {
        stringstream ss;
        ss << setw(4) << setfill('0') << codiceCorsoDiLaurea;
        return ss.str();
    }

public:
    CorsoDiLaurea(string n) : nome(n) , puntatore(0) {
        ++codiceCorsoDiLaurea;
    }

    void inserisciCorsi(corso t) {
        c[puntatore] = t;
        puntatore++;
    }

    void getCorso(string n) {
        for (int i = 0; i < this->getPuntatore(); i++) {
            if (this->c[i].getNomeCorso() == n) {
                cout<< "corso presente" << endl;
                return;
            }
        }
        cout << "corso non presente" << endl;
    }

    void getStudentiDalCorso(string n) {
        for (int i = 0; i < this->getPuntatore(); i++) {

            if (this->c[i].getNomeCorso() == n) {    // metodo creato per ricavare gli studenti iscritti ad un corso, il cout alla fine oltre a far uscire a video il nome dello studente
                                                     //stampa anche l'unione del codice del corso di laurea insieme alla matricola formando la MATRICOLA vera e propria,
                for( nodo* t = this->c[i].getHead(); t != nullptr; t = t->getNext())

                    cout << t->getNome() << " matricola: " << getCodiceCorsoDiLaurea() <<t->getMatricola() << endl;
                }
            }
        }
    }
};

 int CorsoDiLaurea::codiceCorsoDiLaurea = 0;
#endif //HEADER_HPP
