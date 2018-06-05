//
// Created by maxjf1 on 21/05/18.
//

#ifndef TRABALHO_GRAFOS_GRAFO_H
#define TRABALHO_GRAFOS_GRAFO_H


#include "No.h"

class Grafo {
private:
    int tamanho;
    No *lista;
public:
    Grafo();

    Grafo(int tamanho);

    void addNo(int id);

    void removeNo(int id);

    void addAresta(int inicio, int fim, int peso);

    void removeAresta(int inicio, int fim);

    bool vazio();

    void print();

};


#endif //TRABALHO_GRAFOS_GRAFO_H
