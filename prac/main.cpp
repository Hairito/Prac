#include "Huffman.hpp"

using namespace std;

int main (){
	
	// 1. Lectura del text d'entrada
	string input;
	//cin >> input;
	getline(cin, input);
	// 2. Creació de la taula de freqüències
	TaulaFreq freqtab;
	freqtab.construirTaula(input);
	// 3. Obtenció dels codis de Huffman
	Huffman huff(freqtab);
	// 4. Codificació Huffman d'un missatge de text
	huff.inserirCodis();
	huff.mostrarCodis();
		// 4.1 Mostrar el text d'entrada original
	cout << " Missatge d'entrada (com a string):" << endl;
	cout << input << endl;
		// 4.2 Mostrar el text d'entrada amb la codificació Huffman
	cout << " Missatge codificat (com a string):" << endl;
	string output;
	output = huff.codificar(input);
	cout << output << endl;
	
}