#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include "TaulaFreq.hpp"
#include "BinaryTree.hpp"
#include "PriorityQueue.hpp"
using namespace std;

typedef BinaryTree<Entrada> BTE;

class Huffman {

// Tipus de màdul: dades
// Descripció del tipus: Taula de codis de símbols obtinguts a partir de la
//                       codificació Huffman. 

private:	

	// COMPLETEU
	BinaryTree<Entrada> bt;
	Queue<BinaryTree<Entrada>> pq;
	TaulaFreq tfreq;
    
public:
    // Constructors
	
	// Pre:  
	// Post: Crea una codificació Huffman buida a partir de la taula de freqüències
	//       tf on només hi ha els símbols i la seva freqüència.(creacio de la PriorityQueue de BT d'entrades)
	//       Tambe es crea una copia de tf al p.i.(tfreq)
    Huffman(TaulaFreq &tf);
	
    // Consultors
	
	// Pre:
	// Post: El resultat és la traducció del text d'entrada a un text
	//       amb la codificació Huffman ((string de 0 i 1)
	string codificar(const string &textE);
    
    // Modificadors	

	// Pre:
	// Post: Calcula la codificació Huffman (els codis de Huffman per cada símbol
	//       segons la freqüència de cadascun d'ells).
	void calculaCodi(BTE &bt, string cod);

	// Pre:
	// Post: Crea l'arbre de simbols bt(p.i.) i frequencies ordenant de mes a menys frequent
	void creaArbre();

	// Pre:
	// Post: Crea l'arbre de simbols bt(p.i.) i frequencies ordenant de mes a menys frequent. 
	//      Calcula la codificació Huffman (els codis de Huffman per cada símbol
	//      segons la freqüència de cadascun d'ells).
    void inserirCodis();
	 
	// Escriptura
	
	// Pre:
	// Post: S'ha mostrat pel canal estàndard de sortida el contingut 
	//       de la TaulaFreq del p.i., amb els símbols, freqüències i 
	//       codis Huffman.
	void mostrarCodis() /*const*/;
};

#endif
