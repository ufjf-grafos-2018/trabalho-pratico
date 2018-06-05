//
// Created by maxjf1 on 21/05/18.
//
#include <stdio.h>
#include <iostream>

#include "Grafo.h"

using namespace std;


Grafo::Grafo() : tamanho(0), lista(NULL) {}

Grafo::Grafo(int tamanho) : tamanho(tamanho), lista(NULL) {
    for (int i = 1; i <= tamanho; ++i) {
        addNo(i);
    }
}

void Grafo::addNo(int id) {
    No *no = new No(id);
    if (!vazio()) {
        no->setProx(lista);
    }
    lista = no;
    tamanho++;
}

void Grafo::removeNo(int id) {
    No *no = lista, *anterior;
    if (no != NULL && no->getId() == id) {
        lista = no->getProx();
        delete no;
    } else {
        while (no != NULL && no->getId() != id) {
            anterior = no;
            no = no->getProx();
        }
        if (no != NULL) {
            anterior->setProx(no->getProx());
            delete no;
        }
    }
}

/**
 * Adiciona Aresta
 * @param inicio
 * @param fim
 * @param peso
 */
void Grafo::addAresta(int inicio, int fim, int peso) {
    No *noInicio = NULL, *noFim = NULL, *atual = lista;
    while ((noInicio == NULL || noFim == NULL) && atual != NULL) {
        if (atual->getId() == inicio) {
            noInicio = atual;
        }
        if (atual->getId() == fim) {
            noFim = atual;
        }
        atual = atual->getProx();
    }

    if (noInicio && noFim) {
        noInicio->addAresta(noFim, peso);
        noFim->addAresta(noInicio, peso);
    }

}


void Grafo::removeAresta(int inicio, int fim) {
    No *noInicio = NULL, *noFim = NULL, *atual = lista;
    while ((noInicio == NULL || noFim == NULL) && atual != NULL) {
        if (atual->getId() == inicio) {
            noInicio = atual;
        }
        if (atual->getId() == fim) {
            noFim = atual;
        }
        atual = atual->getProx();
    }

    if (noInicio && noFim) {
        noInicio->removeAresta(noFim);
        noFim->removeAresta(noInicio);
    }
}

bool Grafo::vazio() {
    return lista == NULL;
}

void Grafo::print() {
    No *no = lista;
    Aresta *aresta;

    while (no) {
        aresta = no->getArestas();
        while (aresta) {
            cout << aresta->getOrigem()->getId() << "=>" << aresta->getDestino()->getId() << ": " << aresta->getPeso()
                 << endl;
            aresta = aresta->getProx();
        }
        no = no->getProx();
    }
}



