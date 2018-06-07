//
// Created by rodolpho on 07/06/18.
//

#ifndef TRABALHO_GRAFOS_MANIPULADORARQUIVO_H
#define TRABALHO_GRAFOS_MANIPULADORARQUIVO_H

#include "../Grafo.h"

using namespace std;
class ManipuladorArquivo {

public:
    Grafo* leitor(string entrada);
    void escreve(char *saida, Grafo *grafo);
};


#endif //TRABALHO_GRAFOS_MANIPULADORARQUIVO_H
