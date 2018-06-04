//
// Created by rodolpho on 21/05/18.
//
#pragma once

#ifndef TRABALHO_GRAFOS_ARESTA_H
#define TRABALHO_GRAFOS_ARESTA_H



#include "Vertice.h"
class Vertice;

class Aresta {

private:
    int peso;
    int nomeVertice;
    Vertice *destino;
    Vertice *origem;
    Aresta *vizinho;

public:

    int getPeso() const;

    void setPeso(int peso);

    int getNomeVertice() const;

    void setNomeVertice(int nomeVertice);

    Vertice *getDestino() const;

    void setDestino(Vertice *destino);

    Vertice *getOrigem() const;

    void setOrigem(Vertice *origem);

    Aresta *getVizinho() const;

    void setVizinho(Aresta *vizinho);

};


#endif //TRABALHO_GRAFOS_ARESTA_H
