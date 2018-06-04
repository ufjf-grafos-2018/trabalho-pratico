//
// Created by rodolpho on 21/05/18.
//

#include "Aresta.h"
#include "Vertice.h"

int Aresta::getPeso() const {
    return peso;
}

void Aresta::setPeso(int peso) {
    Aresta::peso = peso;
}

int Aresta::getNomeVertice() const {
    return nomeVertice;
}

void Aresta::setNomeVertice(int nomeVertice) {
    Aresta::nomeVertice = nomeVertice;
}

Vertice* Aresta::getDestino() const {
    return destino;
}

void Aresta::setDestino(Vertice *destino) {
    Aresta::destino = destino;
}

Vertice *Aresta::getOrigem() const {
    return origem;
}

void Aresta::setOrigem(Vertice *origem) {
    Aresta::origem = origem;
}

Aresta *Aresta::getVizinho() const {
    return vizinho;
}

void Aresta::setVizinho(Aresta *vizinho) {
    Aresta::vizinho = vizinho;
}
