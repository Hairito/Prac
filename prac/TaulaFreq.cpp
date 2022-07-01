#include <string>
#include <iostream>

#include "TaulaFreq.hpp"
#include "Entrada.hpp"
#include "PriorityQueue.hpp"

using namespace std;

// Constructors
	
// Pre: 
// Post: Crea una taula de freqüències buida.
TaulaFreq::TaulaFreq() {
}

// Consultors

// Pre:
// Post: El resultat és el nombre d'elements de la taula p.i.
int TaulaFreq::mida() const {
    return ent.size();
}


// Modificadors
// Pre:
// Post: Omple la taula p.i. a partir dels caràcters de text.
void TaulaFreq::construirTaula(string text) {
    //recorre el text afegint els simbols a la taula de frequencies.
    for (int i = 0; i<text.size(); i++) {
        bool found = false;
        char ch = text[i];
            // Recorre el vector de entrades buscant si ja existeix el simbol.
            for (int i = 0; i < ent.size() and not found; i++)
            {
                if (ent[i].getSimbol() == ch) {
                    ent[i].setFrequencia(ent[i].getFrequencia() + 1);
                    found = true;
                }
            }
            if(not found) {
                Entrada aux(ch,1);
                afegirEntrada(aux);
            }
    }
}

// Pre:
// Post: Afegeix l'entrada e al final de la taula p.i.
void TaulaFreq::afegirEntrada(const Entrada &e) {
    ent.push_back(e);
}


// Escriptura

// Pre:
// Post: S'ha mostrat pel canal estàndard de sortida el contingut 
//       de la taula p.i.
void TaulaFreq::mostrarTaula() const {
    cout << " Bolcat taula frequencies ---->" << endl;
    cout << endl;
    cout << " Mida: " << ent.size() << " simbols " << endl;
    for (int i = 0; i < ent.size(); i++)
    {
        cout << "Entrada " << i << ". " << ent[i];
    }
    cout << "----> Fi bolcat taula" << endl;
}

// Pre:
// Post: copia la taula de frequencia del p.i. a una nova taula de frequencia.
void TaulaFreq::copiaTaula(TaulaFreq &tf) {
    for (int i = 0; i < ent.size(); i++)
    {
        tf.afegirEntrada(ent[i]);
    }
}

// Pre: el vector conte al menys un element
// Post: retorna l'Entrada de la posicio i.
Entrada& TaulaFreq::operator[](int i) {
    return ent[i];
}