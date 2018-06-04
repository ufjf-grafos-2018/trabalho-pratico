//
// Created by rodolpho on 21/05/18.
//

#include "Vertice.h"

int Vertice::getNome() const {
    return nome;
}

void Vertice::setNome(int nome) {
    Vertice::nome = nome;
}

int Vertice::getPeso() const {
    return peso;
}

void Vertice::setPeso(int peso) {
    Vertice::peso = peso;
}

int Vertice::getGrau() const {
    return grau;
}

void Vertice::setGrau(int grau) {
    Vertice::grau = grau;
}

Vertice *Vertice::getProximo() const {
    return proximo;
}

void Vertice::setProximo(Vertice *proximo) {
    Vertice::proximo = proximo;
}

Aresta *Vertice::getNeighbor() const {
    return neighbor;
}

void Vertice::setNeighbor(Aresta *neighbor) {
    Vertice::neighbor = neighbor;
}
