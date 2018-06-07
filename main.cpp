#include <iostream>
#include <fstream>
#include <cstring>
#include "Grafo.h"

using namespace std;

int main() {
    int grauGrafo, v1, v2, p;
    string nomeArquivoEntrada ="/home/maxjf1/projetos/trabalho-pratico/entrada.txt";

    ifstream file(nomeArquivoEntrada);
    char *url = new char[nomeArquivoEntrada.length() + 1];
    strcpy(url, nomeArquivoEntrada.c_str());

    FILE *arq;

    arq = fopen(url, "r");
    if (arq == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");
    else

        fscanf(arq, "%d", &grauGrafo);
    Grafo *grafo = new Grafo(grauGrafo);

    while ((fscanf(arq, "%d %d %d\n", &v1, &v2, &p)) != EOF) {

        grafo->addAresta(v1, v2, p);
    }

    fclose(arq);
    grafo->print();

    ///xurumelos
//    Grafo *grafo = new Grafo(5);
//
//    grafo->addAresta(1, 3, 20);
//    grafo->addAresta(2, 5, 40);
//    grafo->addAresta(3, 4, 60);
//    grafo->addAresta(1, 5, 70);
//    grafo->removeNo(3);
//    grafo->removeAresta(5, 1);
//    grafo->print();g
    grafo->getGrau();

    grafo->printSequenciaGraus();

    grafo->isCompleto();

    grafo->kRegular(5);

    grafo->vizinhoAberto(5);

    grafo->vizinhoFechado(5);

    return 0;
}