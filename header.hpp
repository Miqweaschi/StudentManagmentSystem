//
// Created by svitl on 24/09/2025.
//

// Realizzare un programma che gestisce studenti e corsi universitari. Ogni studente può essere iscritto a più
// corsi e ogni corso può avere più studenti
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
    studente() : nome(""), cognome("") {}    // costruttore di default

    studente(string n, string c) {
        nome = n;
        cognome = c;
        matricola = ++contatore;  // incrementato ogni volta che un nuovo studente viene creato
    }

    string getNome() { return nome; }
    string getCognome() { return cognome; }

    string getMatricola() {
        stringstream ss;
        ss << setw(6) << setfill('0') << matricola;
        return ss.str();
    }
};

// creazione della classe nodo
class nodo {
private:
    studente stud;
    nodo* next;
public:
    nodo(studente s) : stud(s), next(nullptr) {}
    void setNext(nodo* n) { next = n; }
    nodo* getNext() { return next; }
    string getNome() { return stud.getNome(); }
    string getCognome() { return stud.getCognome(); }
    string getMatricola() { return stud.getMatricola(); }
};

// lista studenti
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

        nodo* newNodo = new nodo(s);
        if (head == nullptr) {
            head = tail = newNodo;
        } else {
            tail->setNext(newNodo);
            tail = newNodo;
        }
        return true;
    }

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

// gestore studenti
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

// classe corso
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
        if (!manager.getStudente(s.getNome(), s.getCognome())) {
            cout << "Studente " << s.getNome() << " " << s.getCognome()
                 << " non registrato. Impossibile iscriverlo al corso "
                 << nomeCorso << endl;
            return false;
        }
        if (studenti.getStudente(s.getNome(), s.getCognome())) {
            cout << "Studente già iscritto al corso " << nomeCorso << endl;
            return false;
        }
        studenti.inserisciStudente(s);
        cout << "Studente " << s.getNome() << " " << s.getCognome()
             << " iscritto al corso " << nomeCorso << endl;
        return true;
    }

    void eliminaStudente(string matricola) { studenti.eliminaStudente(matricola); }
    bool getStudente(string nome, string cognome) { return studenti.getStudente(nome, cognome); }
    nodo* getHead() { return studenti.getHead(); }
};

// classe corso di laurea
class CorsoDiLaurea {
private:
    static int codiceCorsoDiLaurea;
    int codCorsoDiLaurea;
    int puntatore;
    corso c[16];
    string nome;

    int getPuntatore() { return puntatore; }
    string getCodiceCorsoDiLaurea() {
        stringstream ss;
        ss << setw(4) << setfill('0') << codCorsoDiLaurea;
        return ss.str();
    }

public:
    CorsoDiLaurea(string n) : nome(n), puntatore(0) {
        codCorsoDiLaurea = ++codiceCorsoDiLaurea;
    }

    void inserisciCorsi(corso t) {
        c[puntatore] = t;
        puntatore++;
    }

    void getCorso(string n) {
        for (int i = 0; i < this->getPuntatore(); i++) {
            if (this->c[i].getNomeCorso() == n) {
                cout << "corso presente" << endl;
                return;
            }
        }
        cout << "corso non presente" << endl;
    }

    void getStudentiDalCorso(string n) {
        for (int i = 0; i < this->getPuntatore(); i++) {
            if (this->c[i].getNomeCorso() == n) {
                for (nodo* t = this->c[i].getHead(); t != nullptr; t = t->getNext())
                    cout << t->getNome() << " matricola: " << this->getCodiceCorsoDiLaurea()
                         << t->getMatricola() << endl;
            }
        }
    }

    void EliminaStudente(string n, string matricola) {
        for (int i = 0; i < this->getPuntatore(); i++) {
            if (this->c[i].getNomeCorso() == n) {
                for (nodo* t = this->c[i].getHead(); t != nullptr; t = t->getNext()) {
                    if (matricola == t->getMatricola()) {
                        cout << "studente " << t->getMatricola() << " eliminato dal corso" << endl;
                        this->c[i].eliminaStudente(matricola);
                    }
                }
            }
        }
    }
};

// controller web
class UserController : public drogon::HttpController<UserController> {
private:
    static studentManager studentService;

public:
    METHOD_LIST_BEGIN
        ADD_METHOD_TO(UserController::registerUser, "/register", drogon::Post);
        ADD_METHOD_TO(UserController::listStudents, "/students", drogon::Get);
        ADD_METHOD_TO(UserController::home, "/", drogon::Get);
    METHOD_LIST_END

    // POST /register
    void registerUser(const drogon::HttpRequestPtr &req,
                      std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
        auto json = req->getJsonObject();
        Json::Value res;

        if (!json || !json->isMember("nome") || !json->isMember("cognome")) {
            res["success"] = false;
            res["error"] = "Missing fields";
            callback(drogon::HttpResponse::newHttpJsonResponse(res));
            return;
        }

        studente s((*json)["nome"].asString(), (*json)["cognome"].asString());
        studentService.inserisciStudente(s);

        res["success"] = true;
        res["message"] = "Studente registrato con successo";
        callback(drogon::HttpResponse::newHttpJsonResponse(res));
    }

    // GET /students
    void listStudents(const drogon::HttpRequestPtr &req,
                      std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
        Json::Value res(Json::arrayValue);
        for (nodo *t = studentService.getHead(); t != nullptr; t = t->getNext()) {
            Json::Value s;
            s["nome"] = t->getNome();
            s["cognome"] = t->getCognome();
            s["matricola"] = t->getMatricola();
            res.append(s);
        }
        callback(drogon::HttpResponse::newHttpJsonResponse(res));
    }

    // GET /
    void home(const drogon::HttpRequestPtr &req,
              std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
        auto resp = drogon::HttpResponse::newFileResponse("../view/index.html"); 
        // oppure: drogon::HttpResponse::newFileResponse("./views/index.html");
        callback(resp);
    }
};

#endif // HEADER_HPP
