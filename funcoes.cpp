
#include "lab.h"

using namespace std;

// ------------------------ Funcoes.cpp --------------------- //

int verificaParede(vector<string>& lab, int x, int y, Pilha& posicoes_lab, int altura, int largura) {

	Pos pos_atual_;
	pos_atual_.x = x;
	pos_atual_.y = y;

	char aqui = lab[pos_atual_.x][pos_atual_.y]; // Define aqui com lab[x][y]

	if (aqui == 'S') {
		posicoes_lab.push(pos_atual_);
		return 1;
	}

	if (aqui == 'X' || aqui == '#') {
		return 0;
	}

	lab[x][y] = '#';

	if (x < 0 || x >= largura || y < 0 || y >= altura) { // Verifica as extremidades do labirinto
		return 0;
	}

	if (verificaParede(lab, x + 1, y, posicoes_lab, altura, largura)) { // Verifica pra direita
		posicoes_lab.push(pos_atual_);
		return 1;
	}

	if (verificaParede(lab, x - 1, y, posicoes_lab, altura, largura)) { // Verifica pra esquerda
		posicoes_lab.push(pos_atual_);
		return 1;
	}

	if (verificaParede(lab, x, y + 1, posicoes_lab, altura, largura)) { // Verifica pra cima
		posicoes_lab.push(pos_atual_);
		return 1;
	}

	if (verificaParede(lab, x, y - 1, posicoes_lab, altura, largura)) { // Verifica pra baixo
		posicoes_lab.push(pos_atual_);
		return 1;
	}

	if (posicoes_lab.vazia()) {
		return 0;
	}
	else {
		posicoes_lab.pop();
	}

}

void imprimeLabirinto(Pilha pos_lab, vector<string>& lab1, int altura) {
	while (!pos_lab.vazia()) {												// Substitui os valores da pilha com *
		lab1[pos_lab.topo().x][pos_lab.topo().y] = '*';
		pos_lab.pop();
	}

	for (int i = 0; i < altura; ++i) {
		cout << lab1.at(i) << endl;
	}
	cout << endl;
}

Pos encontraEntrada(vector<string>& lab1, int altura, int largura) {

	Pos p_entrada;

	for (int i = 0; i < altura; i++) {
		for (int j = 0; j < largura; j++) {
			if (lab1[i][j] == 'E') {
				p_entrada.x = i;
				p_entrada.y = j;
			}
		}
	}
	return p_entrada;
}

Pos encontraSaida(vector<string>& lab1, int altura, int largura) {

	Pos p_saida;

	for (int i = 0; i < altura; i++) {
		for (int j = 0; j < largura; j++) {
			if (lab1[i][j] == 'S') {
				p_saida.x = i;
				p_saida.y = j;
			}
		}
	}
	return p_saida;
}

// ------------------------ Funcoes.cpp --------------------- //
