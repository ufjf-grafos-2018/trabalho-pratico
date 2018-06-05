//
// Created by maxjf1 on 21/05/18.
//
#include <stdio.h>
#include <iostream>

#include "Grafo.h"

using namespace std;

/**
 * Construtor
 * @param tamanho Tamanho do grafo
 */
Grafo::Grafo(int tamanho) {
    init(tamanho);
}

/**
 * Construtor
 * @param tamanho Tamanho do grafo
 * @param digrafo Se é digrafo
 */
Grafo::Grafo(int tamanho, bool digrafo) : digrafo(digrafo) {
    init(tamanho);
}

/**
 * Inicializa o grafo
 * @param tamanho Quantidade de nós a serem adicionadas
 */
void Grafo::init(int tamanho) {
    for (int i = 1; i <= tamanho; ++i) {
        addNo(i);
    }
}

/**
 * Adiciona um nó ao grafo
 * @param id ID do nó
 */
void Grafo::addNo(int id) {
    No *no = new No(id);
    if (!vazio()) {
        no->setProx(lista);
    }
    lista = no;
    tamanho++;
}

/**
 * Remove um nó do grafo
 * @param id ID do nó
 */
void Grafo::removeNo(int id) {
    No *no = lista, *anterior;
    if (no != NULL && no->getId() == id) {
        lista = no->getProx();
        removeArestas(no);
        delete no;
    } else {
        while (no != NULL && no->getId() != id) {
            anterior = no;
            no = no->getProx();
        }
        if (no != NULL) {
            anterior->setProx(no->getProx());
            removeArestas(no);
            delete no;
        }
    }
}

/**
 * Adiciona Aresta ao grafo
 * @param inicio ID do nó de origem
 * @param fim ID do nó de destino
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

/**
 * Remove Aresta do grafo
 * @param inicio ID do nó de origem
 * @param fim ID do nó de destino
 */
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
        if (!digrafo) {
            noFim->removeAresta(noInicio);
        }
    }
}

/**
 * Se o grafo está vazio
 * @return
 */
bool Grafo::vazio() {
    return lista == NULL;
}

/**
 * Imprime o grafo
 */
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

/**
 * Remove as arestas de um nó
 * @param no
 */
void Grafo::removeArestas(No *no) {
    if (digrafo) {
        /**
         * Digrafo - varrer grafo em busca de incidências
         * TODO: Remoção caso seja digrafo - varredura
         */
    } else {
        /**
         * Não digrafo - remover arestas dos nós conectados apenas
         */
        cout << "Removendo arestas de " << no->getId() << endl;
        Aresta *aresta = no->getArestas();
        while (aresta) {
            aresta->getDestino()->removeAresta(no);
            aresta = aresta->getProx();
        }
    }
}




