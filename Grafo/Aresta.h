//
// Created by maxjf1 on 21/05/18.
//

#ifndef TRABALHO_GRAFOS_VERTICE_H
#define TRABALHO_GRAFOS_VERTICE_H


#include "No.h"
class No;

class Aresta {
private:
    int peso;
    No *origem;
    No *destino;
    Aresta *proxAresta;
public:
    Aresta(No *origem, No *destino, int peso);

    Aresta(No *origem, No *destino);

    Aresta();

    void setProx(Aresta *prox);

    int getPeso() const;

    No *getOrigem() const;

    No *getDestino() const;

    Aresta *getProx() const;
};


#endif //TRABALHO_GRAFOS_VERTICE_H
