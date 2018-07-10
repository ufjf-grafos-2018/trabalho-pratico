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

//    grafo->print();


    /*No* vetNos[grafo->getOrdem()]; // vetor com a ordem dos nós a serem visitados, ordenados pelo grau

    No* aux = grafo->getInicioLista();
    int i=0;
    while(aux!=NULL){
        vetNos[i] = aux;

        aux = aux->getProx();

        i++;

    }

    grafo->ordenaVetor(vetNos);

    for(int p =0; p < grafo->getOrdem();p++){
        cout<<"No: "<< vetNos[p]->getId()<< " Grau: " << vetNos[p]->getGrau()<<endl;
    }
*/


    int val = grafo->coloracaoGuloso();
    cout<< "Numero de cores usadas: "<<val;

    cout<<endl<<grafo->posRand(0.3);

    //Interface::iniciaMenu(grafo);

    ManipuladorArquivo::escreve(argv[2], grafo);

    return 0;
}
