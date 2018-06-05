#include <iostream>
#include "Grafo.h"

int main() {
    Grafo *grafo = new Grafo(5);
    grafo->addAresta(1,3, 20);
    grafo->addAresta(2,5, 40);
    grafo->addAresta(3,4, 60);
    grafo->addAresta(1,5, 70);
    grafo->print();

    return 0;
}