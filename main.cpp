#include <iostream>
#include <fstream>
#include <cstring>
#include "Grafo.h"

#include "IO/ManipuladorArquivo.h"

using namespace std;

int main(int argc, char** argv) {

    if(argc != 3)
    {
        cout<<"Parâmetros errados: "<<endl<<"USO: "<< argv[0]<<" <arquivoEntrada.txt> <arquivoSaida.txt>"<<endl;
        return 1;
    }
    string nomeArquivoEntrada =argv[1];


    ManipuladorArquivo manipula;

    Grafo *grafo = manipula.leitor(nomeArquivoEntrada);

    grafo->print();


   grafo->getGrauNo(5);


   cout<<grafo->ehBipartido();

   manipula.escreve(argv[2],grafo);

    return 0;
}