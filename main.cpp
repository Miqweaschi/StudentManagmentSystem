#include <iostream>
#include "header.hpp"
// Realizzare un programma che gestisce studenti e corsi universitari. Ogni studente può essere iscritto a piu
// corsi e ogni corso puo avere piu studenti
using namespace std;

int main() {
    studente s1("pino","gay");
    studente s2("pino","gaz");
    studente s3("pinas","caca");
    studente s4("pin","caca");
    studente s5("pines","caca");

   corso informaticaI("informatica I",12);
    informaticaI.inserisciStudente(s1);
    informaticaI.inserisciStudente(s2);
    informaticaI.inserisciStudente(s3);


    corso ASD("Algoritmi e strutture dati",12);

    ASD.inserisciStudente(s1);
    ASD.inserisciStudente(s2);
    ASD.inserisciStudente(s4);

    CorsoDiLaurea Informatica("informatica");
    Informatica.inserisciCorsi(ASD);
    Informatica.inserisciCorsi(informaticaI);

    Informatica.getCorso("Algoritmi e strutture dati");
    Informatica.getCorso("informatica I");

    Informatica.getStudentiDalCorso("Algoritmi e strutture dati");


    return 0;
}
