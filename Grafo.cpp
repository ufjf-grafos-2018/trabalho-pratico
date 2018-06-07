//
// Created by maxjf1 on 21/05/18.
//
#include <stdio.h>
#include <iostream>

#include "Grafo.h"

using namespace std;


Grafo::Grafo() {}

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
        no->setProx(inicioLista);
    }
    inicioLista = no;
    tamanho++;
}

/**
 * Remove um nó do grafo
 * @param id ID do nó
 */
void Grafo::removeNo(int id) {
    No *no = inicioLista, *anterior;
    if (no != NULL && no->getId() == id) {
        inicioLista = no->getProx();
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
    No *noInicio = NULL, *noFim = NULL, *atual = inicioLista;
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
        if (!digrafo) {
            noFim->addAresta(noInicio, peso);
        }
    }

}

/**
 * Remove Aresta do grafo
 * @param inicio ID do nó de origem
 * @param fim ID do nó de destino
 */
void Grafo::removeAresta(int inicio, int fim) {
    No *noInicio = NULL, *noFim = NULL, *atual = inicioLista;
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
    return inicioLista == NULL;
}

/**
 * Imprime o grafo
 */
void Grafo::print() {
    No *no = inicioLista;
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

    cout << "Ordem: " << getOrdem() << endl;
    cout << "Grau: " << getGrau() << endl;
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

/**
 * Retorna a ordem do grafo
 * @return
 */
int Grafo::getOrdem() {
    return tamanho;
}

/**
 * Retorna o grau do grafo
 * @return
 */
int Grafo::getGrau() {
    int grau = 0, grauAtual;
    No *no = inicioLista;
    while (no) {
        if (no->getGrau() > grau)
            grau = no->getGrau();
        no = no->getProx();
    }
    return grau;
}

int Grafo::getGrauNo(int id) {
    No *no = getNo(id);
    if (no) return no->getGrau();
    return 0;
}

No *Grafo::getNo(int id) {
    No *no = inicioLista;
    while (no) {
        if (no->getId() == id)
            return no;
    }
    return nullptr;
}

int *Grafo::getSequenciaGraus() {
    int *graus = new int[tamanho];
    int i = 0;
    No *no = inicioLista;
    while (no) {
        graus[i] = no->getGrau();
        cout << graus[i] << endl;
        i++;
        no = no->getProx();
    }
    return graus;
}

void Grafo::printSequenciaGraus() {
    int *graus = getSequenciaGraus();

    cout << "[";
    for (int i = 0; i < tamanho; i++) {
        cout << graus[i] << (i + 1 == tamanho ? "" : ",");
    }
    cout << "]" << endl;

}

int Grafo::kRegular() {
    int *graus = getSequenciaGraus();
    int k = graus[0];
    for (int i = 1; i < tamanho; ++i) {
        if (k != graus[i]) {
            //cout << "Não É K-regular" <<  endl;
            return -1;
        }
    }
    //cout << "É " << k << "-regular." << endl;
    return k;
}

bool Grafo::isKRegular(int k) {
    return kRegular() == k;
}

bool Grafo::isKRegular() {
    return kRegular() >= 0;
}

bool Grafo::isCompleto() {
    int *graus = getSequenciaGraus();
    for (int i = 0; i < tamanho; ++i) {
        if (graus[i] != tamanho - 1) {
//            cout << "O grafo não é completo." << endl;
            return false;
        }
    }
//    cout << "O grafo é completo." << endl;
    return true;

}

void Grafo::vizinhoAberto(int id, bool fechado) {
    No *noBuscado = getNo(id);

    if (!noBuscado){
        cout << "No " << id << "nao encontrado!";
        return;
    }

    int i = 0, tamanhoVizinhos = noBuscado->getGrau();

    if (fechado)
        tamanhoVizinhos++;

    No **vizinhos = new No *[tamanhoVizinhos], *noAux;
    Grafo *vizinhanca = new Grafo();
    Aresta *arestaAux = noBuscado->getArestas();

    if (fechado) {
        vizinhanca->addNo(noBuscado->getId());
        vizinhos[0] = noBuscado;
        i = 1;
    }

    while (arestaAux) {
        vizinhanca->addNo(arestaAux->getDestino()->getId());
        vizinhos[i] = arestaAux->getDestino();
        arestaAux = arestaAux->getProx();
        i++;
    }

    for (i = 0; i < tamanhoVizinhos; i++) {
        noAux = vizinhos[i];
        arestaAux = noAux->getArestas();
        while (arestaAux) {

            for (int j = 0; j < tamanhoVizinhos; j++) {
                if (vizinhos[j] && arestaAux->getDestino() == vizinhos[j]) {
                    vizinhanca->addAresta(arestaAux->getOrigem()->getId(), arestaAux->getDestino()->getId(),
                                          arestaAux->getPeso());
                }
            }
            arestaAux = arestaAux->getProx();
        }
        vizinhos[i] = NULL;
    }
    vizinhanca->print();
}