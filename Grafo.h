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

    Grafo *vizinhanca(int id, bool fechado);
public:

    Grafo() {};

    Grafo(int tamanho);

    Grafo(int tamanho, bool digrafo);

    void addNo(int id);

    void removeNo(int id);

    void addAresta(int inicio, int fim, int peso);

    void removeAresta(int inicio, int fim);

    bool vazio();

    int getOrdem();

    int getGrau();

    int getGrauNo(int id);

    No *getNo(int id);

    int *getSequenciaGraus();

    bool isCompleto();

    int kRegular();

    bool isKRegular(int k);

    bool isKRegular();

    void printSequenciaGraus();

    void print();

    Grafo* vizinhoFechado(int id);

    Grafo* vizinhoAberto(int id);
};


#endif //TRABALHO_GRAFOS_GRAFO_H
