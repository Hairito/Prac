#include "Huffman.hpp"
#include "TaulaFreq.hpp"
#include "BinaryTree.hpp"

using namespace std;

typedef BinaryTree<Entrada> BTE;

// Tipus de màdul: dades
// Descripció del tipus: Taula de codis de símbols obtinguts a partir de la
//                       codificació Huffman. 

// Constructors

// Pre:  
// Post: Crea una codificació Huffman buida a partir de la taula de freqüències
//       tf on només hi ha els símbols i la seva freqüència.(creacio de la PriorityQueue de BT d'entrades)
//       Tambe es crea una copia de tf al p.i.(tfreq)
Huffman::Huffman(TaulaFreq &tf) { // S'ha eliminat el const, pel funcionament de l'operador []
    //Transformacio TF a Queue de BT
    for (int i = 0; i < tf.mida(); i++)
    {
        pq.push(BTE (tf[i], BTE (), BTE ()));
        tfreq.afegirEntrada(tf[i]);
    }
}

// Consultors

// Pre:
// Post: El resultat és la traducció del text d'entrada a un text
//       amb la codificació Huffman ((string de 0 i 1)
string Huffman::codificar(const string &textE) {
    string cod;
    for (int i = 0; i < textE.size(); i++)
    {
        char c = textE[i];
        for (int i = 0; i < tfreq.mida(); i++)
        {
            if (tfreq[i].getSimbol() == c) {
                cod += tfreq[i].getCodificacio();
            }
        }
        
    }
    return cod;
}

// Modificadors

// Pre:
// Post: Crea l'arbre de simbols bt(p.i.) i frequencies ordenant de mes a menys frequent
void Huffman::creaArbre() {
    BTE sum;
    if(pq.size() == 0) {
        return;
    }else if (pq.size() == 1) {
        /*BTE first(pq.front());
        pq.pop();
        Entrada ent('-', first.getRoot().getFrequencia()+1);
        BTE sum(ent, first, BTE ());
        pq.push(sum);*/
        bt = pq.front();
        return;
    }else{
        //cout << "size more:" << pq.size() << endl;
        BTE first(pq.front());
        pq.pop();
        BTE second(pq.front());
        pq.pop();
        Entrada ent('-', second.getRoot().getFrequencia()+1);
        BTE sum(ent, first, second);
        pq.push(sum);
    }
    creaArbre();
    bt = pq.front();
}

// Pre:
// Post: Calcula la codificació Huffman (els codis de Huffman per cada símbol
//       segons la freqüència de cadascun d'ells).
void Huffman::calculaCodi(BTE &bt, string cod){
    if (bt.isEmpty()) {
        return;
    }
    char sym = bt.getRoot().getSimbol();
    if (sym != '-') {  //comprovar empty left and right sym != '-'  bt.getLeft().isEmpty() and bt.getRight().isEmpty()
        for (int i = 0; i < tfreq.mida(); i++)
        {
            if (tfreq.mida() == 1) {
                tfreq[i].setCodificacio("0");
            }else if (tfreq[i].getSimbol() == sym) {
                tfreq[i].setCodificacio(cod);
            }
        }
        return;
    }
    calculaCodi(bt.getLeft(), cod + "0");
    calculaCodi(bt.getRight(), cod + "1");

}


// Pre:
// Post: Crea l'arbre de simbols bt(p.i.) i frequencies ordenant de mes a menys frequent. 
//      Calcula la codificació Huffman (els codis de Huffman per cada símbol
//      segons la freqüència de cadascun d'ells).
void Huffman::inserirCodis() {
    // de Queue Crear arbre i codificar Huffman
    creaArbre();
    //cout << bt << endl;
    calculaCodi(bt, "");
}

// Escriptura

// Pre:
// Post: S'ha mostrat pel canal estàndard de sortida el contingut 
//       de la TaulaFreq del p.i., amb els símbols, freqüències i 
//       codis Huffman.
void Huffman::mostrarCodis() /*const*/ {
    tfreq.mostrarTaula();
}
