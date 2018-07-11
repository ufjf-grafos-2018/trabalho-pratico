//
// Created by rodolpho on 08/07/18.
//

#include "Grafo.h"
#include "../Lista/ListaNo.h"
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
    int i = 0;


   /* No *vetNos[this->getOrdem()]; // vetor com a ordem dos nós a serem visitados, ordenados pelo grau

    No *aux = this->getInicioLista();

    while (aux != NULL) {
        vetNos[i] = aux;

        aux = aux->getProx();

        i++;

    }

  //  ListaNo *listaNoOrdenado = this->listaOrdenadaGrau();
       this->ordenaVetor(vetNos);

*/
   ListaNo * listaNoOrdenado = insereNaLista();


    int cores[ordem];
    for (i = 0; i < ordem; i++) {

        cores[i] = -1;
    }


    No *auxNo;

    int pos = 0;

    while (pos < ordem) {


      //  auxNo = vetNos[pos];
        auxNo = listaNoOrdenado->getInicio()->getContent();

        this->validaCor(auxNo, cores, &ultimaCor);
/*
        for (int p = 0; p < ordem; p++) {
            cout << p + 1 << " :" << cores[p] << endl;
        }*/
        pos++;
        listaNoOrdenado->remove(auxNo->getId());
    }

    return ultimaCor + 1;


}

void Grafo::validaCor(No *no, int cores[], int *ultimaCor) {
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
                if (item->getContent()->getGrau() >= no->getGrau() &&
                    (!item->getProx() || no->getGrau() >= item->getProx()->getContent()->getGrau())) {
                    item->insert(no);
                    break;
                }
                item = item->getProx();
            }
            if (!item)
                lista->insertEnd(no);
        }
        no = no->getProx();
    }
    return lista;
}

void Grafo::coloracaoGulosoRand(float alfa) {

    int bestResult = 0;
    int iteracoes = 0;

    while (iteracoes < 1) {

        int ultimaCor = 1;
        int i;
        int ordem = this->tamanho;
        int cores[ordem];
        for (i = 0; i < ordem; i++) {

            cores[i] = -1;
        }

        ListaNo * listaNoOrdenado = insereNaLista();
        No *noAux;

        while (listaNoOrdenado->getSize() > 0) {
            noAux = listaNoOrdenado->getNo(posRand(alfa, listaNoOrdenado));

            this->validaCor(noAux, cores, &ultimaCor);

           /* for (int p = 0; p < ordem; p++) {
                cout << p + 1 << " :" << cores[p] << endl;
            }*/


            listaNoOrdenado->remove(noAux->getId());

        }
        iteracoes++;
        if(iteracoes ==0){
            bestResult = ultimaCor+1;
        }

        if(ultimaCor > bestResult){
            bestResult = ultimaCor+1;
        }

        cout<<"Ultima Cor: "<< ultimaCor<< endl;
    }

    cout<<"o numero de cores usadas foram: "<< bestResult<<endl;


}

int Grafo::posRand(float alfa, ListaNo *listaNo) {


    srand((unsigned) time(NULL));
    int tamanho =listaNo->getSize();



    int max = (int) (alfa * tamanho);
    if (max == 0) return 0;
    int aleatorio = (int) rand() % max;

    cout<<"Aleatorio: "<< aleatorio<<endl;
    return aleatorio;


}

ListaNo* Grafo::insereNaLista() {


    int i = 0;

    No *vet[this->getOrdem()]; // vetor com a ordem dos nós a serem visitados, ordenados pelo grau
    No *aux = this->getInicioLista();

    while (aux != NULL) {
        vet[i] = aux;

        aux = aux->getProx();

        i++;

    }

    //  ListaNo *listaNoOrdenado = this->listaOrdenadaGrau();
    this->ordenaVetor(vet);


    ListaNo * listaNo= new ListaNo();

    for(int i=this->tamanho-1;i>=0;i--){
        listaNo->insert(vet[i]);
    }



    return listaNo;
}

