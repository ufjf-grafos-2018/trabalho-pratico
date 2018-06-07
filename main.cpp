#include <iostream>
#include <fstream>
#include <cstring>
#include "Grafo.h"

#include "IO/ManipuladorArquivo.h"

using namespace std;

int main(int argc, char** argv) {

    if(argc != 3)
    {
        cout<<"Paraetros errados: USO:"<< argv[0]<<" <arquivoEntrada.txt> <arquivoSaida.txt>"<<endl;
        return 1;
    }
    string nomeArquivoEntrada =argv[1];


    ManipuladorArquivo manipula;

    Grafo *grafo = manipula.leitor(nomeArquivoEntrada);

    grafo->print();


   if(grafo->multigrafo())
   {
       cout<<"E";
   }
   cout<<grafo->getGrauNo(6);
   grafo->getGrauNo(5);

   grafo->addNo(6);
   grafo->addAresta(6,1,25);

   manipula.escreve(argv[2],grafo);

    return 0;
}