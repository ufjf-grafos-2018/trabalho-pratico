#include <iostream>
#include <fstream>
#include <cstring>
#include "Grafo/Grafo.h"
#include "Interface.h"

using namespace std;

Grafo *grafo;
string nomeArquivoEntrada = "../Arquivos/entrada.txt";
int main() {
    grafo = Interface::getGrafoByFile(nomeArquivoEntrada);

    Interface::iniciaMenu(grafo);

    return 0;
}
