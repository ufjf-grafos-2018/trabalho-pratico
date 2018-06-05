//
// Created by maxjf1 on 21/05/18.
//
#include <stdio.h>
#include "No.h"

No::No(int id) : id(id), prox(NULL), arestas(NULL) {}

void No::setProx(No *prox) {
    No::prox = prox;
}

int No::getId() const {
    return id;
}

No *No::getProx() const {
    return prox;
}

void No::addAresta(No *destino, int peso) {
    Aresta *aresta = new Aresta(this, destino, peso);
    aresta->setProx(arestas);
    arestas = aresta;
}

void No::addAresta(No *destino) {
    addAresta(destino, 0);
}

Aresta *No::getArestas() const {
    return arestas;
}

/**
 * TODO
 * @param destino
 */
void No::removeAresta(No *destino) {

}
