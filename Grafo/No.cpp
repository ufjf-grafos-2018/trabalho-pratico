//
// Created by maxjf1 on 21/05/18.
//
#include <stdio.h>
#include "No.h"

No::No(int id) : id(id), proxNo(NULL), arestas(NULL) {}

void No::setProx(No *prox) {
    No::proxNo = prox;
}

int No::getId() const {
    return id;
}

No *No::getProx() const {
    return proxNo;
}

/**
 * Adiciona Aresta ao nó
 * @param destino Nó de destino
 * @param peso
 */
void No::addAresta(No *destino, int peso) {
    Aresta *aresta = new Aresta(this, destino, peso);
    aresta->setProx(arestas);
    arestas = aresta;
    grau++;
}

/**
 * Adiciona Aresta ao nó
 * @param destino Nó de destino
 */
void No::addAresta(No *destino) {
    addAresta(destino, 0);
}

Aresta *No::getArestas() const {
    return arestas;
}

/**
 * Remove aresta do nó
 * @param destino Nó de destino
 */
void No::removeAresta(No *destino) {
    Aresta *aresta = arestas, *anterior = NULL;
    while (aresta) {
        if (aresta->getDestino() == destino) {
            if (anterior == NULL) {
                arestas = aresta->getProx();
            } else {
                anterior->setProx(aresta->getProx());
            }
            delete aresta;
            break;
        }
        anterior = aresta;
        aresta = aresta->getProx();
    }
    grau--;
}

int No::getGrau() const {
    return grau;
}
