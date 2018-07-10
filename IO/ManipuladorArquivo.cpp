//
// Created by rodolpho on 07/06/18.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include "ManipuladorArquivo.h"


using namespace std;

/**
 * Gera um grafo a partir da leitura de um arquivo
 * @param entrada caminho relativo ou absoluto do arquivo
 * @return
 */
Grafo *ManipuladorArquivo::leitor(string entrada) {
    Grafo *grafo;
    int grauGrafo, v1, v2, p;

    ifstream file(entrada);
    char *url = new char[entrada.length() + 1];
    FILE *arq;

    strcpy(url, entrada.c_str());
    arq = fopen(url, "r");
    if (arq == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");
    else

        fscanf(arq, "%d", &grauGrafo);
    grafo = new Grafo(grauGrafo, false);

    while ((fscanf(arq, "%d %d\n", &v1, &v2)) != EOF) {

        grafo->addAresta(v1, v2);
    }

    fclose(arq);

    return grafo;
}

void ManipuladorArquivo::escreve(char *saida, Grafo *grafo) {

    FILE *arq;
    int i;
    int result;

    arq = fopen(saida, "wt");

    if (arq == NULL) {
        cout << "Falha ao criar o arquivo" << endl;
        return;
    }
    No *no = grafo->getInicioLista();
    Aresta *aresta;

    while (no) {
        aresta = no->getArestas();
        while (aresta) {

            result = fprintf(arq, "%d %d %d\n", aresta->getOrigem()->getId(), aresta->getDestino()->getId(),
                             aresta->getPeso());
            if (result == EOF) {
                cout << "Erro na gravação" << endl;
            }
            aresta = aresta->getProx();
        }
        no = no->getProx();
    }

    fclose(arq);
}
