//
// Created by maxjf1 on 08/06/18.
//
#include <string>
#include "../Grafo/Grafo.h"

#ifndef TRABALHO_GRAFOS_INTERFACE_H
#define TRABALHO_GRAFOS_INTERFACE_H

using namespace std;

class Interface {
    static void imprimeMenu();
    static void pauseMenu();
    static void limpaTela();

public:
     static void iniciaMenu(Grafo *grafo);
};


#endif //TRABALHO_GRAFOS_INTERFACE_H
