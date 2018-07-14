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
       /* for (int p = 0; p < ordem; p++) {
            cout << p + 1 << " :" << cores[p] << endl;

        }*/
        pos++;
        listaNoOrdenado->remove(auxNo->getId());
    }

  /*  int vet[ultimaCor];
    int soma = 0;

    for (int k = 0; k < ultimaCor; ++k) {
        vet[k]= -1;
    }

    for (int j = 0; j < this->tamanho; ++j) {

            vet[cores[j]] = 1;

    }

    for (int l = 0; l <ultimaCor ; ++l) {
        if(vet[l] == 1)
            soma++;
    }*/

    cout<<"Cores Usadas: "<<ultimaCor<<endl;

   // cout<<"Cores: "<<soma<<endl;
    return ultimaCor;


}

void Grafo::validaCor(No *no, int cores[], int *ultimaCor) {
    Aresta *arestaAux;

    int cor = 1;
    int cont = 0;

    if (cores[no->getId() - 1] == -1) {


        while (*ultimaCor >= cont) {
            arestaAux = no->getArestas();
            while (arestaAux != NULL) {

                if (cores[arestaAux->getDestino()->getId() - 1] == cor) {
                    cor++;
                    break;
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

struct Solucao Grafo::coloracaoGulosoRand(double alfa) {

    struct Solucao bestResult;
    bestResult.alpha =alfa;
    int iteracoes = 0;


    while (iteracoes < 1) {

        int ultimaCor = 0;
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


        if(iteracoes ==0){
            bestResult.cores = ultimaCor;
        }

        if(ultimaCor < bestResult.cores){
            bestResult.cores = ultimaCor;
        }

        iteracoes++;


    }

    return bestResult;


}

int Grafo::posRand(float alfa, ListaNo *listaNo) {



    int tamanho =listaNo->getSize();



    int max = (int) (alfa * tamanho);
    if (max == 0) return 0;
    int aleatorio = (int) rand() % max;


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
//Algoritmo Guloso Rand Reativo
struct Solucao Grafo::gulosoRandReativo(int max_itr, int bloco_itr) {

    struct Solucao melhor,aux;
    melhor.cores = 99999;
    int indice;
    double prob[10];
    double alphas[10];
    int valoresEncontrados[10];
    double media[10];
    int nAlfa[10];
    double q[10];
    double alpha = 0.0;
    int embloco =1;
    double somQ = 0.0;


    for (int i=0; i<10; i++){
        prob[i] = 1/10;
        alphas[i] = i*0.05;
        valoresEncontrados[i] = 0;
        media[i] = 0.0;
        nAlfa[i] = 0;
        q[i] = 0.0;
    }

    for(int it = 0 ; it<max_itr; it++){

        if(it<10){
            alpha = alphas[it];
            nAlfa[it]++;
        }
        else{
            indice = random(10, alphas);
            alpha = alphas[indice];
            nAlfa[indice]++;
        }
        aux = coloracaoGulosoRand(alpha);
        valoresEncontrados[indice]+=aux.cores;

        if (aux.cores <= melhor.cores) {
            melhor = aux;
        }

        if(it == bloco_itr*embloco)
        {
            embloco++;
            for(int i = 0; i<10; i++)
            {

                if(nAlfa[i]!= 0)
                {
                    media[i] = (valoresEncontrados[i]*1.0)/nAlfa[i];
                    q[i] = (melhor.cores*1.0)/media[i];
                }
                else
                {
                    media[i] = 0.0;
                    q[i] = 0.0;
                }
            }
            somQ = 0.0;
            for(int i = 0; i<10;i++)
                somQ = q[i] + somQ;
            for(int i = 0; i<10; i++)
            {
                if(somQ!= 0.0)
                    prob[i] = (q[i]*1.0)/somQ;
                else
                    prob[i] = 0.0;
            }
        }
    }

    return melhor;

}

int Grafo::random(int tam, double *prob){
    int soma = 0;
    int nRand = 0;
    for (int i=0; i<tam; i++){
        soma += prob[i]*1000;
    }
    nRand = (soma >0)?rand() % soma:0;
    soma = 0;
    for (int i=0; i<tam; i++){
        soma+=prob[i]*1000;
        if (nRand <= soma){
            return i;
        }
    }
}



// Testando uma nova Heuristica

void Grafo::validacao(No* no, int *cores, int *ultimaCor){


    bool visitado= false;
    if(no->getArestas() == NULL){
        cores[no->getId()-1] = *ultimaCor;
    }else {

        Aresta *auxAresta = no->getArestas();

        while (auxAresta != NULL) {

            if (cores[auxAresta->getDestino()->getId() - 1] == cores[no->getId() - 1]) {
                if(cores[auxAresta->getDestino()->getId() - 1] == -1) {
                    cores[auxAresta->getDestino()->getId() - 1] = *ultimaCor;
                }
                else {
                    *ultimaCor = *ultimaCor + 1;
                    cores[auxAresta->getDestino()->getId() - 1] = *ultimaCor;
                }
            } else if(cores[auxAresta->getDestino()->getId()-1] == -1){
                if(visitado )
                { cores[auxAresta->getDestino()->getId()-1]= *ultimaCor;

                }else {
                    *ultimaCor = *ultimaCor + 1;
                    cores[auxAresta->getDestino()->getId() - 1] = *ultimaCor;
                    visitado = true;
                }
            }
            auxAresta =auxAresta->getProx();
        }

    }


}


