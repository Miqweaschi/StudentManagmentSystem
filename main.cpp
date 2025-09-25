#include <complex.h>
#include <iostream>
#include "header.hpp"
// Realizzare un programma che gestisce studenti e corsi universitari. Ogni studente può essere iscritto a piu
// corsi e ogni corso puo avere piu studenti
using namespace std;

int main() {
    studente s1("Luigi","Manno");
    studente s2("pasquale","De Angelis");
    studente s3("Daniele","Banana");                         //creazione studenti passando in input nome e cognome
    studente s4("Samuele","Reynold");
    studente s5("Maria","Rossi");

   corso informaticaI("informatica I",12);
    informaticaI.inserisciStudente(s1);
    informaticaI.inserisciStudente(s2);                  //creazione corso informatica I passando in input nome del corso e cfu
    informaticaI.inserisciStudente(s3);


    corso ASD("Algoritmi e strutture dati",12);

    ASD.inserisciStudente(s1);
    ASD.inserisciStudente(s2);                               //creazione corso Algoritmi e strutture dati passando in input nome del corso e cfu
    ASD.inserisciStudente(s4);

    CorsoDiLaurea Informatica("informatica");
    Informatica.inserisciCorsi(ASD);                            // creazione del corso di laurea informatica passando come input il nome
    Informatica.inserisciCorsi(informaticaI);

    Informatica.getCorso("Algoritmi e strutture dati");
    Informatica.getCorso("informatica I");

    Informatica.getStudentiDalCorso("Algoritmi e strutture dati");
    Informatica.getStudentiDalCorso("informatica I");

    Informatica.EliminaStudente("informatica I","000001");
    Informatica.getStudentiDalCorso("informatica I");

    Informatica.getStudentiDalCorso("Algoritmi e strutture dati");

    return 0;
}
