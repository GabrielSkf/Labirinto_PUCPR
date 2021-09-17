#include "lab.h"

// ------------------------ Pilha.cpp -----------------------//

Pilha::Pilha() {
	topo_ = -1;
}

void Pilha::push(TipoDado elem) {
	if (!cheia()) {
		++topo_;
		dados[topo_] = elem;
	}
	else
		cerr << "Pilha Cheia!" << endl; // Mensagens de Erro
}

void Pilha::pop() {         // Acima do topo é lixo, não precisa apagar os elementos acima do topo
	if (!vazia())
		--topo_;
	else
		cerr << "Pilha Vazia!" << endl; // Mensagens de Erro
}

TipoDado Pilha::topo() {
	if (!vazia()) // náo vazia?
		return dados[topo_];
	else {
		cerr << "Pilha Vazia!" << endl; // Mensagens de Erro
	}
}

bool Pilha::vazia() {
	return (topo_ == -1); // Simplificacao de If`s
}

bool Pilha::cheia() {
	return (topo_ == MAXPILHA - 1); // Simplificacao de If`s
}

// ------------------------ Pilha.cpp -----------------------//
