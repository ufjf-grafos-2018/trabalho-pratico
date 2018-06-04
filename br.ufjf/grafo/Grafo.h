//
// Created by rodolpho on 18/05/18.
//

#ifndef TRABALHO_GRAFOS_GRAFO_H
#define TRABALHO_GRAFOS_GRAFO_H

#include "Vertice.h"

class Grafo {

private:
    Vertice* inicio;
    int tamanho;

public:
    Grafo( int tamanho);
    void addVertice(int vertice1, int vertice2, int peso);

    Vertice *getInicio() const;

    void setInicio(Vertice *inicio);

    int getTamanho() const;

    void setTamanho(int tamanho);

};


#endif //TRABALHO_GRAFOS_GRAFO_H
