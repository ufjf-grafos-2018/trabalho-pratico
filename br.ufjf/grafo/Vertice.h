//
// Created by rodolpho on 21/05/18.
//
#pragma once

#ifndef TRABALHO_GRAFOS_VERTICE_H
#define TRABALHO_GRAFOS_VERTICE_H


#include "Aresta.h"
class Aresta;

class Vertice {

private:
    int nome;
    int peso;
    int grau;
    Vertice* proximo;
    Aresta* neighbor;

public:

    int getNome() const;

    void setNome(int nome);

    int getPeso() const;

    void setPeso(int peso);

    int getGrau() const;

    void setGrau(int grau);

    Vertice* getProximo() const;

    void setProximo(Vertice* proximo);

    Aresta* getNeighbor() const;

    void setNeighbor(Aresta *neighbor);


};


#endif //TRABALHO_GRAFOS_VERTICE_H
