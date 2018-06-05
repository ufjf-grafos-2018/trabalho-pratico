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
    Aresta *prox;
public:
    Aresta(No *origem, No *destino, int peso);

    void setProx(Aresta *prox);

    Aresta(No *origem, No *destino);

    int getPeso() const;

    No *getOrigem() const;

    No *getDestino() const;

    Aresta *getProx() const;
};


#endif //TRABALHO_GRAFOS_VERTICE_H
