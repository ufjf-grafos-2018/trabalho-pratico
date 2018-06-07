//
// Created by maxjf1 on 21/05/18.
//

#ifndef TRABALHO_GRAFOS_GRAFO_H
#define TRABALHO_GRAFOS_GRAFO_H


#include "No.h"

class Grafo {
private:
    int tamanho = 0;
    No *inicioLista = NULL;
    bool digrafo = false;
    void init(int tamanho);
    void removeArestas(No *no);
public:

    No *getInicioLista() const;

    Grafo(int tamanho);

    Grafo(int tamanho, bool digrafo);

    void addNo(int id);

    void removeNo(int id);

    void addAresta(int inicio, int fim, int peso);

    void removeAresta(int inicio, int fim);

    bool vazio();

    int getOrdem();

    int getGrau();

    bool multigrafo();

    int getGrauNo(int id);

    No *getNo(int id);

    int *getSequenciaGraus();

    void printSequenciaGraus();

    void print();

};


#endif //TRABALHO_GRAFOS_GRAFO_H
