
#ifndef LAB_H
#define LAB_H

#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXPILHA = 100;

struct Pos {
	int x;
	int y;
};

using TipoDado = Pos;

// ------------------------ Pilha.h-----------------------//
class Pilha {
public:
	Pos pos_padrao;
	Pilha(); // construtor
	void push(TipoDado elem);
	void pop();
	TipoDado topo();
	bool vazia();
	bool cheia();
private:
	std::array<TipoDado, MAXPILHA> dados;  // <-- Objeto   Vetor --> //TipoDado dados[MAXPILHA];
	int topo_;
};
// ------------------------ Pilha.h-----------------------//


// Declaração das Funções
int verificaParede(vector<string>& lab, int x, int y, Pilha& posicoes_lab, int altura, int largura);
void imprimeLabirinto(Pilha pos_lab, vector<string>& lab1, int altura);
Pos encontraEntrada(vector<string>& lab1, int altura, int largura);
Pos encontraSaida(vector<string>& lab1, int altura, int largura);

#endif

