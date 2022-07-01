#include <string>
#include <iostream>

#include "Entrada.hpp"

using namespace std;

// Constructors
// Pre: 
// Post: Crea una entrada buida.
Entrada::Entrada() {
}

// Pre:  f > 0
// Post: Crea una entrada de símbol c i freqüència f sense codi Huffman.
Entrada::Entrada(char c, int f) {
    this->c = c;
    this->f = f;
}

// Pre: 
// Post: Crea una entrada amb els valors de l'entrada e.
Entrada::Entrada(const Entrada &e) {
    c = e.c;
    f = e.f;
    code = e.code;
}

// Pre: 
// Post: El resultat és una entrada amb els valors de l'entrada e.
Entrada& Entrada::operator=(const Entrada &e) {
    c = e.c;
    f = e.f;
    code = e.code;
    return *this;
}


// Destructor 

// Post: Esborra automàticament els objectes locals en sortir d'un
//       àmbit de visibilitat.
Entrada::~Entrada() {
}

   
// Modificadors


// Pre:  f > 0 
// Post: La freqüència de l'entrada p.i. passa a ser f.
void Entrada::setFrequencia(int f) {
    this->f = f;
}

// Pre: 
// Post: El codi Huffman de l'entrada p.i. passa a ser co.
void Entrada::setCodificacio(string co) {
    code = co;
}

   
// Consultors

// Pre:
// Post: El resultat és el símbol de l'entrada p.i.
char Entrada::getSimbol() const {
    return c;
}

// Pre:
// Post: El resultat és la freqüència de l'entrada p.i.
double Entrada::getFrequencia() const {
    return f;
}

// Pre:
// Post: El resultat és el codi Huffman de l'entrada p.i.
string Entrada::getCodificacio() const {
    return code;
}

// Pre: 
// Post: El resultat indica si la freqüència de l'entrada p.i. 
//       és estrictament menor que la freqüència de l'entrada e.
bool Entrada::operator<(const Entrada &e) const {
    return f < e.f;
}

// NEW COMPARISON FUNCTIONS

// Pre: 
// Post: El resultat indica si la freqüència de l'entrada p.i. 
//       és menor o igual que la freqüència de l'entrada e.
bool Entrada::operator<=(const Entrada &e) const {
    return f <= e.f;
}

// Pre: 
// Post: El resultat indica si la freqüència de l'entrada p.i. 
//       és estrictament major que la freqüència de l'entrada e.
bool Entrada::operator>(const Entrada &e) const {
    return f > e.f;
}

// Escriptura

// Pre: 
// Post: S'han escrit els atributs de l'entrada e al canal 
//       estàndard de sortida.
ostream& operator<<(ostream &os, const Entrada &e) {
    os << "Simbol:" << e.c << ", Frequencia: " << e.f << ", Codificacio: " << e.code << endl;
    return os;
}

