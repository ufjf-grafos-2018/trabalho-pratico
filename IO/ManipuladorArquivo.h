//
// Created by rodolpho on 07/06/18.
//

#ifndef TRABALHO_GRAFOS_MANIPULADORARQUIVO_H
#define TRABALHO_GRAFOS_MANIPULADORARQUIVO_H


#include "../Grafo/Grafo.h"

using namespace std;

class ManipuladorArquivo {

public:
    static Grafo *leitor(string entrada);

    static void escreve(char *saida, Grafo *grafo);
};


#endif //TRABALHO_GRAFOS_MANIPULADORARQUIVO_H
