//
// Created by maxjf1 on 21/05/18.
//

#ifndef TRABALHO_GRAFOS_NO_H
#define TRABALHO_GRAFOS_NO_H


#include "Aresta.h"

class Aresta;

class No {
private:
    int id;
    Aresta *arestas;
    No *prox;
public:
    No(int id);

    int getId() const;

    No *getProx() const;

    void setProx(No *prox);

    void addAresta(No *destino, int peso);

    void addAresta(No *destino);

    void removeAresta(No *destino);

    Aresta *getArestas() const;
};


#endif //TRABALHO_GRAFOS_NO_H
