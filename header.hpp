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
        studente() : nome(""), cognome("") {} //costruttore di default

        studente(string n, string c) {
            nome = n;
            cognome = c;        // costruttore parametrizzato
            matricola = ++contatore;
        }

        string getNome() {
            return nome;
        }
        string getCognome() {
            return cognome;
        }

        string getMatricola() {
            stringstream ss;
            ss << setw(6) << setfill('0') << matricola;
            return ss.str();
        }
};
int studente::contatore = 0;  //variabile statica utilizzata per assegnare una matricola univoca ad ogni studente;




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


//creazione classe corso
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

class CorsoDiLaurea {
private:
    static int codiceCorsoDiLaurea;
    int puntatore;
    corso c[16];
    string nome;
public:
    CorsoDiLaurea(string n) : nome(n) , puntatore(0) {
        ++codiceCorsoDiLaurea;
    }

    void inserisciCorsi(corso t) {
        c[puntatore] = t;
        puntatore++;
    }

    int getPuntatore() {
        return puntatore;
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

    string getCodiceCorsoDiLaurea() {
        stringstream ss;
        ss << setw(4) << setfill('0') << codiceCorsoDiLaurea;
        return ss.str();
    }

    void getStudentiDalCorso(string n) {
        for (int i = 0; i < this->getPuntatore(); i++) {
            if (this->c[i].getNomeCorso() == n) {
                for( nodo* t = this->c[i].getHead(); t != nullptr; t = t->getNext()) {
                    cout << t->getNome() << " matricola: " << getCodiceCorsoDiLaurea() <<t->getMatricola() << endl;
                }
            }
        }
    }
};

 int CorsoDiLaurea::codiceCorsoDiLaurea = 0;
#endif //HEADER_HPP
