//
// Created by maxjf1 on 21/05/18.
//
#include <stdio.h>
#include <iostream>
#include <queue>
#include <list>

#include "Grafo.h"

using namespace std;

/**
 * Construtor
 * @param tamanho Tamanho do grafo
 */
Grafo::Grafo(int tamanho) {
    init(tamanho);
}

/**
 * Construtor
 * @param tamanho Tamanho do grafo
 * @param digrafo Se é digrafo
 */
Grafo::Grafo(int tamanho, bool digrafo) : digrafo(digrafo) {
    init(tamanho);
}

/**
 * Inicializa o grafo
 * @param tamanho Quantidade de nós a serem adicionadas
 */
void Grafo::init(int tamanho) {
    for (int i = 1; i <= tamanho; ++i) {
        addNo(i);
    }
}

/**
 * Adiciona um nó ao grafo
 * @param id ID do nó
 */
void Grafo::addNo(int id) {
    No *no = new No(id);
    if (!vazio()) {
        no->setProx(inicioLista);
    }
    inicioLista = no;
    tamanho++;
}

/**
 * Remove um nó do grafo
 * @param id ID do nó
 */
void Grafo::removeNo(int id) {
    No *no = inicioLista, *anterior;
    if (no != NULL && no->getId() == id) {
        inicioLista = no->getProx();
        removeArestas(no);
        delete no;
    } else {
        while (no != NULL && no->getId() != id) {
            anterior = no;
            no = no->getProx();
        }
        if (no != NULL) {
            anterior->setProx(no->getProx());
            removeArestas(no);
            delete no;
        }
    }
}

/**
 * Adiciona Aresta ao grafo
 * @param inicio ID do nó de origem
 * @param fim ID do nó de destino
 * @param peso
 */
void Grafo::addAresta(int inicio, int fim, int peso) {
    No *noInicio = NULL, *noFim = NULL, *atual = inicioLista;
    while ((noInicio == NULL || noFim == NULL) && atual != NULL) {
        if (atual->getId() == inicio) {
            noInicio = atual;
        }
        if (atual->getId() == fim) {
            noFim = atual;
        }
        atual = atual->getProx();
    }

    if (noInicio && noFim) {
        noInicio->addAresta(noFim, peso);
        if(!digrafo){
            noFim->addAresta(noInicio, peso);
        }
    }

}

/**
 * Remove Aresta do grafo
 * @param inicio ID do nó de origem
 * @param fim ID do nó de destino
 */
void Grafo::removeAresta(int inicio, int fim) {
    No *noInicio = NULL, *noFim = NULL, *atual = inicioLista;
    while ((noInicio == NULL || noFim == NULL) && atual != NULL) {
        if (atual->getId() == inicio) {
            noInicio = atual;
        }
        if (atual->getId() == fim) {
            noFim = atual;
        }
        atual = atual->getProx();
    }

    if (noInicio && noFim) {
        noInicio->removeAresta(noFim);
        if (!digrafo) {
            noFim->removeAresta(noInicio);
        }
    }
}

/**
 * Se o grafo está vazio
 * @return
 */
bool Grafo::vazio() {
    return inicioLista == NULL;
}

/**
 * Imprime o grafo
 */
void Grafo::print() {
    No *no = inicioLista;
    Aresta *aresta;

    while (no) {
        aresta = no->getArestas();
        while (aresta) {
            cout << aresta->getOrigem()->getId() << "=>" << aresta->getDestino()->getId() << ": " << aresta->getPeso()
                 << endl;
            aresta = aresta->getProx();
        }
        no = no->getProx();
    }

    cout << "Ordem: " << getOrdem() << endl;
    cout << "Grau: " << getGrau() << endl;
}

/**
 * Remove as arestas de um nó
 * @param no
 */
void Grafo::removeArestas(No *no) {
    if (digrafo) {
        /**
         * Digrafo - varrer grafo em busca de incidências
         * TODO: Remoção caso seja digrafo - varredura
         */
    } else {
        /**
         * Não digrafo - remover arestas dos nós conectados apenas
         */
        cout << "Removendo arestas de " << no->getId() << endl;
        Aresta *aresta = no->getArestas();
        while (aresta) {
            aresta->getDestino()->removeAresta(no);
            aresta = aresta->getProx();
        }
    }
}

/**
 * Retorna a ordem do grafo
 * @return
 */
int Grafo::getOrdem() {
    return tamanho;
}

/**
 * Retorna o grau do grafo
 * @return
 */
int Grafo::getGrau() {
    int grau = 0, grauAtual;
    No *no = inicioLista;
    while(no){
        if(no->getGrau() > grau)
            grau = no->getGrau();
        no = no->getProx();
    }
    return grau;
}

int Grafo::getGrauNo(int id) {
    if (getNo(id)){

        No *no = getNo(id);
        return no->getGrau();
    }
    else
        cout<<"Nó não existe no grafo"<<endl;

    return 0;
}

No *Grafo::getNo(int id) {
    No *no = inicioLista;
    while(no){
        if(no->getId() == id)
            return no;
        no= no->getProx();
    }
    return nullptr;
}

int *Grafo::getSequenciaGraus() {
    int* graus = new int[tamanho];
    int i = 0;
    No * no = inicioLista;
    while(no){
        graus[i]= no->getGrau();
        cout << graus[i] << endl;
        i++;
        no = no->getProx();
    }
    return graus;
}

void Grafo::printSequenciaGraus() {
    int *graus = getSequenciaGraus();

    cout << "[";
    for(int i = 0; i < tamanho; i++){
        cout << graus[i] << (i+1 == tamanho ? "" : ",");
    }
    cout << "]" << endl;

}

bool Grafo::multigrafo() {

    No *auxNo = this->inicioLista;
    Aresta *auxAresta;
    Aresta *aux;
    int id;

    while(auxNo->getProx() != NULL)
    {
        auxAresta= auxNo->getArestas();

        while(auxAresta !=NULL){
            aux=auxAresta->getProx();
            id = auxAresta->getDestino()->getId();
            while(aux !=NULL){
                if(id == aux->getDestino()->getId()) {
                    cout<<"ID: "<< id<<"AUX: "<< aux->getDestino()->getId()<<endl;
                    return false;
                }

                aux = aux->getProx();

            }
            auxAresta= auxAresta->getProx();
        }

        auxNo = auxNo->getProx();
    }

    return true;


}

No *Grafo::getInicioLista() const {
    return inicioLista;
}


bool Grafo::ehBipartido() {

        No *noAux = getInicioLista();
        Aresta *arestaAux = noAux->getArestas();
        int  V = this->tamanho;
        int result[V];


        result[0]  = 0;


        for (int u = 1; u < V; u++)
            result[u] = -1;


        bool available[V];
        for (int cr = 1; cr < V; cr++)
            available[cr] = false;


        while(noAux !=NULL)
        {

                arestaAux = noAux->getArestas();
                while(arestaAux!=NULL)
             {
                if (result[arestaAux->getDestino()->getId()-1] != -1) {
                    available[result[arestaAux->getDestino()->getId()]] = true;

                }

                arestaAux = arestaAux->getProx();
            }

            int cr;
            for (cr = 0; cr < V; cr++)
                if (available[cr] == false)
                    break;

            result[noAux->getId()] = cr;


            arestaAux = noAux->getArestas();
            while(arestaAux!=NULL){
                if (result[arestaAux->getDestino()->getId()-1] != -1)
                    available[arestaAux->getDestino()->getId()-1] = false;

                arestaAux = arestaAux->getProx();
            }

            noAux = noAux->getProx();
        }


        for (int u = V; u > 0; u--){


            cout << "Vertice " << u << " --->  Cor " << result[u] << endl;
        }


        for (int u = V; u > 0;u--){
            if (result[u]>1)
                return false;

        }
    return true;
}