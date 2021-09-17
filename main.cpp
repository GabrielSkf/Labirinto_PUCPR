#include <iostream>;
#include "lab.h"

using namespace std;

int main() {

	vector<string> labirinto = {
		"XXXXXXXXXXXXXXXXXXXXX",
		"X     X     X     X X",
		"XX XX XXXXX X X X   X",
		"X   X       XXX XXX X",
		"X X X XXXXXXX   X   X",
		"X X   X   X X X   X X",
		"X XXXXX X X   XXXXX X",
		"X X     X XXX  X    X",
		"X X X X X   XX XX XXX",
		"X X XXX X X     X   X",
		"E X X X X XXXXX XXX X",
		"X     X X   X X X   X",
		"X XXXXX XXX X XXX X X",
		"X X       X X   X X X",
		"X   XXX X X XXX X X X",
		"XXX X X X X X X X XXX",
		"X X   X X   X   X   X",
		"X XXX XXXXXXXXX XXX X",
		"X                 X X",
		"XXXXXXXXXXXXXXXXXXXSX"
	};

	// Pilha para armazenar posicoes corretas do labirinto 
	Pilha posicoes_lab;

	// Structs criadas para armazenar as posicoes no formato [x,y]
	Pos pos_atual;
	Pos pos_entrada;
	Pos pos_saida;

	vector<string> labirinto1;

	labirinto1 = labirinto; // Copia do labirinto para manter o original

	int largura = int(labirinto[0].size());	// 21 - Caracteres
	int altura = int(labirinto.size());		// 20 - Strings

	pos_entrada = encontraEntrada(labirinto1, altura, largura);
	pos_saida = encontraSaida(labirinto1, altura, largura);

	verificaParede(labirinto, pos_entrada.x, pos_entrada.y, posicoes_lab, altura, largura); // Funcao recursiva que verifica as posicoes

	cout << "Entrada: " << "[" << pos_entrada.x << "]" << "[" << pos_entrada.y << "]" << endl << endl; // Imprime entrada

	imprimeLabirinto(posicoes_lab, labirinto1, altura); // Imprime labirinto

	cout << "Saida: " << "[" << pos_saida.x << "]" << "[" << pos_saida.y << "]" << endl; // Imprime saida

	return 0;

}

