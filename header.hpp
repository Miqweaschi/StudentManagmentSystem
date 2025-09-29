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
#include <drogon/HttpController.h>
#include <json/json.h>
#include <drogon/drogon.h>
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
  //variabile statica utilizzata per assegnare una matricola univoca ad ogni studente;

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
    string getCognome() {
        return stud.getCognome();
    }
    string getMatricola() {
        return stud.getMatricola();
    }
};

class ListaStudenti {
private:
    nodo* head;
    nodo* tail;
public:
    ListaStudenti() : head(nullptr), tail(nullptr) {}

    ~ListaStudenti() {
        while (head != nullptr) {
            nodo* tmp = head;
            head = head->getNext();
            delete tmp;
        }
    }

    bool inserisciStudente(studente s) {
        // evita duplicati
        if (getStudente(s.getNome(), s.getCognome())) return false;

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 939420c (migliorire)
        nodo* newNodo = new nodo(s);
        if (head == nullptr) {
            head = tail = newNodo;
        } else {
            tail->setNext(newNodo);
            tail = newNodo;
        }
        return true;
<<<<<<< HEAD
=======
    nodo* getHead() {
        return head;
=======
>>>>>>> 939420c (migliorire)
    }

    bool getStudente(string nome, string cognome) {
        for (nodo* t = head; t != nullptr; t = t->getNext()) {
            if (t->getNome() == nome && t->getCognome() == cognome) {
                return true;
            }
        }
        return false;
    }

<<<<<<< HEAD
    bool inserisciStudente(studente s) {
        nodo* newNodo = new nodo(s);
        if (head == nullptr) {
            head = tail = newNodo;
            return true;
        }
            tail->setNext(newNodo);
            tail = newNodo;
            return true;
>>>>>>> 48c43f1 (inserito metodo di ricerca degli studenti di un corso)
    }
=======
    nodo* getHead() { return head; }
>>>>>>> 939420c (migliorire)

    bool getStudente(string nome, string cognome) {
        for (nodo* t = head; t != nullptr; t = t->getNext()) {
            if (t->getNome() == nome && t->getCognome() == cognome) {
                return true;
            }
        }
        return false;
    }

    nodo* getHead() { return head; }

    void eliminaStudente(string matricola) {
        if (!head) return;
        if (head->getMatricola() == matricola) {
            nodo* tmp = head;
            head = head->getNext();
            if (!head) tail = nullptr;
            delete tmp;
            return;
        }

        nodo* prec = head;
        nodo* succ = head->getNext();

        while (succ != nullptr) {
            if (succ->getMatricola() == matricola) {
                prec->setNext(succ->getNext());
                if (succ == tail) tail = prec;
                delete succ;
                return;
            }
            prec = succ;
            succ = succ->getNext();
        }
    }
};

    class studentManager {
    private:
        ListaStudenti studenti;
    public:
        bool inserisciStudente(studente s) {
            return studenti.inserisciStudente(s);
        }

        bool getStudente(string nome, string cognome) {
            return studenti.getStudente(nome, cognome);
        }

        nodo* getHead() { return studenti.getHead(); }
    };


//creazione classe corso, questa è la nostra lista che contiene un head ed una tail

    class corso {
    private:
        string nomeCorso;
        int cfu;
        ListaStudenti studenti;
    public:
        corso() : nomeCorso(""), cfu(0) {}
        corso(string n, int c) : nomeCorso(n), cfu(c) {}

        string getNomeCorso() { return nomeCorso; }

        bool inserisciStudente(studente s, studentManager &manager) {
            // controllo se è registrato nello studentManager
            if (!manager.getStudente(s.getNome(), s.getCognome())) {
                cout << "Studente " << s.getNome() << " " << s.getCognome()
                     << " non registrato. Impossibile iscriverlo al corso "
                     << nomeCorso << endl;
                return false;
            }

            // controllo se già iscritto al corso
            if (studenti.getStudente(s.getNome(), s.getCognome())) {
                cout << "Studente già iscritto al corso " << nomeCorso << endl;
                return false;
            }

            // inserimento effettivo
            studenti.inserisciStudente(s);
            cout << "Studente " << s.getNome() << " " << s.getCognome()
                 << " iscritto al corso " << nomeCorso << endl;
            return true;
        }

        void eliminaStudente(string matricola) { studenti.eliminaStudente(matricola); }

        bool getStudente(string nome, string cognome) { return studenti.getStudente(nome, cognome); }

        nodo* getHead() { return studenti.getHead(); }
};


//creazione della classe corso di laurea, questa classe contiene un array di 16 corsi, come un normale corso di laurea,

class CorsoDiLaurea {
private:
    static int codiceCorsoDiLaurea;
    int codCorsoDiLaurea;
    int puntatore;
    corso c[16];
    string nome;

    int getPuntatore() {
        return puntatore;
    }


    string getCodiceCorsoDiLaurea() {
        stringstream ss;
        ss << setw(4) << setfill('0') << codCorsoDiLaurea;
        return ss.str();
    }

public:
    CorsoDiLaurea(string n) : nome(n) , puntatore(0) {
        codCorsoDiLaurea= ++codiceCorsoDiLaurea;
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

                    cout << t->getNome() << " matricola: " << this->getCodiceCorsoDiLaurea() <<t->getMatricola() << endl;
            }
        }
    }

    void EliminaStudente(string n,string matricola) {
        for (int i = 0; i < this->getPuntatore(); i++) {
            if (this->c[i].getNomeCorso() == n) {                   // metodo che riceve in input il nome del corso e la matricola dello studente da eliminare dal corso
                for( nodo* t = this->c[i].getHead(); t != nullptr; t = t->getNext()) {      // il controllo se lo studente esiste oppure no viene fatto qui in questo metodo.
                    if (matricola == t->getMatricola()) {
                        cout << "studente " << t->getMatricola() << " eliminato dal corso" << endl;
                        this->c[i].eliminaStudente(matricola);
                    }

                }
            }
        }
    }
};

class UserController : public drogon::HttpController<UserController> {
private:
    static studentManager studentService;
public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(UserController::registerUser,"/register",drogon::Post);
    METHOD_LIST_END

        void registerUser(const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr &)> &&callback){

        auto json = req->getJsonObject();
        Json::Value res;
        if (!json || !json->isMember("nome") || !json->isMember("cognome")){
            res["success"] = false;
            res["error"] = "Missing fields";
            callback(drogon::HttpResponse::newHttpJsonResponse(res));
            return;
        }
        studente s((*json)["nome"].asString(), (*json)["cognome"].asString());
        studentService.inserisciStudente(s);

        res["success"] = true;
        res["message"] = "studente registrato con successo";
        callback(drogon::HttpResponse::newHttpJsonResponse(res));
    }
            };
<<<<<<< HEAD
=======

>>>>>>> 939420c (migliorire)

#endif //HEADER_HPP
