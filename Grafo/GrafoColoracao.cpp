//
// Created by rodolpho on 08/07/18.
//

#include "Grafo.h"
#include "ListaNo.h"
#include <math.h>
#include <limits>
#include <vector>
#include <time.h>
#include <iostream>

using namespace std;


void Grafo::ordenaVetor(No *vet[]) {

    int i, flag = 1, numLength = this->tamanho;
    int d = numLength;
    No *temp;
    while (flag || (d > 1)) {
        flag = 0;
        d = (d + 1) / 2;
        for (i = 0; i < (numLength - d); i++) {
            if (vet[i + d]->getGrau() > vet[i]->getGrau()) {
                temp = vet[i + d];
                vet[i + d] = vet[i];
                vet[i] = temp;
                flag = 1;
            }
        }

    }

}


int Grafo::coloracaoGuloso() {

    int ordem = this->tamanho;
    int ultimaCor = 1;


    No *vetNos[this->getOrdem()]; // vetor com a ordem dos nós a serem visitados, ordenados pelo grau

    No *aux = this->getInicioLista();
    int i = 0;
    while (aux != NULL) {
        vetNos[i] = aux;

        aux = aux->getProx();

        i++;

    }

    this->ordenaVetor(vetNos);

    int cores[ordem];
    for (i = 0; i < ordem; i++) {

        cores[i] = -1;
    }


    No *auxNo;

    int pos = 0;

    while (pos < ordem) {

        auxNo = vetNos[pos];

        this->validaCor(auxNo, cores, pos, &ultimaCor);

        for (int p = 0; p < ordem; p++) {
            cout << p + 1 << " :" << cores[p] << endl;
        }

        cout << endl;


        pos++;
    }

    return ultimaCor + 1;


}

void Grafo::validaCor(No *no, int cores[], int pos, int *ultimaCor) {
    Aresta *arestaAux;


    int cor = 0;
    int cont = 0;


    if (cores[no->getId() - 1] == -1) {


        while (*ultimaCor >= cont) {
            arestaAux = no->getArestas();
            while (arestaAux != NULL) {

                if (cores[arestaAux->getDestino()->getId() - 1] == cor) {
                    cor++;
                }

                arestaAux = arestaAux->getProx();
            }
            cont++;
        }
        cores[no->getId() - 1] = cor;
        if (*ultimaCor < cor) {
            *ultimaCor = cor;
        }
    }
}

ListaNo *Grafo::listaOrdenadaGrau() {
    ListaNo *lista = new ListaNo;
    No *no = getInicioLista();

    while (no) {
        if (!lista->getInicio() || no->getGrau() >= lista->getInicio()->getContent()->getGrau())
            lista->insert(no);
        else {
            ListaNoItem *item = lista->getInicio();
            while (item) {
                if(item->getContent()->getGrau() >=no->getGrau() && (!item->getProx() || no->getGrau() >= item->getProx()->getContent()->getGrau())){
                    item->insert(no);
                    break;
                }
                item = item->getProx();
            }
            if(!item)
                lista->insertEnd(no);
        }
        no = no->getProx();
    }
    return lista;
}


