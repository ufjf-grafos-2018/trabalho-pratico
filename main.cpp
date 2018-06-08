#include <iostream>
#include <fstream>
#include <cstring>
#include "Grafo/Grafo.h"
#include "IO/Interface.h"

#include "IO/ManipuladorArquivo.h"

using namespace std;

string nomeArquivoEntrada;
Grafo *grafo;

int main(int argc, char **argv) {

    if (argc != 3) {
        cout << "Parâmetros errados: " << endl << "USO: " << argv[0] << " <arquivoEntrada.txt> <arquivoSaida.txt>"
             << endl;
        return 1;
    }

    nomeArquivoEntrada = argv[1];

    grafo = ManipuladorArquivo::leitor(nomeArquivoEntrada);

    grafo->print();

    Interface::iniciaMenu(grafo);

    ManipuladorArquivo::escreve(argv[2], grafo);

    return 0;
}
