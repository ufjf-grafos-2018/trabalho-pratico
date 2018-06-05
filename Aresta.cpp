//
// Created by maxjf1 on 21/05/18.
//

#include "Aresta.h"

Aresta::Aresta( No *origem, No *destino, int peso) : peso(peso), origem(origem), destino(destino) {}

Aresta::Aresta(No *origem, No *destino) : origem(origem), destino(destino), peso(0) {}

void Aresta::setProx(Aresta *prox) {
    Aresta::prox = prox;
}

int Aresta::getPeso() const {
    return peso;
}

No *Aresta::getOrigem() const {
    return origem;
}

No *Aresta::getDestino() const {
    return destino;
}

Aresta *Aresta::getProx() const {
    return prox;
}
